#include "ServerInfo.hpp"
#include "DefineColor.hpp"
#include <vector>

void ServerInfo::print_user_list(const std::vector<UserInfo> &vect_user)
{
  std::cout << COLOR_BOLDBLUE << "[ USER LIST ]  \n"
            << COLOR_RESET << std::endl;
  int j = 0;
  std::vector<UserInfo>::const_iterator i;
  for (i = vect_user.begin(); i != vect_user.end(); ++i, ++j)
  {
    const UserInfo &user = *i;
    std::cout << "  " << COLOR_BOLDBLUE << j + 1 << ") " << COLOR_RESET
              << COLOR_BOLDWHITE << user._user_nick << "(" << user._user_name << ", " << user._user_mode << ", " << user._user_unused << ", " << user._user_realname << ")" << COLOR_RESET << std::endl;
  }
  std::cout << std::endl;
}

void ServerInfo::print_receive_data(const uintptr_t &socket, const std::string &command)
{
  std::cout << COLOR_BOLDBLUE << "\n < RECEIVE > \n"
            << COLOR_RESET << std::endl
            << COLOR_BOLDWHITE << "  [ Socket ] :  " << socket << std::endl
            << "  [ Input ] :  " << command << COLOR_RESET << std::endl;
}
void ServerInfo::print_send_data(const uintptr_t &socket, const std::string &msg)

{
  std::cout << COLOR_BOLDBLUE << "\n < SEND > \n"
            << COLOR_RESET << std::endl
            << COLOR_BOLDWHITE << "  [ Socket ] :  " << socket << std::endl
            << "  [ Message ]  : " << msg << COLOR_RESET << std::endl;
}