#include "Database.hpp"
#include "Event.hpp"
#include "UserInfo.hpp"
#include <string>
#include <sys/_types/_ct_rune_t.h>

#include "ServerInfo.hpp"

events (Database::*Database::mode_handlers[N_MODE_TYPE])(const uintptr_t &ident, t_mode &mode) =
		{
				&Database::execute_cmd_i_plus,
				&Database::execute_cmd_i_minus,
				&Database::execute_cmd_t_plus,
				&Database::execute_cmd_t_minus,
				&Database::execute_cmd_l_plus,
				&Database::execute_cmd_l_minus,
				&Database::execute_cmd_o_plus,
				&Database::execute_cmd_o_minus,
				&Database::execute_cmd_k_plus,
				&Database::execute_cmd_k_minus,
};

std::vector<UserInfo> &Database::get_user_vector(void)
{
	return _user_vector;
}

void Database::delete_invalid_user(const uintptr_t &ident)
{
	if (!check_user(ident))
	{
		return;
	}
	UserInfo &current_user = select_user(ident);
	if (check_valid_user(current_user))
	{
		Channel &current_ch = select_ch(current_user);

		std::vector<UserInfo> &users = current_ch.get_user_info();
		const int user_size = users.size();
		current_ch.banish_user(current_user);
		if (user_size == 1)
			delete_ch(current_ch.get_ch_name());
	}
	_user_vector.erase(remove(_user_vector.begin(), _user_vector.end(), current_user), _user_vector.end());
}

event Database::check_user_verification(const uintptr_t &ident, const std::string &command_type)
{
	event result;

	result.first = ident;
	if (!check_user(ident))
	{
		return Message::msg_password_error_464(ident);
	}
	UserInfo &cur_user = select_user(ident);
	if (!(cur_user._user_flag & F_PASS))
	{
		return Message::msg_password_error_464(ident);
	}
	if (command_type == "NICK" || command_type == "USER")
	{
		return result;
	}
	if (!(cur_user._user_flag & F_NICK))
	{
		return Message::msg_not_registered_user_error_451(ident, command_type);
	}
	if (!(cur_user._user_flag & F_USER))
	{
		return Message::msg_not_registered_user_error_451(cur_user, command_type);
	}
	return result;
}

UserInfo &Database::select_user(const uintptr_t &ident)
{
	std::vector<UserInfo>::iterator i;

	for (i = _user_vector.begin(); i != _user_vector.end(); i++)
	{
		if (i->_user_sock == ident)
		{
			return (*i);
		}
	}
	return (*i);
}

UserInfo &Database::select_user(const std::string &nickname)
{
	std::vector<UserInfo>::iterator i;

	for (i = _user_vector.begin(); i != _user_vector.end(); i++)
	{
		if (i->_user_nick == nickname)
		{
			return (*i);
		}
	}
	return (*i);
}

bool Database::check_user(const uintptr_t &ident)
{
	for (std::vector<UserInfo>::iterator i = _user_vector.begin(); i != _user_vector.end(); i++)
	{
		if (i->_user_sock == ident)
		{
			return (true);
		}
	}
	return (false);
}
bool Database::check_user(const std::string &nickname)
{
	for (std::vector<UserInfo>::iterator i = _user_vector.begin(); i != _user_vector.end(); i++)
	{
		if (i->_user_nick == nickname)
		{
			return (true);
		}
	}
	return (false);
}

void Database::delete_user(UserInfo &leaver)
{
	int idx = 0;
	std::vector<UserInfo>::iterator i;

	for (i = _user_vector.begin(); i != _user_vector.end(); i++)
	{
		if (*i == leaver)
		{
			_user_vector.erase(_user_vector.begin() + idx);
			break;
		}
		idx++;
	}
}

bool Database::check_nick(std::string &new_nick)
{
	if (!isalpha(static_cast<int>(new_nick[0])) && static_cast<int>(new_nick[0]) != '_')
		return false;
	for (std::size_t i(1); i < new_nick.size(); i++)
	{
		if (!isalnum(static_cast<int>(new_nick[i])) && static_cast<int>(new_nick[i]) != '_')
		{
			return false;
		}
	}
	return true;
}

