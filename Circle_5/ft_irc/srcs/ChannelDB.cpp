#include "Channel.hpp"
#include "Database.hpp"
#include "Event.hpp"
#include "UserInfo.hpp"
#include "DefineColor.hpp"
#include <sys/_types/_size_t.h>
#include <iostream>
#include <sstream>

std::vector<Channel> &Database::get_ch()
{
	return _ch_vector;
}

bool Database::check_valid_ch(std::string &ch_name)
{
	std::vector<Channel>::iterator i;

	for (i = _ch_vector.begin(); i != _ch_vector.end(); ++i)
	{
		if (i->get_ch_name() == ch_name)
		{
			return true;
		}
	}
	return false;
}

bool Database::check_valid_user(UserInfo &leaver)
{
	std::vector<Channel>::iterator i = _ch_vector.begin();

	for (; i != _ch_vector.end(); ++i)
	{
		if (i->check_ch_user(leaver))
		{
			return true;
		}
	}
	return false;
}

Channel &Database::create_ch(UserInfo &joiner, std::string &ch_name)
{
	Channel tmp;

	tmp.set_ch_name(ch_name);
	tmp.append_joiner(joiner);
	tmp.set_host_address(joiner);
	_ch_vector.push_back(tmp);
	return _ch_vector.back();
}

void Database::delete_ch(std::string &ch_name)
{
	Channel tmp;

	tmp.set_ch_name(ch_name);

	std::vector<Channel>::iterator i = std::find(_ch_vector.begin(),
																								_ch_vector.end(), tmp);
	std::size_t size = std::distance(this->_ch_vector.begin(), i);
	this->_ch_vector.erase(this->_ch_vector.begin() + size);
}

Channel &Database::select_ch(std::string &ch_name)
{
	std::vector<Channel>::iterator i = _ch_vector.begin();

	for (; i != _ch_vector.end(); ++i)
	{
		if (i->get_ch_name() == ch_name)
		{
			return *i;
		}
	}
	return *i;
}

Channel &Database::select_ch(const std::string &ch_name)
{
	std::vector<Channel>::iterator i = _ch_vector.begin();

	for (; i != _ch_vector.end(); ++i)
	{
		if (i->get_ch_name() == ch_name)
		{
			return *i;
		}
	}
	return *i;
}

Channel &Database::select_ch(UserInfo &connector)
{
	std::vector<Channel>::iterator i = _ch_vector.begin();

	for (; i != _ch_vector.end(); ++i)
	{
		if (i->check_ch_user(connector))
		{
			return *i;
		}
	}
	return *i;
}

events Database::join_ch(UserInfo &joiner, const std::string &tmp_chan_name, const std::string &tmp_password)
{
	events result;
	event tmp;
	std::string ch_name(tmp_chan_name);
	Channel &current_ch = select_ch(tmp_chan_name);

	if (check_valid_user(joiner))
	{
		event tmp2;
		tmp = Message::msg_join(joiner, joiner, ch_name);
		tmp2 = Message::msg_part(joiner, joiner, ch_name, "invalid : No Double join");
		tmp.second += tmp2.second;
		result.insert(tmp);
		return result;
	}
	if (check_valid_ch(ch_name) == false)
	{
		Channel &channel = create_ch(joiner, ch_name);
		tmp = Message::msg_join(joiner, joiner, ch_name);
		result.insert(tmp);
		events_iter i = result.find(joiner._user_sock);
		i->second += Message::msg_join_353(joiner, channel.get_ch_name(), "@" + joiner._user_nick);
		i->second += Message::msg_join_366(joiner, channel.get_ch_name());
	}
	else if ((current_ch._ch_flag & F_INVITE_ONLY) && !current_ch.check_invitation(joiner._user_sock))
	{
		tmp = Message::msg_join_no_invitation_error_473(joiner, ch_name);
		result.insert(tmp);
	}
	else if (!(current_ch._ch_flag & F_INVITE_ONLY) && (current_ch._ch_flag & F_KEY_NEEDED) && !current_ch.check_ch_key(current_ch, tmp_password))
	{
		tmp = Message::msg_join_key_error_475(joiner, ch_name);
		result.insert(tmp);
	}
	else if (!(current_ch._ch_flag & F_INVITE_ONLY) && (current_ch._ch_flag & F_LIMITED_MEMBERSHIP) && static_cast<int>(current_ch.get_user_info().size()) >= current_ch.get_limit_num())
	{
		tmp = Message::msg_join_full_limit_error_471(joiner, ch_name);
		result.insert(tmp);
	}
	else
	{
		current_ch.append_joiner(joiner);
		const std::string &ch_user_result(current_ch.get_user_result());
		result = current_ch.send_msg_packet(joiner, joiner, "Join \"" + ch_name + "\" channel, " + joiner._user_nick, JOIN);
		events_iter i = result.find(joiner._user_sock);
		i->second += Message::msg_join_353(joiner, current_ch.get_ch_name(), ch_user_result);
		i->second += Message::msg_join_366(joiner, current_ch.get_ch_name());
	}
	return result;
}

