#include "Message.hpp"
#include <vector>

const std::string Message::_server_name = "irc.local";

event Message::msg_pong(const uintptr_t &socket, const std::string &msg)
{
	event result;

	const std::string &pong_reply = ":" + Message::_server_name + " PONG " + Message::_server_name + " :" + msg;
	result = std::make_pair(socket, pong_reply + "\r\n");
	return result;
}

event Message::msg_not_enough_arg_error_461(const UserInfo &sender, const std::string &command)
{
	event result;

	const std::string &error_message = ":" + Message::_server_name + " 461 " + sender._user_nick + " " + command + " :Not enough parameters";
	result = std::make_pair(sender._user_sock, error_message + "\r\n");
	return result;
}

event Message::msg_not_enough_arg_error_461(const uintptr_t &sock, const std::string &command)
{
	event result;

	const std::string &error_message = ":" + Message::_server_name + " 461 * " + command + " :Not enough parameters";
	result = std::make_pair(sock, error_message + "\r\n");
	return result;
}

event Message::msg_not_registered_user_error_451(const UserInfo &sender, const std::string &command)
{
	event result;

	const std::string &error_message = ":" + Message::_server_name + " 451 " + sender._user_nick + " " + command + " :You have not registered";
	result = std::make_pair(sender._user_sock, error_message + "\r\n");
	return result;
}

event Message::msg_not_registered_user_error_451(const uintptr_t &sock, const std::string &command)
{
	event result;

	const std::string &error_message = ":" + Message::_server_name + " 451 * " + " " + command + " :You have not registered";
	result = std::make_pair(sock, error_message + "\r\n");
	return result;
}

event Message::msg_wrong_ping_argument_error_409(const UserInfo &sender, const std::string &command)
{
	event result;

	const std::string &error_message = ":" + Message::_server_name + " 409 " + sender._user_nick + " " + command + " :No origin specified";
	result = std::make_pair(sender._user_sock, error_message + "\r\n");
	return result;
}

event Message::msg_change_nick(const UserInfo &sender, const UserInfo &receiver, const std::string &new_nick)
{
	event result;

	const std::string &nick_msg = ":" + sender._user_nick + "!" + sender._user_name + "@" + sender._user_unused + " NICK :" + new_nick;
	result = std::make_pair(receiver._user_sock, nick_msg + "\r\n");
	return result;
}

event Message::msg_password_error_464(const uintptr_t &sock)
{
	event result;

	const std::string &nick_msg = ":" + Message::_server_name + " 464 " + "UserInfo :Password Incorrect, Server disconnected";
	result = std::make_pair(sock, nick_msg + "\r\n");
	return result;
}

event Message::msg_already_nick_with_nick_error_432(const UserInfo &sender, const std::string &new_nick)
{
	event result;

	const std::string &nick_msg = ":" + Message::_server_name + " 432 " + sender._user_nick + " " + new_nick + " :Nickname is already in use.";
	result = std::make_pair(sender._user_sock, nick_msg + "\r\n");
	return result;
}

event Message::msg_nick_error_433(const UserInfo &sender, const std::string &new_nick)
{
	event result;

	const std::string &nick_msg = ":" + Message::_server_name + " 433 " + sender._user_nick + " " + new_nick + " :Nickname overruled.";
	result = std::make_pair(sender._user_sock, nick_msg + "\r\n");
	return result;
}

event Message::msg_already_nick_without_nick_error_433(const uintptr_t &sock, const std::string &new_nick)
{
	event result;

	const std::string &nick_msg = ":" + Message::_server_name + " 433 * " + new_nick + " :Nickname is already in use.";
	result = std::make_pair(sock, nick_msg + "\r\n");
	return result;
}

event Message::msg_nick_error_432(const UserInfo &sender, const std::string &new_nick)
{
	event result;

	const std::string &nick_msg = ":" + Message::_server_name + " 432 " + sender._user_nick + " " + new_nick + " Erroneous Nickname.";
	result = std::make_pair(sender._user_sock, nick_msg + "\r\n");
	return result;
}