events Database::execute_cmd_mode(const uintptr_t &ident, t_mode &mode)
{
	events result;
	event tmp = check_user_verification(ident, "MODE");

	if (tmp.second.size())
	{
		result.insert(tmp);
	}
	else if (check_user(mode.target) && !check_valid_user(select_user(mode.target)))
	{
		tmp.first = ident;
		return result;
	}
	else if (check_valid_ch(mode.target) == false)
	{
		tmp = Message::msg_no_ch_error_403(select_user(ident), mode.target);
		result.insert(tmp);
		return result;
	}
	else
		result = (this->*mode_handlers[mode.mode_type])(ident, mode);
	return result;
}

events Database::execute_cmd_invite(const uintptr_t &ident, std::string &user, std::string &ch_name)
{
	events result;
	event tmp = check_user_verification(ident, "INVITE");

	if (tmp.second.size())
	{
		result.insert(tmp);
	}
	else if (check_valid_ch(ch_name) == false)
	{
		event tmp = Message::msg_no_ch_error_403(select_user(ident), ch_name);
		result.insert(tmp);
	}
	else if (check_user(user) == false)
	{
		event tmp = Message::msg_invite_invalid_user_error(select_user(ident), user);
		result.insert(tmp);
	}
	else if (check_valid_user(select_user(user)) == true)
	{
		event tmp = Message::msg_already_in_ch_error_443(select_user(ident), ch_name);
		result.insert(tmp);
	}
	else
	{
		UserInfo &invitor = select_user(ident);
		UserInfo &invited_user = select_user(user);
		Channel &current_ch = select_ch(ch_name);
		current_ch.append_invitation(invited_user._user_sock);
		result = current_ch.send_msg_packet(invitor, invited_user, ch_name, INVITE);
		tmp.first = invitor._user_sock;
		tmp.second.clear();
		result.insert(tmp);
	}
	return result;
}

event Database::execute_cmd_pass(const uintptr_t &ident)
{
	event tmp;

	tmp.first = ident;
	if (!check_user(ident))
	{
		UserInfo tmp_user;
		tmp_user._user_sock = ident;
		tmp_user._user_flag |= F_PASS;
		_user_vector.push_back(tmp_user);
	}
	ServerInfo::print_user_list(_user_vector);
	return tmp;
}

events Database::execute_cmd_nick(const uintptr_t &ident, std::string &new_nick)
{
	events result;
	event tmp = check_user_verification(ident, "NICK");
	if (tmp.second.size() != 0)
	{
		result.insert(tmp);
		return result;
	}

	UserInfo &current_user = select_user(ident); 
	if (!check_nick(new_nick))
	{ 
		if (current_user._user_nick.empty()) 
			tmp = Message::msg_nick_error_432(ident, new_nick);
		else
		{
			UserInfo &existed_usr = select_user(current_user._user_nick);
			tmp = Message::msg_nick_error_432(existed_usr, new_nick);
		}
		result.insert(tmp); 
		return result;
	}
	if (check_user(new_nick))
	{ 
		UserInfo &existed_usr = select_user(new_nick);
		if (ident == existed_usr._user_sock)
			return result;
		if (existed_usr._user_name.size())
		{
			if (current_user._user_nick.empty())
				tmp = Message::msg_already_nick_without_nick_error_433(ident, new_nick);
			else
				tmp = Message::msg_already_nick_with_nick_error_432(current_user, new_nick);
			result.insert(tmp);
			return result;
		}
		tmp = Message::msg_nick_error_433(existed_usr, new_nick);

		current_user._user_nick = new_nick;
		current_user._user_flag |= F_NICK;

		result.insert(tmp);

		existed_usr._user_nick.clear();
		existed_usr._user_flag &= ~F_NICK;
	}
	if (!(current_user._user_flag & F_NICK))
	{
		current_user._user_nick = new_nick;
		current_user._user_flag |= F_NICK;
		if (current_user._user_flag & F_USER)
		{
			tmp = Message::msg_connection_001(current_user);
			result.insert(tmp);
		}
	}
	else
	{
		if (check_valid_user(current_user))
		{
			result = nick_ch(current_user, new_nick);
		}
		tmp = Message::msg_change_nick(current_user, current_user, new_nick);
		current_user._user_nick = new_nick;
		result.insert(tmp);
	}
	ServerInfo::print_user_list(_user_vector);
	return result;
}

