#pragma once

#include <cstring>
#include <unistd.h>

#include "Database.hpp"

class Delivery;

enum e_n_cmd
{N_CMD = 13};

class Parser
{
private:
	events &_parser_events;
	Database _database;
	const std::string &_password;

	static const std::string cmds[N_CMD];
	static void (Parser::*cmd_handler[N_CMD])(const uintptr_t &, std::stringstream &, std::string &);

	std::string resize_msg(const std::string &tmp, const std::string &send_string);
	void register_one_write_event(event &tmp);
	void register_multiple_write_events(events &tmp, const uintptr_t &ident, const int flag);


	void parse_cmd_pass(const uintptr_t &ident, std::stringstream &line_stream, std::string &send_string);
	void parse_cmd_nick(const uintptr_t &ident, std::stringstream &line_stream, std::string &send_string);
	void parse_cmd_user(const uintptr_t &ident, std::stringstream &line_stream, std::string &send_string);
	void parse_cmd_ping(const uintptr_t &ident, std::stringstream &line_stream, std::string &send_string);
	void parse_cmd_quit(const uintptr_t &ident, std::stringstream &line_stream, std::string &send_string);
	void parse_cmd_privmsg(const uintptr_t &ident, std::stringstream &line_stream, std::string &send_string);
	void parse_cmd_notice(const uintptr_t &ident, std::stringstream &line_stream, std::string &send_string);
	void parse_cmd_join(const uintptr_t &ident, std::stringstream &line_stream, std::string &send_string);
	void parse_cmd_mode(const uintptr_t &ident, std::stringstream &line_stream, std::string &send_string);
	void parse_cmd_invite(const uintptr_t &ident, std::stringstream &line_stream, std::string &send_string);
	void parse_cmd_part(const uintptr_t &ident, std::stringstream &line_stream, std::string &send_string);
	void parse_cmd_topic(const uintptr_t &ident, std::stringstream &line_stream, std::string &send_string);
	void parse_cmd_kick(const uintptr_t &ident, std::stringstream &line_stream, std::string &send_string);


	const std::string toupper_cmd(const char *command);

public:
	Parser(events &server_events, const std::string &password);

	void ready_to_end();
	void parse_cmd(const uintptr_t &ident, std::string &command);
	void delete_error_user(const uintptr_t &ident);
};