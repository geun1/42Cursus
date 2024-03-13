#include "Server.hpp"

void exit_with_perror(const std::string &msg);

Server *Server::_server_ptr = NULL;
Delivery *Server::_reciever_ptr = NULL;

void Server::handle_sigint(void)
{
	_reciever_ptr->end_receiver();
}

static bool _port_checker(const std::string &str)
{
	if (str.empty())
	{
		return (true);
	}
	for (std::size_t i = 0; i < str.length(); ++i)
	{
		if (!std::isdigit(str.at(i)))
			return (true);
	}
	return (false);
}

static bool _pw_checker(const std::string &str)
{
	if (str.empty() || str.length() > 16)
	{
		return (true);
	}
	for (std::size_t i = 0; i < str.length(); ++i)
	{
		if (std::isspace(str.at(i)) || !std::isprint(str.at(i)))
		{
			return (true);
		}
	}
	return (false);
}


Server::Server(const std::string &port, const std::string &password)
{
	if (_port_checker(port) || _pw_checker(password))
	{
		exit_with_perror("input port invaild");
	}
	_port = static_cast<uintptr_t>(atoi(port.c_str()));
	if (_port > 65535)
	{
		exit_with_perror("Port number is out of range");
	}
	_password = password;
}

events &Server::get_server_events(void)
{
	return _server_events;
}

void Server::server_start()
{
	Delivery receiver(get_server_events(), _port, _password);
	Server::_reciever_ptr = &receiver;

	receiver.main_loop();
}
