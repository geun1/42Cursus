#include "UserInfo.hpp"

UserInfo::UserInfo(void)
{
	bzero(this, sizeof(*this));
}

void UserInfo::input_user(const std::string &username, const std::string &mode, const std::string &unused, const std::string &realname)
{
	_user_name = username;
	_user_mode = mode;
	_user_unused = unused;
	_user_realname = realname;
}