events Database::quit_ch(UserInfo &leaver, std::string &ch_name, const std::string &msg_)
{
	event tmp;
	events result;
	std::string msg(msg_);

	if (check_valid_ch(ch_name) == false)
	{
		tmp = Message::msg_no_ch_error_403(leaver, ch_name);
		result.insert(tmp);
		return result;
	}
	Channel &channel = select_ch(ch_name);
	if (channel.check_ch_user(leaver) == 0)
	{
		tmp = Message::msg_no_user_error_401(leaver, leaver._user_nick);
		return result;
	}
	std::vector<UserInfo> &users = channel.get_user_info();
	const int user_size = users.size();
	result = channel.send_msg_packet(leaver, leaver, msg, QUIT);
	channel.banish_user(leaver);

	if (user_size == 1)
		delete_ch(ch_name);
	return result;
}

events Database::part_ch(UserInfo &leaver, std::string &ch_name, const std::string &msg_)
{
	event tmp;
	events result;
	std::string msg(msg_);

	if (check_valid_ch(ch_name) == false)
	{
		tmp = Message::msg_no_ch_error_403(leaver, ch_name);
		result.insert(tmp);
		return result;
	}
	Channel &channel = select_ch(ch_name);
	if (channel.check_ch_user(leaver) == 0)
	{
		tmp = Message::msg_no_user_error_401(leaver, leaver._user_nick);
		return result;
	}
	std::vector<UserInfo> users = channel.get_user_info();
	int user_size = users.size();
	result = channel.send_msg_packet(leaver, leaver, msg, PART);
	channel.banish_user(leaver);
	if (user_size == 1)
		delete_ch(ch_name);
	return result;
}

events Database::make_priv_msg(UserInfo &sender, std::string ch_name, const std::string &msg)
{
	events result;
	event tmp;

	if (check_valid_ch(ch_name) == false)
	{
		tmp = Message::msg_no_ch_error_403(sender, ch_name);
		result.insert(tmp);
		return result;
	}
	Channel &channel = select_ch(ch_name);
	if (channel.check_ch_user(sender) == false)
	{
		tmp = Message::msg_no_user_error_401(sender, sender._user_nick);
		result.insert(tmp);
		return result;
	}
	result = channel.send_msg_packet(sender, sender, msg, PRIV);
	return result;
}

events Database::make_notice_msg(UserInfo &sender, std::string ch_name, const std::string &msg)
{
	events result;
	event tmp;

	if (check_valid_ch(ch_name) == false)
	{
		tmp = Message::msg_no_ch_error_403(sender, ch_name);
		result.insert(tmp);
		return result;
	}
	Channel &channel = select_ch(ch_name);
	if (channel.check_ch_user(sender) == false)
	{
		tmp = Message::msg_no_user_error_401(sender, sender._user_nick);
		result.insert(tmp);
		return result;
	}
	result = channel.send_msg_packet(sender, sender, msg, NOTICE);
	return result;
}

events Database::kick_ch(UserInfo &host, UserInfo &target, std::string &ch_name, std::string &msg)
{
	events result;
	event tmp;

	if (check_valid_ch(ch_name) == false)
	{
		tmp = Message::msg_no_ch_error_403(host, ch_name);
		result.insert(tmp);
		return result;
	}
	Channel &channel = select_ch(ch_name);
	if (channel.check_host_address(host))
	{
		if (channel.check_ch_user(target) == true)
		{
			result = channel.send_msg_packet(host, target, msg, KICK);
			channel.banish_user(target);
			if (channel.get_user_info().size() == 0)
				delete_ch(ch_name);
		}
		else
		{
			tmp = Message::msg_kick_no_user_error_441(host, host._user_nick, target._user_nick, ch_name);
			result.insert(tmp);
		}
	}
	else
	{
		tmp = Message::msg_kick_not_op_error_482(host, host._user_nick, ch_name);
		result.insert(tmp);
	}
	return result;
}

events Database::nick_ch(UserInfo &nicker, std::string &send_msg)
{
	events result;
	event tmp;
	UserInfo dummy_user;

	Channel &channel = select_ch(nicker);
	result = channel.send_msg_packet(nicker, dummy_user, send_msg, NICK);
	channel.update_nick(nicker, send_msg);
	return result;
}