event Message::msg_nick_error_432(const uintptr_t &sock, const std::string &new_nick)
{
	event result;

	const std::string &nick_msg = ":" + Message::_server_name + " 432 " + " * " + " " + new_nick + " Erroneous Nickname.";
	result = std::make_pair(sock, nick_msg + "\r\n");
	return result;
}

event Message::msg_connection_001(const UserInfo &sender)
{
	event result;

	const std::string &msg001 = ":" + Message::_server_name + " 001 " + sender._user_nick + " :Welcome to the 42's irc network " + sender._user_nick + "!" + sender._user_mode;
	result = std::make_pair(sender._user_sock, msg001 + "\r\n");
	return result;
}

event Message::msg_user_error_302(const UserInfo &sender)
{
	event result;
	std::string msg;

	if (sender._user_flag & F_NICK)
		msg = ":" + Message::_server_name + " 302 " + sender._user_nick + " :" + sender._user_name + "=+root@127.0.0.1 " + sender._user_mode + "=+root@127.0.0.1 " + sender._user_unused + "=+root@127.0.0.1 " + sender._user_realname + "=+root@127.0.0.1";
	else
		msg = ":" + Message::_server_name + " 302  :";

	result = std::make_pair(sender._user_sock, msg + "\r\n");
	return result;
}

event Message::msg_quit(const UserInfo &sender, std::string leave_message)
{
	event result;

	if (leave_message.empty())
	{
		leave_message = "leaving";
	}

	const std::string &quit_channel_message = "ERROR :Closing link: (" + sender._user_nick + ") [Quit: " + leave_message + "]";
	result = std::make_pair(sender._user_sock, quit_channel_message + "\r\n");
	return result;
}

event Message::msg_quit_to_remain(const UserInfo &sender, const UserInfo &receiver, std::string leave_message)
{
	event result;

	if (leave_message.empty())
	{
		leave_message = "leaving";
	}
	const std::string &quit_message = ":" + sender._user_nick + "!" + sender._user_name + "@" + sender._user_unused + " QUIT :Quit: " + leave_message;
	result = std::make_pair(receiver._user_sock, quit_message + "\r\n");
	return result;
}

event Message::msg_join(const UserInfo &sender, const UserInfo &receiver, const std::string &channel)
{
	event result;

	const std::string &msg_join = ":" + sender._user_nick + "!" + sender._user_name + "@127.0.0.1 JOIN :" + channel;
	result = make_pair(receiver._user_sock, msg_join + "\r\n");
	return result;
}

event Message::msg_join_invalid_ch_name_error_476(const UserInfo &sender, const std::string invaild_channel)
{
	event result;

	const std::string &error_message = ":" + Message::_server_name + " 476 " + sender._user_nick + " " + invaild_channel + " :Invaild channel name";
	result = std::make_pair(sender._user_sock, error_message + "\r\n");
	return result;
}

std::string Message::msg_join_353(const UserInfo &sender, const std::string &ch_name, const std::string &ch_user_result)
{
	const std::string &result = ":" + Message::_server_name + " 353 " + sender._user_nick + " " + "=" + " " + ch_name + " :" + ch_user_result;
	return result + "\r\n";
}

std::string Message::msg_join_366(const UserInfo &sender, const std::string &ch_name)
{
	const std::string &result = ":" + Message::_server_name + " 366 " + sender._user_nick + " " + ch_name + " :End of /NAMES list.";
	return result + "\r\n";
}

event Message::msg_part(const UserInfo &sender, const UserInfo &receiver, const std::string &channel, const std::string &msg)
{
	event result;

	const std::string &msg_part = ":" + sender._user_nick + "!" + sender._user_name + "@" + receiver._user_mode + " PART " + channel + " " + msg + "";
	result = std::make_pair(receiver._user_sock, msg_part + "\r\n");
	return result;
}

