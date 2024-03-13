#include <string>
#include <iostream>
#include "DefineColor.hpp"

void exit_with_perror(const std::string& msg)
{
	std::cerr << COLOR_BOLDRED << msg << COLOR_RESET << std::endl;
	exit(EXIT_FAILURE);
}