event Database::execute_cmd_user(const uintptr_t &ident, const std::string &username, const std::string &mode, const std::string &unused, const std::string &realname)
{
	event result = check_user_verification(ident, "USER");

	if (result.second.size())
	{
		return result;
	}
	UserInfo &current_user = select_user(ident);
	current_user.input_user(username, mode, unused, realname);
	if (!(current_user._user_flag & F_USER))
	{
		current_user._user_flag |= F_USER;
		if (current_user._user_flag & F_NICK)
			result = Message::msg_connection_001(current_user);
		else
			result = Message::msg_user_error_302(current_user);
	}
	else
		result = Message::msg_user_error_302(current_user);
	ServerInfo::print_user_list(_user_vector);
	return result;
}

event Database::execute_cmd_pong(const uintptr_t &ident, std::string &msg)
{
	event result = check_user_verification(ident, "PING");

	if (result.second.size())
	{
		return result;
	}
	UserInfo &cur_user = select_user(ident);
	if (msg.at(0) == ':' && msg.length() == 1) 
	{
		result = Message::msg_wrong_ping_argument_error_409(cur_user, "PING");
		return result;
	}
	if (msg.at(0) == ':')
		msg = msg.substr(1, msg.length() - 1);
	result = Message::msg_pong(ident, msg);
	return result;
}

events Database::execute_cmd_join(const uintptr_t &ident, const std::string &ch_name, const std::string &tmp_password)
{
	events result;
	event tmp = check_user_verification(ident, "JOIN");

	if (tmp.second.size())
	{
		result.insert(tmp);
		return result;
	}
	else if (check_user(ident))
	{
		UserInfo &current_user = select_user(ident);
		if (ch_name.empty())
		{
			if (!check_user(ident))
			{
				tmp = Message::msg_not_enough_arg_error_461(ident, "JOIN");
				result.insert(tmp);
			}
			else
			{
				tmp = Message::msg_not_enough_arg_error_461(current_user, "JOIN");
				result.insert(tmp);
			}
		}
		else if (ch_name.at(0) != '#')
		{
			tmp = Message::msg_join_invalid_ch_name_error_476(current_user, ch_name);
			result.insert(tmp);
		}
		else if (ch_name.find(',') != std::string::npos)
		{
			tmp = Message::msg_join_invalid_ch_name_error_476(current_user, ch_name);
			result.insert(tmp);
		}
		else
		{
			result = join_ch(current_user, ch_name, tmp_password);
		}
	}
	return result;
}

events Database::execute_cmd_part(const uintptr_t &ident, std::string &ch_name, const std::string &msg)
{
	events result;
	event tmp = check_user_verification(ident, "PART");

	if (tmp.second.size())
	{
		result.insert(tmp);
		return result;
	}
	UserInfo &current_user = select_user(ident);
	result = part_ch(current_user, ch_name, msg);
	return result;
}

events Database::execute_cmd_quit(const uintptr_t &ident, const std::string &msg)
{
	events result;
	event tmp = check_user_verification(ident, "QUIT");

	if (tmp.second.size())
	{
		result.insert(tmp);
		return result;
	}
	else if (check_user(ident))
	{
		UserInfo &current_user = select_user(ident);

		if (check_valid_user(current_user))
		{
			Channel &current_ch = select_ch(current_user);
			result = quit_ch(current_user, current_ch.get_ch_name(), msg);
		}
		else
		{
			tmp = Message::msg_quit(current_user, msg);
			result.insert(tmp);
		}
		_user_vector.erase(remove(_user_vector.begin(), _user_vector.end(), current_user), _user_vector.end());
	}
	return result;
}

