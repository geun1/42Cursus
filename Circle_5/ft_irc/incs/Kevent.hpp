#pragma once

#include "DefineColor.hpp"
#include <iostream>
#include <unistd.h>
#include <vector>
#include <sys/event.h>
#include <sys/time.h>

class Kevent
{
private:
	int _kqueue_return_fd;

	std::vector<struct kevent> _kevent_list;
	void generate_kevent(uintptr_t ident, int16_t filter, uint16_t flags, uint32_t fflags, int64_t data, void *udata);
public:
	Kevent();
	~Kevent();

	std::vector<struct kevent> set_event_checker(const bool &is_end_signal);
	void register_read_event(uintptr_t ident);
	void register_server_event(uintptr_t ident);
	void register_write_event(uintptr_t ident);
	void register_exit_event(uintptr_t ident);
	void remove_event(const struct kevent &k_event);
	void remove_server(uintptr_t serv_sock);
};