event Message::msg_kick(const UserInfo &sender, const UserInfo &receiver, const std::string &target, const std::string &channel, const std::string &msg)
{
	event result;

	const std::string &msg_kick = ":" + sender._user_nick + "!" +
																		sender._user_name + '@' + sender._user_unused + " KICK " + channel + " " + target + " :" + msg + "";
	result = std::make_pair(receiver._user_sock, msg_kick + "\r\n");
	return result;
}

event Message::msg_kick_not_op_error_482(const UserInfo &sender, const std::string &host, const std::string &channel)
{
	event result;

	const std::string &msg_kick = ":" + Message::_server_name +
																		" 482 " + host + " " + channel + " :You must be a channel operator";
	result = std::make_pair(sender._user_sock, msg_kick + "\r\n");
	return result;
}

event Message::msg_kick_no_user_error_441(const UserInfo &sender, const std::string &host, const std::string &target, const std::string &channel)
{
	event result;

	const std::string &msg_kick = ":" + Message::_server_name +
																		" 441 " + host + " " + target + " " + channel + " :They are not on that channel";
	result = std::make_pair(sender._user_sock, msg_kick + "\r\n");
	return result;
}

event Message::msg_privmsg_to_bot(const UserInfo &sender, const std::string &msg)
{
	event result;

	const std::string &privmsg = ":BOT!dummy@" + sender._user_unused + " PRIVMSG " +
															 sender._user_nick + " :" + msg;
	result = std::make_pair(sender._user_sock, privmsg + "\r\n");
	return (result);
}

event Message::msg_privmsg_to_user(const UserInfo &sender, const UserInfo &target, const std::string &msg)
{
	event result;

	const std::string &privmsg = ":" + sender._user_nick + "!" + sender._user_name + "@" + sender._user_unused + " PRIVMSG " +
															 target._user_nick + " :" + msg;
	result = std::make_pair(target._user_sock, privmsg + "\r\n");

	return (result);
}

event Message::msg_privmsg_to_ch_users(const UserInfo &sender, const UserInfo &receiver, const std::string &msg, const std::string &channel)
{
	event result;

	const std::string &privmsg = ":" + sender._user_nick + "!" + sender._user_name + "@" + sender._user_unused + " PRIVMSG " +
															 channel + " :" + msg;
	result = std::make_pair(receiver._user_sock, privmsg + "\r\n");
	return (result);
}

event Message::msg_privmsg_to_nothing_error_401(const UserInfo &sender, const std::string &target)
{
	event result;

	const std::string &privmsg = ":" + sender._user_nick + " 401 " + sender._user_nick + " " + target + " :No such nick";
	result = std::make_pair(sender._user_sock, privmsg + "\r\n");
	return (result);
}

event Message::msg_notice_to_user(const UserInfo &sender, const UserInfo &target, const std::string &msg)
{
	event result;

	const std::string &privmsg = ":" + sender._user_nick + "@" + sender._user_unused + " NOTICE " +
															 target._user_nick + " :" + msg;
	result = std::make_pair(target._user_sock, privmsg + "\r\n");
	return (result);
}

event Message::msg_notice_to_ch_users(const UserInfo &sender, const UserInfo &receiver, const std::string &msg, const std::string &channel)
{
	event result;

	const std::string &privmsg = ":" + sender._user_nick + "@" + sender._user_unused + " NOTICE " +
															 channel + " :" + msg;
	result = std::make_pair(receiver._user_sock, privmsg + "\r\n");
	return (result);
}

event Message::msg_notice_no_nick_error_401(const UserInfo &sender, const UserInfo &receiver)
{
	event result;

	const std::string &privmsg = ":" + Message::_server_name + " 401 " + sender._user_nick + " " + receiver._user_name +
															 " No such nick";
	result = std::make_pair(sender._user_sock, privmsg + "\r\n");
	return (result);
}

#include <sstream>

