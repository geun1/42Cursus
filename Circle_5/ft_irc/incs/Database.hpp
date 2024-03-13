#pragma once

#include "Channel.hpp"
#include "Message.hpp"
#include "Event.hpp"

class Database
{
private:
	std::vector<Channel> _ch_vector;
	std::vector<UserInfo> _user_vector;

public:
	std::vector<UserInfo> &get_user_vector(void);
	event check_user_verification(const uintptr_t &ident, const std::string &command_type);

	events make_priv_msg(UserInfo &sender, std::string ch_name, const std::string &msg);
	events make_notice_msg(UserInfo &sender, std::string ch_name, const std::string &msg);
	bool check_valid_ch(std::string &ch_name);
	bool check_valid_user(UserInfo &leaver);
	Channel &create_ch(UserInfo &joiner, std::string &ch_name);
	void delete_ch(std::string &ch_name);
	Channel &select_ch(std::string &ch_name);
	Channel &select_ch(const std::string &ch_name);
	Channel &select_ch(UserInfo &connector);

	events set_ch_topic(const uintptr_t &ident, std::string &ch_name, std::string &topic);
	events kick_ch(UserInfo &host, UserInfo &target, std::string &ch_name, std::string &msg);
	events join_ch(UserInfo &joiner, const std::string &chan_name_, const std::string &tmp_password);
	events part_ch(UserInfo &leaver, std::string &ch_name, const std::string &msg_);
	events quit_ch(UserInfo &leaver, std::string &ch_name, const std::string &msg_);
	events nick_ch(UserInfo &nicker, std::string &send_msg);
	std::vector<Channel> &get_ch();

	void delete_invalid_user(const uintptr_t &ident);
	event execute_cmd_pass(const uintptr_t &ident);
	events execute_cmd_nick(const uintptr_t &ident, std::string &nick_name);
	event execute_cmd_user(const uintptr_t &ident, const std::string &username, const std::string &mode,
													const std::string &unused, const std::string &realname);
	event execute_cmd_pong(const uintptr_t &ident, std::string &msg);
	events execute_cmd_quit(const uintptr_t &ident, const std::string &ch_name);
	events execute_cmd_privmsg(const uintptr_t &ident, const std::string &target_name, const std::string &msg);
	events execute_cmd_notice(const uintptr_t &ident, const std::string &target_name, const std::string &msg);
	event execute_cmd_privmsg(std::string &target_name, std::string &line, const uintptr_t &ident);
	events execute_cmd_join(const uintptr_t &ident, const std::string &ch_name, const std::string &password);
	events execute_cmd_part(const uintptr_t &ident, std::string &ch_name, const std::string &msg);
	events execute_cmd_kick(const uintptr_t &ident, const std::string &target_name, std::string &ch_name, std::string &msg);
	events execute_cmd_mode(const uintptr_t &ident, t_mode &mode);
	events execute_cmd_invite(const uintptr_t &ident, std::string &user, std::string &ch_name);
	events execute_cmd_i_plus(const uintptr_t &ident, t_mode &mode);
	events execute_cmd_i_minus(const uintptr_t &ident, t_mode &mode);
	events execute_cmd_k_plus(const uintptr_t &ident, t_mode &mode);
	events execute_cmd_k_minus(const uintptr_t &ident, t_mode &mode);
	events execute_cmd_o_plus(const uintptr_t &ident, t_mode &mode);
	events execute_cmd_o_minus(const uintptr_t &ident, t_mode &mode);
	events execute_cmd_t_plus(const uintptr_t &ident, t_mode &mode);
	events execute_cmd_t_minus(const uintptr_t &ident, t_mode &mode);
	events execute_cmd_l_plus(const uintptr_t &ident, t_mode &mode);
	events execute_cmd_l_minus(const uintptr_t &ident, t_mode &mode);
	static events (Database::*mode_handlers[N_MODE_TYPE])(const uintptr_t &ident, t_mode &mode);

	bool check_user(const uintptr_t &ident);
	bool check_user(const std::string &nickname);
	UserInfo &select_user(const uintptr_t &ident);
	UserInfo &select_user(const std::string &nickname);
	void delete_user(UserInfo &leaver);
	bool check_nick(std::string &new_nick);

	event send_msg_to_bot(UserInfo &current_user, const std::string &msg);
	void make_bot(const std::string &name);
};
