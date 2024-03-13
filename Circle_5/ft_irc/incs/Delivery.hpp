#pragma once

#include <sys/socket.h>
#include <sys/event.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#include "Kevent.hpp"
#include "Parser.hpp"
#include "Event.hpp"

class Parser;

class Delivery
{
private:
	static Kevent _kqueue;
	bool sigint_flag;
	Parser _parser;
	events &_events;
	events _carriage_return_backup;
	sockaddr_in _server_sockaddr;
	uintptr_t _server_sock;

	int _switch_to_read_event(struct kevent &cur_event);
	int _switch_to_write_event(struct kevent &cur_event);
	void _initialize_server_socket(const uintptr_t &port);
	void _bind_server_socket();
	void _remove_carriage_return(std::string &to_remove);

public:
	Delivery(events &server_events, const uintptr_t &port, const std::string &password);

	void end_receiver();
	void main_loop();
	static Kevent &get_kqueue();
};