event Message::msg_topic(const UserInfo &sender, const UserInfo &receiver, const std::string &channel, const std::string &topic)
{
	event result;

	std::istringstream ss1(topic);
	std::string buffer;
	while( getline(ss1,buffer,' ')){
    }

	const std::string &topic_msg = ":" + sender._user_unused + "!" + sender._user_name + " TOPIC " +
																 channel + " " + buffer;

	result = std::make_pair(receiver._user_sock, topic_msg + "\r\n");
	return (result);
}

event Message::msg_topic_authentication_error_482(const UserInfo &sender, const std::string &channel)
{
	event result;

	const std::string &topic_msg = ":" + Message::_server_name + " 482 " + sender._user_nick + " " + channel + " :You do not have access to change the topic on this channel";
	result = std::make_pair(sender._user_sock, topic_msg + "\r\n");
	return result;
}

event Message::msg_show_topic_332(const UserInfo &sender, const std::string &channel_name, const std::string &channel_topic)
{
	event result;

	const std::string &topic_msg = ":" + Message::_server_name + " 332 " + sender._user_nick + " " + channel_name + " :" + channel_topic;
	result = std::make_pair(sender._user_sock, topic_msg + "\r\n");
	return result;
}

event Message::msg_not_in_ch_error_442(const UserInfo &sender, const std::string &channel)
{
	event result;

	const std::string &no_msg = ":" + Message::_server_name + " 442 " + sender._user_nick + " " + channel +
															 " :You’re not on that channel!";
	result = std::make_pair(sender._user_sock, no_msg + "\r\n");
	return (result);
}

event Message::msg_no_ch_error_403(const UserInfo &sender, const std::string &channel)
{
	event result;
	std::string no_msg;

	 
	if (channel == "#")
	{
		no_msg = ":" + Message::_server_name + " 403 " + sender._user_nick + " " +
						 channel + " " + ":No such const user in every channel";
	}
	else
	{
		no_msg = ":" + Message::_server_name + " 403 " + sender._user_nick + " " +
						 channel + " " + ":No such channel";
	}
	result = std::make_pair(sender._user_sock, no_msg + "\r\n");
	return (result);
}

event Message::msg_no_user_error_401(const UserInfo &sender, const std::string &target)
{
	event result;

	const std::string &no_msg = ":" + Message::_server_name + " 401 " + sender._user_nick + " " +
															target + " " + ":No such const user";
	result = std::make_pair(sender._user_sock, no_msg + "\r\n");
	return (result);
}

event Message::msg_mode(const UserInfo &sender, const UserInfo &receiver, const std::string &channel, const std::string &mode_type)
{
	event result;

	const std::string &msg_join = ":" + sender._user_nick + "!" + sender._user_name + "@127.0.0.1 MODE " + channel + " :" + mode_type;
	result = make_pair(receiver._user_sock, msg_join + "\r\n");
	return result;
}

event Message::msg_mode_not_op_482(const UserInfo &sender, const std::string &channel)
{
	event result;

	const std::string &msg_join = ":" + Message::_server_name + " 482 " + sender._user_nick + " " + channel + " " + "You're not channel operator";
	result = make_pair(sender._user_sock, msg_join + "\r\n");
	return result;
}

event Message::msg_mode_exceeded_arg_error_461(const uintptr_t &sock, const std::string &command)
{
	event result;

	const std::string &error_message = ":" + Message::_server_name + " 461 * " + command + " : too many parameters";
	result = std::make_pair(sock, error_message + "\r\n");
	return result;
}

event Message::msg_wrong_mode_option_error_472(const uintptr_t &socket, const char &mode_option)
{
	event result;

	const std::string &error_message = ":" + Message::_server_name + " 472 " + mode_option + " :is not a recognized channel mode.";
	result = std::make_pair(socket, error_message + "\r\n");
	return result;
}

event Message::msg_mode_invalid_target_error_401(const UserInfo &sender, const std::string &target)
{
	event result;

	const std::string &no_msg = ":" + Message::_server_name + " 401 " + sender._user_nick + " " +
															target + " " + ":No such nick";
	result = std::make_pair(sender._user_sock, no_msg + "\r\n");
	return (result);
}