events Database::set_ch_topic(const uintptr_t &ident, std::string &ch_name, std::string &topic)
{
	events result;
	event tmp = check_user_verification(ident, "TOPIC");

	if (tmp.second.size())
	{
		result.insert(tmp);
		return result;
	}
	UserInfo &cur_user = select_user(ident);
	if (check_valid_ch(ch_name) == false)
	{
		tmp = Message::msg_no_ch_error_403(cur_user, ch_name);
		result.insert(tmp);
		return result;
	}
	Channel &channel = select_ch(ch_name);
	if (topic.empty())
	{
		if (!channel.get_ch_topic().empty())
		{
			tmp = Message::msg_show_topic_332(cur_user, channel.get_ch_name(), channel.get_ch_topic());
			result.insert(tmp);
		}
		return result;
	}
	if ((channel._ch_flag & F_TOPIC_OWNERSHIP) && !(channel.check_host_address(cur_user)))
	{
		tmp = Message::msg_topic_authentication_error_482(cur_user, ch_name);
		result.insert(tmp);
	}
	else if (channel.check_ch_user(cur_user) == false)
	{
		tmp = Message::msg_not_in_ch_error_442(cur_user, ch_name);
		result.insert(tmp);
	}
	else
	{
		std::string topic_msg = "Topic was changed to " + topic;
		channel.set_ch_topic(topic);
		result = channel.send_msg_packet(cur_user, cur_user, topic_msg, TOPIC);
	}
	return result;
}

events Database::execute_cmd_i_plus(const uintptr_t &ident, t_mode &mode)
{
	events result;
	event tmp;

	Channel &tmp_channel = select_ch(mode.target);
	UserInfo &host = select_user(ident);
	if (tmp_channel.check_host_address(host))
	{
		tmp_channel.set_ch_flag(tmp_channel, mode);
		result = tmp_channel.send_msg_packet(host, host, "+i", MODE);
	}
	else
	{
		tmp = Message::msg_mode_not_op_482(host, mode.target);
		result.insert(tmp);
	}
	return result;
}

events Database::execute_cmd_i_minus(const uintptr_t &ident, t_mode &mode)
{
	events result;
	event tmp;

	Channel &tmp_channel = select_ch(mode.target);
	UserInfo &host = select_user(ident);
	if (tmp_channel.check_host_address(host))
	{
		tmp_channel.set_ch_flag(tmp_channel, mode);
		result = tmp_channel.send_msg_packet(host, host, "-i", MODE);
	}
	else
	{
		tmp = Message::msg_mode_not_op_482(host, mode.target);
		result.insert(tmp);
	}
	return result;
}

events Database::execute_cmd_k_plus(const uintptr_t &ident, t_mode &mode)
{
	events result;
	event tmp;

	if (mode.param.length() == 0)
	{
		tmp = Message::msg_mode_no_arg_error_696(select_user(ident), mode.target, mode.option, "key", "key");
		result.insert(tmp);
		return result;
	}
	Channel &tmp_channel = select_ch(mode.target);
	UserInfo &host = select_user(ident);
	if (tmp_channel.check_host_address(host))
	{
		tmp_channel.set_ch_key(tmp_channel, mode);
		tmp_channel.set_ch_flag(tmp_channel, mode);
		result = tmp_channel.send_msg_packet(host, host, "+k", MODE);
	}
	else
	{
		tmp = Message::msg_mode_not_op_482(host, mode.target);
		result.insert(tmp);
	}
	return result;
}

events Database::execute_cmd_k_minus(const uintptr_t &ident, t_mode &mode)
{
	events result;
	event tmp;

	Channel &tmp_channel = select_ch(mode.target);
	UserInfo &host = select_user(ident);
	if (tmp_channel.check_host_address(host))
	{
		tmp_channel.set_ch_flag(tmp_channel, mode);
		result = tmp_channel.send_msg_packet(host, host, "-k", MODE);
	}
	else
	{
		tmp = Message::msg_mode_not_op_482(host, mode.target);
		result.insert(tmp);
	}
	return result;
}

events Database::execute_cmd_o_plus(const uintptr_t &ident, t_mode &mode)
{
	events result;
	event tmp;

	if (mode.param.length() == 0)
	{
		tmp = Message::msg_mode_no_arg_error_696(select_user(ident), mode.target, mode.option, "op", "nick");
		result.insert(tmp);
		return result;
	}
	else if (!check_user(mode.param))
	{
		tmp = Message::msg_mode_invalid_target_error_401(select_user(ident), mode.param);
		result.insert(tmp);
		return result;
	}

	Channel &target_ch = select_ch(mode.target);
	UserInfo &host_user = select_user(ident);
	if (target_ch.check_host_address(host_user))
	{
		if (!target_ch.check_host_address(select_user(mode.param)))
		{
			target_ch.set_host_address(select_user(mode.param));
		}
		result = target_ch.send_msg_packet(host_user, host_user, "+o", MODE);
	}
	else
	{
		tmp = Message::msg_mode_not_op_482(host_user, mode.target);
		result.insert(tmp);
	}
	return result;
}

