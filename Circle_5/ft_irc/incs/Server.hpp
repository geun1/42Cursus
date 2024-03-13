#pragma once

#include "Delivery.hpp"

class Server
{
	private:
		events						_server_events;
		std::string					_password;
		uintptr_t					_port;
		static Delivery*			_reciever_ptr;

	public:
		static Server*				_server_ptr;
		Server(const std::string& port, const std::string& password);

		void	handle_sigint(void);
		void	server_start();
		events&	get_server_events(void);
};