event Message::msg_mode_no_arg_error_696(const UserInfo &sender, const std::string &target, const std::string &mode_option, const std::string &description, const std::string &err_syntax)
{
	event result;

	const std::string &msg = ":" + Message::_server_name + " 696 " + sender._user_nick + " " +
													 target + " " + mode_option + " * :You must specify a parameter for the " + description + " mode. Syntax: <" + err_syntax + ">.";
	result = std::make_pair(sender._user_sock, msg + "\r\n");
	return (result);
}

event Message::msg_mode_l_invalid_arg_error_696(const UserInfo &sender, const std::string &target, const std::string &mode_option, const std::string &mode_param)
{
	event result;

	const std::string &msg = ":" + Message::_server_name + " 696 " + sender._user_nick + " " +
													 target + " " + mode_option + " " + mode_param + " :Invalid limit mode parameter. Syntax: <limit>.";
	result = std::make_pair(sender._user_sock, msg + "\r\n");
	return (result);
}

event Message::msg_already_in_ch_error_443(const UserInfo &target_user, const std::string &channel)
{
	event result;

	const std::string &error_message = ":" + Message::_server_name + " 443 " + target_user._user_nick + " " + channel + " :is already on channel";
	result = std::make_pair(target_user._user_sock, error_message + "\r\n");
	return result;
}

event Message::msg_invite_to_users(const UserInfo &invitor, const UserInfo &invited_user, const std::string &channel)
{
	event result;

	const std::string &msg_invite_to_users = ":" + invitor._user_nick + "!" + invitor._user_name + "@127.0.0.1 INVITE " + invited_user._user_nick + " :" + channel;
	result = std::make_pair(invited_user._user_sock, msg_invite_to_users + "\r\n");
	return result;
}

event Message::msg_invite_invalid_user_error(const UserInfo &invitor, const std::string &invited_user)
{
	event result;

	const std::string &error_message = ":" + invited_user + " No such nick ";
	result = std::make_pair(invitor._user_sock, error_message + "\r\n");
	return result;
}

event Message::msg_invite_to_target_user(const UserInfo &invitor, const UserInfo &invited_user, const std::string &channel)
{
	event result;

	const std::string &inviting_message = ":" + _server_name + " 341 " + invitor._user_nick + " " + invited_user._user_nick + " " + ":" + channel;
	result = std::make_pair(invitor._user_sock, inviting_message + "\r\n");
	return result;
}

event Message::msg_invite_to_outsider(const UserInfo &sender, const UserInfo &receiver, const std::string &channel)
{
	event result;

	const std::string &inviting_message = ":" + _server_name + " NOTICE " + channel + " :*** " + sender._user_nick + " invited " + receiver._user_nick + " into the channel ";
	result = std::make_pair(receiver._user_sock, inviting_message + "\r\n");
	return result;
}

event Message::msg_join_no_invitation_error_473(const UserInfo &receiver, const std::string &channel)
{
	event result;

	const std::string &inviting_message = ":" + _server_name + " 473 " + receiver._user_nick + " " + channel + " :Cannot join channel (invite only)";
	result = std::make_pair(receiver._user_sock, inviting_message + "\r\n");
	return result;
}

event Message::msg_join_key_error_475(const UserInfo &receiver, const std::string &channel)
{
	event result;

	const std::string &key_error_message = ":" + _server_name + " 475 " + receiver._user_nick + " " + channel + " :Cannot join channel (incorrect channel key)";
	result = std::make_pair(receiver._user_sock, key_error_message + "\r\n");
	return result;
}

event Message::msg_join_full_limit_error_471(const UserInfo &receiver, const std::string &channel)
{
	event result;

	const std::string &key_error_message = ":" + _server_name + " 471  " + receiver._user_nick + " " + channel + " :Cannot join channel (channel is full)";
	result = std::make_pair(receiver._user_sock, key_error_message + "\r\n");
	return result;
}