events Database::execute_cmd_o_minus(const uintptr_t &ident, t_mode &mode)
{
	events result;
	event tmp;

	if (mode.param.length() == 0)
	{
		tmp = Message::msg_mode_no_arg_error_696(select_user(ident), mode.target, mode.option, "op", "nick");
		result.insert(tmp);
		return result;
	}
	else if (!check_user(mode.param))
	{
		tmp = Message::msg_mode_invalid_target_error_401(select_user(ident), mode.param);
		result.insert(tmp);
		return result;
	}

	Channel &target_ch = select_ch(mode.target);
	UserInfo &host_user = select_user(ident);
	if (target_ch.check_host_address(host_user))
	{
		if (target_ch.check_host_address(select_user(mode.param)))
		{
			target_ch.clear_host_address(select_user(mode.param));
		}
		result = target_ch.send_msg_packet(host_user, host_user, "-o", MODE);
	}
	else
	{
		tmp = Message::msg_mode_not_op_482(host_user, mode.target);
		result.insert(tmp);
	}
	return result;
}

events Database::execute_cmd_t_plus(const uintptr_t &ident, t_mode &mode)
{
	events result;
	event tmp;

	Channel &target_ch = select_ch(mode.target);
	UserInfo &host_user = select_user(ident);
	if (target_ch.check_host_address(host_user))
	{
		target_ch.set_ch_flag(target_ch, mode);
		result = target_ch.send_msg_packet(host_user, host_user, "+t", MODE);
	}
	else
	{
		tmp = Message::msg_mode_not_op_482(host_user, mode.target);
		result.insert(tmp);
	}
	return result;
}

events Database::execute_cmd_t_minus(const uintptr_t &ident, t_mode &mode)
{
	events result;
	event tmp;

	Channel &target_ch = select_ch(mode.target);
	UserInfo &host_user = select_user(ident);
	if (target_ch.check_host_address(host_user))
	{
		target_ch.set_ch_flag(target_ch, mode);
		result = target_ch.send_msg_packet(host_user, host_user, "-t", MODE);
	}
	else
	{
		tmp = Message::msg_mode_not_op_482(host_user, mode.target);
		result.insert(tmp);
	}
	return result;
}

events Database::execute_cmd_l_plus(const uintptr_t &ident, t_mode &mode)
{
	events result;
	event tmp;
	int limit_num = 0;
	std::stringstream get_limit_num_stream(mode.param);
	get_limit_num_stream >> limit_num;

	if (mode.param.length() == 0)
	{
		tmp = Message::msg_mode_no_arg_error_696(select_user(ident), mode.target, mode.option, "limit", "limit");
		result.insert(tmp);
		return result;
	}
	else if (limit_num < 0)
	{
		tmp = Message::msg_mode_l_invalid_arg_error_696(select_user(ident), mode.target, mode.option, mode.param);
		result.insert(tmp);
		return result;
	}

	Channel &target_ch = select_ch(mode.target);
	UserInfo &host_user = select_user(ident);
	if (target_ch.check_host_address(host_user))
	{
		target_ch.set_ch_flag(target_ch, mode);
		target_ch.set_limit_num(limit_num);
		get_limit_num_stream.str("");
		get_limit_num_stream.clear();
		get_limit_num_stream << "\b+l :" << limit_num;
		result = target_ch.send_msg_packet(host_user, host_user, get_limit_num_stream.str(), MODE);
	}
	else
	{
		tmp = Message::msg_mode_not_op_482(host_user, mode.target);
		result.insert(tmp);
	}
	return result;
}

events Database::execute_cmd_l_minus(const uintptr_t &ident, t_mode &mode)
{
	events result;
	event tmp;

	if (mode.param.length() != 0)
	{
		tmp = Message::msg_wrong_mode_option_error_472(ident, mode.param.at(mode.param.length() - 1));
		result.insert(tmp);
		return result;
	}

	Channel &target_ch = select_ch(mode.target);
	UserInfo &host_user = select_user(ident);
	if (target_ch.check_host_address(host_user))
	{
		target_ch.set_ch_flag(target_ch, mode);
		result = target_ch.send_msg_packet(host_user, host_user, "-l", MODE);
	}
	else
	{
		tmp = Message::msg_mode_not_op_482(host_user, mode.target);
		result.insert(tmp);
	}
	return result;
}
