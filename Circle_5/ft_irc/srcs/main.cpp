#include "Server.hpp"
#include <signal.h>

static void _sigint_handler(int signum)
{
	if (signum == SIGINT)
	{
		std::cout << COLOR_BOLDBLUE << "Server Closed" << COLOR_RESET << std::endl;
		Server::_server_ptr->handle_sigint();
		exit(0);
	}
}

int main(int argc, char **argv)
{
	signal(SIGINT, _sigint_handler);
	system("clear");
	if (argc != 3)
	{
		std::cerr << COLOR_RED << "err: Wrong Arguments" << COLOR_RESET << std::endl;
		exit(EXIT_FAILURE);
	}
	std::string port(argv[1]);
	std::string password(argv[2]);
	Server server(port, password);
	Server::_server_ptr = &server;
	server.server_start();
}
