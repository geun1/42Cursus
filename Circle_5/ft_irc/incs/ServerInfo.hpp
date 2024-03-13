#pragma once

#include "UserInfo.hpp"

class ServerInfo
{
public:
	static void print_user_list(const std::vector<UserInfo> &vect_user);
	static void print_receive_data(const uintptr_t &socket, const std::string &command);
	static void print_send_data(const uintptr_t &socket, const std::string &msg);
};
