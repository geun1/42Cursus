#include "Delivery.hpp"
#include "Database.hpp"
#include "Event.hpp"
#include "DefineColor.hpp"
#include "ServerInfo.hpp"
#include <atomic>
#include <string>
#include <sys/_types/_uintptr_t.h>
#include <fcntl.h>

void exit_with_perror(const std::string &msg);

Kevent Delivery::_kqueue = Kevent();

Kevent &Delivery::get_kqueue(void)
{
	return _kqueue;
}

Delivery::Delivery(events &server_events, const uintptr_t &port, const std::string &password)
		: _parser(server_events, password), _events(server_events)
{
	sigint_flag = false;
	_initialize_server_socket(port);
	_bind_server_socket();
}

void Delivery::end_receiver(void)
{
	sigint_flag = true;
	_parser.ready_to_end();
}

void Delivery::_initialize_server_socket(const uintptr_t &port)
{
	_server_sock = socket(AF_INET, SOCK_STREAM, 0);
	if (_server_sock < 0)
	{
		exit_with_perror("err: Socket Creating Fail");
	}
	_server_sockaddr.sin_family = AF_INET;
	_server_sockaddr.sin_port = htons(port);
	_server_sockaddr.sin_addr.s_addr = INADDR_ANY;
}

void Delivery::_bind_server_socket()
{
	int optval = 1;
	setsockopt(_server_sock, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof optval);
	if (bind(_server_sock, (sockaddr *)&_server_sockaddr, sizeof(_server_sockaddr)) < 0)
	{
		exit_with_perror("err: Socket Binding Fail");
	}
	fcntl(_server_sock, F_SETFL, O_NONBLOCK);
	if (listen(_server_sock, 5) < 0)
	{
		std::cerr << "error" << std::endl;
	}
	_kqueue.register_server_event(_server_sock);
}

void Delivery::main_loop()
{
	while (true)
	{
		std::vector<struct kevent> k_events = _kqueue.set_event_checker(false);
		for (std::size_t i(0); i < k_events.size(); ++i)
		{
			struct kevent cur_event = k_events[i];
			if (cur_event.ident == _server_sock)
			{
				uintptr_t user_sock = accept(_server_sock, NULL, NULL);
				if (user_sock < 0)
				{
					std::cerr << "err: accepting connection fail" << std::endl;
					continue;
				}
				fcntl(user_sock, F_SETFL, O_NONBLOCK);
				_kqueue.register_read_event(user_sock);
				
			}
			else
			{
				if (cur_event.filter == EVFILT_READ)
				{
					if (_switch_to_read_event(cur_event))
					{
						continue;
					}
				}
				else if (cur_event.filter == EVFILT_WRITE)
				{
					if (_switch_to_write_event(cur_event))
					{
						if (sigint_flag == true && i == k_events.size() - 1)
						{
							close(_server_sock);
							_kqueue.remove_server(_server_sock);
						}
						continue;
					}
					uintptr_t tmp_fd = cur_event.ident;
					_kqueue.remove_event(cur_event);
					_kqueue.register_read_event(tmp_fd);
				}
			}
		}
	}
}

void Delivery::_remove_carriage_return(std::string &to_remove)
{
	std::size_t carriage_pos = to_remove.find('\r');
	while (carriage_pos != std::string::npos)
	{
		to_remove.erase(carriage_pos, 1);
		carriage_pos = to_remove.find('\r');
	}
}

int Delivery::_switch_to_read_event(struct kevent &cur_event)
{
	char buffer[1024];

	memset(buffer, 0, sizeof(buffer));
	if (cur_event.flags & EV_EOF)
	{
		uintptr_t tmp_sock(cur_event.ident);

		events_iter cur_backup = _carriage_return_backup.find(cur_event.ident);
		if (cur_backup != _carriage_return_backup.end())
		{
			_carriage_return_backup.erase(cur_backup);
		}
		_kqueue.remove_event(cur_event);
		_parser.delete_error_user(tmp_sock);
		return (1);
	}
	int byte_received = recv(cur_event.ident, buffer, sizeof(buffer), 0);
	if (byte_received < 0)
	{
		std::cerr << COLOR_RED << "err: receiving data" << COLOR_RESET << std::endl;
		return (1);
	}
	std::string command(buffer, byte_received);
	std::size_t newline_pos = command.find('\n');

	_remove_carriage_return(command);

	if (newline_pos == std::string::npos)
	{
		events_iter cur_backup = _carriage_return_backup.find(cur_event.ident);

		if (cur_backup == _carriage_return_backup.end())
		{
			event tmp;
			tmp.first = cur_event.ident;
			tmp.second = command;
			_carriage_return_backup.insert(tmp);
		}
		else
		{
			cur_backup->second += command;
		}
		_kqueue.register_read_event(cur_event.ident);
	}

	else
	{

		events_iter cur_backup = _carriage_return_backup.find(cur_event.ident);
		if (cur_backup != _carriage_return_backup.end())
		{
			command.insert(0, cur_backup->second);	
			_carriage_return_backup.erase(cur_backup);
		}
		ServerInfo::print_receive_data(cur_event.ident, command);
		_parser.parse_cmd(cur_event.ident, command);
	}
	return (0);
}

int Delivery::_switch_to_write_event(struct kevent &cur_event)
{
	events_iter target = _events.find(cur_event.ident);
	if (target == _events.end())
		return(1);
	ServerInfo::print_send_data(target->first, target->second);
	
	if (cur_event.flags == EV_DELETE)
	{
		close(cur_event.ident);
		_events.erase(target);
		return (1);
	}
	int send_bytes = send(cur_event.ident, target->second.c_str(), target->second.size(), 0);
	if (send_bytes < 0)
	{
		std::cerr << COLOR_RED << "err: sending data" << COLOR_RESET << std::endl;
		return (1);
	}
	if (cur_event.udata)
	{
		_kqueue.remove_event(cur_event);
		close(cur_event.ident);
		_events.erase(target);
		return (1);
	}
	_events.erase(target);
	return (0);
}