events Database::execute_cmd_privmsg(const uintptr_t &ident, const std::string &target_name, const std::string &msg)
{
	events result;
	event tmp = check_user_verification(ident, "PRIVMSG");

	if (tmp.second.size())
	{
		result.insert(tmp);
		return result;
	}
	if (check_user(ident))
	{
		UserInfo &current_user = select_user(ident);

		tmp.first = ident;
		if (target_name.at(0) == '#')
		{
			result = make_priv_msg(current_user, target_name, msg);
		}
		else
		{
			if (target_name == "BOT")
			{
				tmp = send_msg_to_bot(current_user, msg);
				result.insert(tmp);
			}
			else if (check_user(target_name))
			{
				UserInfo &tar_usr = select_user(target_name);
				tmp = Message::msg_privmsg_to_user(current_user, tar_usr, msg);
				result.insert(tmp);
				tmp.first = current_user._user_sock;
				tmp.second.clear();
				result.insert(tmp);
			}
			else
			{
				tmp = Message::msg_privmsg_to_nothing_error_401(current_user, target_name);
				result.insert(tmp);
			}
		}
	}
	return result;
}

events Database::execute_cmd_notice(const uintptr_t &ident, const std::string &target_name, const std::string &msg)
{
	events result;
	event tmp = check_user_verification(ident, "NOTICE");

	if (tmp.second.size())
	{
		result.insert(tmp);
		return result;
	}
	if (target_name == "BOT")
	{
		result.insert(tmp);
		return result;
	}
	UserInfo &current_user = select_user(ident);
	if (target_name.at(0) == '#')
	{
		result = make_notice_msg(current_user, target_name, msg);
	}
	else
	{
		if (check_user(target_name))
		{
			UserInfo &tar_usr = select_user(target_name);
			tmp = Message::msg_notice_to_user(current_user, tar_usr, msg);
			result.insert(tmp);
			tmp.first = current_user._user_sock;
			tmp.second.clear();
			result.insert(tmp);
		}
		else
		{
			tmp = Message::msg_notice_no_nick_error_401(current_user, current_user);
			result.insert(tmp);
		}
	}
	return result;
}

events Database::execute_cmd_kick(const uintptr_t &ident, const std::string &target_name, std::string &ch_name, std::string &msg)
{
	event tmp = check_user_verification(ident, "KICK");
	events result;

	if (tmp.second.size())
	{
		result.insert(tmp);
		return result;
	}
	if (check_user(ident))
	{
		UserInfo &kicker = select_user(ident);
		if (check_user(target_name))
		{
			UserInfo &target = select_user(target_name);
			result = kick_ch(kicker, target, ch_name, msg);
		}
		else
		{
			tmp = Message::msg_no_user_error_401(kicker, target_name);
			result.insert(tmp);
		}
	}
	return result;
}

void Database::make_bot(const std::string &name)
{

	UserInfo tmp_usr;

	tmp_usr._user_nick = name;
	tmp_usr.input_user("Dummy", "Dummy", "localhost", "Dummy");
	_user_vector.push_back(tmp_usr);
}
event Database::send_msg_to_bot(UserInfo &current_user, const std::string &msg)
{
	event tmp;
	std::string bot_msg;

	if (msg == "!command")
	{
		bot_msg = "NICK, USER, PING, JOIN, QUIT, PRIVMSG, KICK, PART, TOPIC, NOTICE";
	}
	else if (msg == "!channel")
	{
		if (_ch_vector.empty())
		{
			bot_msg = "NO CHANNEL IN THIS SERVER!";
		}
		else
		{
			bot_msg = "● [CHANNEL LIST] : ";
			for (std::size_t i(0); i < _ch_vector.size(); ++i)
			{
				bot_msg += std::to_string(i) + ". " + _ch_vector[i].get_ch_name() + " : " + _ch_vector[i].get_ch_topic() + ((i == (_ch_vector.size() - 1)) ? "" : ", ");
			}
		}
	}
	else if (msg == "!user")
	{
		bot_msg = "● [USER LIST] : ";
		std::size_t n(1);
		for (std::size_t i(1); i < _user_vector.size(); ++i)
		{
			if ((_user_vector[i]._user_flag & F_PASS) && (_user_vector[i]._user_flag & F_NICK))
				bot_msg += std::to_string(n++) + ". " + _user_vector[i]._user_nick + ((i == (_user_vector.size() - 1)) ? "" : ", ");
		}
	}
	else
	{
		bot_msg = "THAT IS NOT MY COMMAND. YOU CAN USE : '!command' & '!channel' & !user.";
	}
	tmp = Message::msg_privmsg_to_bot(current_user, bot_msg);
	return tmp;
}
