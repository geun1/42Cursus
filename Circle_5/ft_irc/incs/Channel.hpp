#pragma once

#include "Message.hpp"
#include "Event.hpp"
#include "Mode.hpp"

#include <vector>
#include <algorithm>
#include <sstream>

enum enum_command
{
	JOIN,
	PART,
	PRIV,
	KICK,
	QUIT,
	NOTICE,
	TOPIC,
	NICK,
	MODE,
	INVITE
};

enum enum_c_flag
{
	F_INVITE_ONLY = 0b0001,
	F_KEY_NEEDED = 0b0010,
	F_LIMITED_MEMBERSHIP = 0b0100,
	F_TOPIC_OWNERSHIP = 0b1000
};

class Channel
{
private:
	std::vector<UserInfo> _user_info;
	std::vector<uintptr_t> _host_address;
	std::vector<uintptr_t> _invitations_address;
	std::string _ch_name;
	std::string _ch_topic;
	std::string _ch_key;
	int _num_limit;

public:
	char _ch_flag;

	Channel();
	std::vector<uintptr_t> &get_host_address(void);
	void set_host_address(uintptr_t host_sock);
	void set_host_address(UserInfo &user);
	void clear_host_address(uintptr_t host_sock);
	void clear_host_address(UserInfo &host_user);
	bool check_host_address(uintptr_t user_sock);
	bool check_host_address(UserInfo &user);

	std::string &get_ch_name(void);
	std::string &get_ch_topic(void);
	void set_ch_topic(std::string &topic);
	bool check_ch_user(UserInfo &usr);
	void set_ch_flag(Channel &channel, t_mode &mode);
	void set_ch_name(std::string &ch_name);
	void set_ch_key(Channel &tmp_channel, t_mode mode);

	int get_limit_num(void);
	void set_limit_num(int &member_limit);
	void update_nick(UserInfo &usr, std::string new_nick);
	void append_joiner(UserInfo &joiner);
	void banish_user(UserInfo &usr);
	void append_invitation(uintptr_t user_sock);

	std::string get_user_result(void);
	bool check_invitation(const uintptr_t &usr);
	bool check_ch_key(Channel &tmp_channel, const std::string &tmp_password);
	events send_msg_packet(UserInfo &sender, UserInfo &target, std::string msg, int remocon);

	std::vector<UserInfo> &get_user_info(void);
	std::vector<UserInfo> sort_user_by_client_socks(void);
	bool operator==(const Channel &t) const;
};
