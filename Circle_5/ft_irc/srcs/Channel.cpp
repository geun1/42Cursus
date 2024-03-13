#include "Channel.hpp"
#include "Event.hpp"

Channel::Channel()
{
	this->_ch_flag = 0b1000;
	this->_ch_key = "";
	this->_ch_topic = "";
	this->_num_limit = 0;
}

std::vector<uintptr_t> &Channel::get_host_address(void)
{
	return this->_host_address;
}

void Channel::set_host_address(uintptr_t host_sock)
{
	this->_host_address.push_back(host_sock);
}

void Channel::set_host_address(UserInfo &user)
{
	uintptr_t host_sock = user._user_sock;
	this->_host_address.push_back(host_sock);
}


void Channel::update_nick(UserInfo &usr, std::string new_nick)
{
	std::vector<UserInfo>::iterator i;
	for (i = _user_info.begin(); i != _user_info.end(); i++)
	{
		if (i->_user_nick == usr._user_nick)
		{
			i->_user_nick = new_nick;
			break;
		}
	}
}

std::vector<UserInfo> Channel::sort_user_by_client_socks(void)
{
	std::vector<UserInfo> result;

	result.push_back(_user_info.at(0));
	if (_user_info.size() == 1)
		return result;
	for (std::vector<UserInfo>::iterator i = _user_info.begin(); i != _user_info.end(); ++i)
	{
		std::vector<UserInfo>::iterator comparison_i = result.begin();
		for (; comparison_i != result.end(); ++comparison_i)
		{
			if (*i > *comparison_i)
			{
				continue;
			}
			else if (*i < *comparison_i || *i == *comparison_i)
			{
				break;
			}
		}
		if (comparison_i == result.end() || *i != *comparison_i)
			result.insert(comparison_i, *i);
	}
	return result;
} 

std::string Channel::get_user_result(void)
{
	std::string result;
	std::vector<UserInfo> sort = sort_user_by_client_socks();
	for (std::vector<UserInfo>::iterator i = sort.begin(); i != sort.end(); ++i)
	{
		result += (check_host_address(*i) ? "@" + i->_user_nick : i->_user_nick);
		result += " ";
	}
	return result;
}

events Channel::send_msg_packet(UserInfo &sender, UserInfo &target, std::string msg, int remocon)
{
	events result;
	std::vector<UserInfo>::iterator i;

	for (i = _user_info.begin(); i != _user_info.end(); i++)
	{
		event packet;

		switch (remocon)
		{
		case JOIN:
			packet = Message::msg_join(sender, *i, this->get_ch_name());
			break;
		case PART:
			packet = Message::msg_part(sender, *i, this->get_ch_name(), msg);
			break;
		case PRIV:
			if (sender == *i)
			{
				packet.first = sender._user_sock;
				packet.second = "";
			}
			else
			{
				packet = Message::msg_privmsg_to_ch_users(sender, *i, msg, this->get_ch_name());
			}
			break;
		case KICK:
			packet = Message::msg_kick(sender, *i, target._user_nick, this->get_ch_name(), msg);
			break;
		case QUIT:
			packet = (sender == *i) ? Message::msg_quit(sender, msg)
															 : Message::msg_quit_to_remain(sender, *i, msg);
			break;
		case NOTICE:
			if (sender == *i)
			{
				packet.first = sender._user_sock;
				packet.second = "";
			}
			else
			{
				packet = Message::msg_notice_to_ch_users(sender, *i, msg, this->get_ch_name());
			}
			break;
		case TOPIC:
			packet = Message::msg_topic(sender, *i, this->get_ch_name(), msg);
			break;
		case NICK:
			packet = Message::msg_change_nick(sender, *i, msg);
			break;
		case MODE:
			packet = Message::msg_mode(sender, *i, this->get_ch_name(), msg);
			break;
		case INVITE:
			if (sender == *i)
			{
				packet = Message::msg_invite_to_target_user(sender, target, this->get_ch_name());
			}
			else
			{
				packet = Message::msg_invite_to_users(sender, *i, this->get_ch_name());
			}
			break;
		}

		result.insert(packet);
	}
	if (remocon == INVITE)
	{
		event packet = Message::msg_invite_to_outsider(sender, target, this->get_ch_name());
		result.insert(packet);
	}
	return result;
}

std::string &Channel::get_ch_name(void)
{
	return this->_ch_name;
}

std::string &Channel::get_ch_topic(void)
{
	return this->_ch_topic;
}

bool Channel::check_ch_user(UserInfo &usr)
{
	std::vector<UserInfo>::iterator i;

	for (i = _user_info.begin(); i != _user_info.end(); i++)
	{
		if (i->_user_sock == usr._user_sock)
			return 1;
	}
	return 0;
}




