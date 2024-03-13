#include "Kevent.hpp"

void exit_with_perror(const std::string &msg);

Kevent::Kevent()
{
	_kqueue_return_fd = kqueue();
	if (_kqueue_return_fd < 0)
	{
		exit_with_perror("Failed to create kqueue");
	}
}

Kevent::~Kevent()
{
	if (_kqueue_return_fd > 0)
	{
		close(_kqueue_return_fd);
	}
}

void Kevent::generate_kevent(uintptr_t ident, int16_t filter, uint16_t flags, uint32_t fflags, int64_t data, void *udata)
{
	struct kevent k_event = {};

	EV_SET(&k_event, ident, filter, flags, fflags, data, udata);
	_kevent_list.push_back(k_event);
}

std::vector<struct kevent> Kevent::set_event_checker(const bool &is_end_signal)
{
	std::vector<struct kevent> result;

	if (is_end_signal)
		return result;
	struct kevent event_list[10];
	int event_num(-1);

	while ((event_num < 0))
	{
		event_num = kevent(_kqueue_return_fd, &(_kevent_list[0]), (int)_kevent_list.size(), event_list, 10, NULL);
	}
	for (int i(0); i < event_num; ++i)
	{
		result.push_back(event_list[i]);
	}
	_kevent_list.clear();
	return (result);
}

void Kevent::register_server_event(uintptr_t ident)
{
	generate_kevent(ident, EVFILT_READ, EV_ADD, 0, 0, NULL);
}

void Kevent::register_read_event(uintptr_t ident)
{
	generate_kevent(ident, EVFILT_READ, EV_ADD | EV_ONESHOT, 0, 0, NULL);
}

void Kevent::register_write_event(uintptr_t ident)
{
	generate_kevent(ident, EVFILT_WRITE, EV_ADD, 0, 0, NULL);
}

void Kevent::register_exit_event(uintptr_t ident)
{
	char k(0);

	generate_kevent(ident, EVFILT_WRITE, EV_ADD, 0, 0, &k);
}

void Kevent::remove_event(const struct kevent &k_event)
{
	generate_kevent(k_event.ident, EVFILT_WRITE, EV_DELETE,0,0,0);
}

void Kevent::remove_server(uintptr_t serv_sock)
{
    generate_kevent(serv_sock, EVFILT_READ,EV_DELETE,0,0,0);
}