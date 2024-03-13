#pragma once

#include "Event.hpp"
#include "UserInfo.hpp"
#include "DefineColor.hpp"

class Message
{
public:
	static event msg_connection_001(const UserInfo &sender);

	static event msg_wrong_mode_option_error_472(const uintptr_t &ident, const char &mode_option);

	static event msg_pong(const uintptr_t &socket, const std::string &msg); 
	static event msg_wrong_ping_argument_error_409(const UserInfo &sender, const std::string &command);

	static event msg_not_registered_user_error_451(const UserInfo &sender, const std::string &command);
	static event msg_not_registered_user_error_451(const uintptr_t &sock, const std::string &command);

	static event msg_not_enough_arg_error_461(const UserInfo &sender, const std::string &command);
	static event msg_not_enough_arg_error_461(const uintptr_t &sock, const std::string &command);

	static event msg_user_error_302(const UserInfo &sender);

	static event msg_password_error_464(const uintptr_t &sock);

	static event msg_change_nick(const UserInfo &sender, const UserInfo &receiver, const std::string &new_nick);
	static event msg_already_nick_with_nick_error_432(const UserInfo &sender, const std::string &new_nick);
	static event msg_nick_error_433(const UserInfo &sender, const std::string &new_nick); 
	static event msg_already_nick_without_nick_error_433(const uintptr_t &sock, const std::string &new_nick);
	static event msg_nick_error_432(const UserInfo &sender, const std::string &new_nick);
	static event msg_nick_error_432(const uintptr_t &sock, const std::string &new_nick);
	
	static event msg_quit(const UserInfo &sender, std::string leave_message);
	static event msg_quit_to_remain(const UserInfo &sender, const UserInfo &receiver, std::string leave_message);

	static event msg_privmsg_to_bot(const UserInfo &sender, const std::string &msg);
	static event msg_privmsg_to_user(const UserInfo &sender, const UserInfo &target, const std::string &msg);
	static event msg_privmsg_to_ch_users(const UserInfo &sender, const UserInfo &receiver, const std::string &channel, const std::string &msg);
	static event msg_privmsg_to_nothing_error_401(const UserInfo &sender, const std::string &target);

	static event msg_join(const UserInfo &sender, const UserInfo &receiver, const std::string &channel);
	static event msg_join_invalid_ch_name_error_476(const UserInfo &sender, const std::string invaild_channel);
	static event msg_join_no_invitation_error_473(const UserInfo &receiver, const std::string &channel);
	static event msg_join_key_error_475(const UserInfo &receiver, const std::string &channel);
	static event msg_join_full_limit_error_471(const UserInfo &receiver, const std::string &channel);
	static std::string msg_join_353(const UserInfo &sender, const std::string &ch_name, const std::string &ch_user_result);
	static std::string msg_join_366(const UserInfo &sender, const std::string &ch_name);

	static event msg_part(const UserInfo &sender, const UserInfo &receiver, const std::string &channel, const std::string &msg);

	static event msg_kick(const UserInfo &sender, const UserInfo &receiver, const std::string &subject, const std::string &channel, const std::string &msg);
	static event msg_kick_not_op_error_482(const UserInfo &sender, const std::string &host, const std::string &channel);
	static event msg_kick_no_user_error_441(const UserInfo &sender, const std::string &host, const std::string &target, const std::string &channel);

	static event msg_topic(const UserInfo &sender, const UserInfo &receiver, const std::string &channel, const std::string &topic);
	static event msg_topic_authentication_error_482(const UserInfo &sender, const std::string &channel);
	static event msg_show_topic_332(const UserInfo &sender, const std::string &channel_name, const std::string &channel_topic);

	static event msg_notice_to_user(const UserInfo &sender, const UserInfo &target, const std::string &msg);
	static event msg_notice_to_ch_users(const UserInfo &sender, const UserInfo &receiver, const std::string &channel, const std::string &msg);
	static event msg_notice_no_nick_error_401(const UserInfo &sender, const UserInfo &receiver);

	static event msg_no_ch_error_403(const UserInfo &sender, const std::string &channel);
	static event msg_not_in_ch_error_442(const UserInfo &sender, const std::string &channel);

	static event msg_no_user_error_401(const UserInfo &sender, const std::string &target);

	static event msg_mode_not_op_482(const UserInfo &sender, const std::string &channel);
	static event msg_mode_exceeded_arg_error_461(const uintptr_t &sock, const std::string &command);
	static event msg_mode_invalid_target_error_401(const UserInfo &sender, const std::string &target);
	static event msg_mode_no_arg_error_696(const UserInfo &sender, const std::string &target, const std::string &mode_option, const std::string &description, const std::string &err_syntax);
	static event msg_mode_l_invalid_arg_error_696(const UserInfo &sender, const std::string &target, const std::string &mode_option, const std::string &mode_param);
	static event msg_mode(const UserInfo &sender, const UserInfo &receiver, const std::string &channel, const std::string &mode_type);

	static event msg_already_in_ch_error_443(const UserInfo &target_user, const std::string &channel);
	static event msg_invite_to_users(const UserInfo &sender, const UserInfo &receiver, const std::string &channel);
	static event msg_invite_to_outsider(const UserInfo &sender, const UserInfo &receiver, const std::string &channel);
	static event msg_invite_invalid_user_error(const UserInfo &sender, const std::string &target_user);
	static event msg_invite_to_target_user(const UserInfo &invitor, const UserInfo &target_user, const std::string &channel);


private:
	static const std::string _server_name;
};