void Channel::append_joiner(UserInfo &joiner)
{
	_user_info.push_back(joiner);
}

void Channel::set_ch_name(std::string &ch_name)
{
	this->_ch_name = ch_name;
}

void Channel::set_ch_topic(std::string &topic)
{
	this->_ch_topic = topic;
}

std::vector<UserInfo> &Channel::get_user_info()
{
	return this->_user_info;
}
void Channel::banish_user(UserInfo &usr)
{
	if (check_host_address(usr))
		clear_host_address(usr);

	std::vector<UserInfo>::iterator i = std::find(this->_user_info.begin(),
																						 this->_user_info.end(), usr);
	std::size_t size = std::distance(this->_user_info.begin(), i);
	this->_user_info.erase(this->_user_info.begin() + size);
}
bool Channel::operator==(const Channel &t) const
{
	return (this->_ch_name == t._ch_name);
}

void Channel::clear_host_address(uintptr_t host_sock)
{
	std::vector<uintptr_t>::iterator i = std::find(this->_host_address.begin(), this->_host_address.end(), host_sock);
	std::size_t size = std::distance(this->_host_address.begin(), i);
	this->_host_address.erase(this->_host_address.begin() + size);
}

void Channel::clear_host_address(UserInfo &host_user)
{
	uintptr_t host_sock = host_user._user_sock;
	std::vector<uintptr_t>::iterator i = std::find(this->_host_address.begin(), this->_host_address.end(), host_sock);
	std::size_t size = std::distance(this->_host_address.begin(), i);
	this->_host_address.erase(this->_host_address.begin() + size);
}

bool Channel::check_host_address(uintptr_t user_sock)
{
	std::vector<uintptr_t>::iterator i;

	for (i = _host_address.begin(); i != _host_address.end(); i++)
	{
		if (*i == user_sock)
			return true;
	}
	return false;
}

bool Channel::check_host_address(UserInfo &usr)
{
	std::vector<uintptr_t>::iterator i;
	uintptr_t user_sock = usr._user_sock;

	for (i = _host_address.begin(); i != _host_address.end(); i++)
	{
		if (*i == user_sock)
			return true;
	}
	return false;
}

int Channel::get_limit_num(void)
{
	return this->_num_limit;
}

void Channel::set_limit_num(int &member_limit)
{
	this->_num_limit = member_limit;
}

void Channel::set_ch_flag(Channel &channel, t_mode &mode)
{
	if (mode.mode_type == I_PLUS && !(channel._ch_flag & F_INVITE_ONLY))
	{
		channel._ch_flag += F_INVITE_ONLY;
	}
	else if (mode.mode_type == I_MINUS && (channel._ch_flag & F_INVITE_ONLY))
	{
		channel._ch_flag -= F_INVITE_ONLY;
	}
	else if (mode.mode_type == K_PLUS && !(channel._ch_flag & F_KEY_NEEDED))
	{
		channel._ch_flag += F_KEY_NEEDED;
	}
	else if (mode.mode_type == K_MINUS && (channel._ch_flag & F_KEY_NEEDED))
	{
		channel._ch_flag -= F_KEY_NEEDED;
	}
	else if (mode.mode_type == T_PLUS && !(channel._ch_flag & F_TOPIC_OWNERSHIP))
	{
		channel._ch_flag += F_TOPIC_OWNERSHIP;
	}
	else if (mode.mode_type == T_MINUS && (channel._ch_flag & F_TOPIC_OWNERSHIP))
	{
		channel._ch_flag -= F_TOPIC_OWNERSHIP;
	}
	else if (mode.mode_type == L_PLUS && !(channel._ch_flag & F_LIMITED_MEMBERSHIP))
	{
		channel._ch_flag += F_LIMITED_MEMBERSHIP;
	}
	else if (mode.mode_type == L_MINUS && (channel._ch_flag & F_LIMITED_MEMBERSHIP))
	{
		channel._ch_flag -= F_LIMITED_MEMBERSHIP;
	}
	else
		return;
}

bool Channel::check_invitation(const uintptr_t &usr)
{
	std::vector<uintptr_t>::iterator i;

	for (i = _invitations_address.begin(); i != _invitations_address.end(); i++)
	{
		if (*i == usr)
			return true;
	}
	return false;
}
void Channel::append_invitation(uintptr_t user)
{
	_invitations_address.push_back(user);
}

void Channel::set_ch_key(Channel &tmp_channel, t_mode mode)
{
	tmp_channel._ch_key = mode.param;
}

bool Channel::check_ch_key(Channel &tmp_channel, const std::string &tmp_password)
{
	if (tmp_channel._ch_key != tmp_password)
	{
		return false;
	}
	return true;
}