#pragma once

#include <iostream>

enum e_flags { F_PASS = 0b100, F_NICK = 0b010, F_USER = 0b001};

struct UserInfo
{
	std::string	_user_nick;
	std::string _user_name;
	std::string _user_mode;
	std::string _user_unused;
	std::string _user_realname;
	char		_user_flag;
	uintptr_t	_user_sock;

	UserInfo(void);
	void	input_user(const std::string& username, const std::string& mode
						, const std::string& unused, const std::string& realname);
	bool	operator==(const UserInfo& obj) const { return this->_user_sock == obj._user_sock; };
	bool	operator!=(const UserInfo& obj) const { return this->_user_sock != obj._user_sock; };
	bool	operator>(const UserInfo& obj) const { return this->_user_sock > obj._user_sock; };
	bool	operator<(const UserInfo& obj) const { return this->_user_sock < obj._user_sock; };
};
