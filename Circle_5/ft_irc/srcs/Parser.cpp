#include "Parser.hpp"
#include "Delivery.hpp"
#include "Event.hpp"
#include "DefineColor.hpp"
#include "Database.hpp"
#include "ServerInfo.hpp"

#include <sstream>
#include <string>
#include <sys/_types/_size_t.h>
#include <iostream>

const std::string Parser::cmds[N_CMD] = {"PASS", "NICK", "USER", "PING", "JOIN", "QUIT", "PRIVMSG", "KICK", "PART", "TOPIC", "NOTICE", "MODE", "INVITE"};
void (Parser::*Parser::cmd_handler[N_CMD])(const uintptr_t &, std::stringstream &, std::string &) =
		{&Parser::parse_cmd_pass, &Parser::parse_cmd_nick, &Parser::parse_cmd_user, &Parser::parse_cmd_ping, &Parser::parse_cmd_join, &Parser::parse_cmd_quit, &Parser::parse_cmd_privmsg,
		 &Parser::parse_cmd_kick, &Parser::parse_cmd_part, &Parser::parse_cmd_topic, &Parser::parse_cmd_notice, &Parser::parse_cmd_mode, &Parser::parse_cmd_invite};

const std::string Parser::toupper_cmd(const char *command)
{
	std::string result;

	for (std::size_t i(0); i < std::strlen(command); ++i)
	{
		result += std::toupper(static_cast<int>(command[i]));
	}
	return result;
}

Parser::Parser(events &server_events, const std::string &password)
		: _parser_events(server_events), _password(password)
{
	_database.make_bot("BOT");
}

void Parser::ready_to_end()
{
	events to_delete;

	to_delete.clear();
	for (std::vector<UserInfo>::iterator i = _database.get_user_vector().begin(); i != _database.get_user_vector().end(); ++i)
	{
		if (i->_user_sock == 0)
			continue;
		event tmp = Message::msg_quit(*i, "");
		Delivery::get_kqueue().register_exit_event(i->_user_sock);
	}
}

void Parser::delete_error_user(const uintptr_t &ident)
{
	_database.delete_invalid_user(ident);
}

std::string Parser::resize_msg(const std::string &tmp, const std::string &send_string)
{
	std::string result;

	if (tmp.size() && tmp.at(0) == ':')
		result = send_string;
	else
		result = tmp;
	(result.size() > 510) ? result.resize(510) : result.resize(result.size());
	return result;
}

void Parser::parse_cmd(const uintptr_t &ident, std::string &command)
{
	std::stringstream ss(command);
	std::string line;

	while (std::getline(ss, line, '\n'))
	{
		std::stringstream line_stream(line);
		std::string command_type;
		std::size_t i(0);

		line_stream >> command_type;

		command_type = toupper_cmd(command_type.c_str());
		for (; i < N_CMD && (command_type != Parser::cmds[i]); ++i)
		{
		}
		if (i < N_CMD)
		{
			std::size_t pos;
			if ((i == 3) && (line.find(':') != std::string::npos))
			{ 
				pos = line.find(':') - 1;
			}
			else
			{
				pos = line.find(':');
			}
			std::string send_string;
			if (pos == std::string::npos)
			{
				send_string.clear();
			}
			else
			{
				send_string = line.substr(pos + 1, line.length() - (pos + 1));
			}			 
			(this->*Parser::cmd_handler[i])(ident, line_stream, send_string);
		}
		else
		{
			event tmp;
			tmp.first = ident;
			register_one_write_event(tmp);
		}
	}
}

int check_mode_err_type(t_mode &mode)
{
	if (mode.target.length() == 0 || mode.option.length() == 0)
		return CMD_EMPTY;
	else if (mode.option.length() == 2 && (mode.option.at(1) == 'i' || mode.option.at(1) == 't') && mode.param.length() > 0)
	{
		return CMD_TOO_MANY;
	}
	else if (mode.mode_type == MODE_TYPE_ERR)
	{
		return WRONG_MSG;
	}
	return -1;
}

void set_mode_input_type(t_mode &mode)
{
	mode.mode_type = MODE_TYPE_ERR;
	if (mode.option.length() != 2)
		return;

	char sign = mode.option.at(0);
	char option = mode.option.at(1);

	if (sign == '+')
	{
		if (option == 'i')
			mode.mode_type = I_PLUS;
		if (option == 't')
			mode.mode_type = T_PLUS;
		if (option == 'l')
			mode.mode_type = L_PLUS;
		if (option == 'o')
			mode.mode_type = O_PLUS;
		if (option == 'k')
			mode.mode_type = K_PLUS;
	}
	else if (sign == '-')
	{
		if (option == 'i')
			mode.mode_type = I_MINUS;
		if (option == 't')
			mode.mode_type = T_MINUS;
		if (option == 'l')
			mode.mode_type = L_MINUS;
		if (option == 'o')
			mode.mode_type = O_MINUS;
		if (option == 'k')
			mode.mode_type = K_MINUS;
	}
	return;
}

void set_mode_input(t_mode &mode, std::stringstream &line)
{
	line >> mode.target >> mode.option >> mode.param;
	set_mode_input_type(mode);
}

char get_wrong_mode_option(std::string wrong_mode)
{
	if (wrong_mode.length() < 2)
		return ' ';
	else
		return wrong_mode.at(1);
}

void Parser::parse_cmd_mode(const uintptr_t &ident, std::stringstream &line_stream, std::string &send_string)
{
	static_cast<void>(send_string);
	t_mode mode;
	events result;
	event tmp;

	set_mode_input(mode, line_stream);
	switch (check_mode_err_type(mode))
	{
	case CMD_EMPTY:
		tmp = Message::msg_not_enough_arg_error_461(ident, "MODE");
		result.insert(tmp);
		break;
	case CMD_TOO_MANY:
		tmp = Message::msg_mode_exceeded_arg_error_461(ident, "MODE");
		result.insert(tmp);
		break;
	case WRONG_MSG:
		tmp = Message::msg_wrong_mode_option_error_472(ident, get_wrong_mode_option(mode.option));
		result.insert(tmp);
		break;
	default:
		result = _database.execute_cmd_mode(ident, mode);
	}

	register_multiple_write_events(result, ident, 0);
}

void Parser::parse_cmd_invite(const uintptr_t &ident, std::stringstream &line_stream, std::string &send_string)
{
	static_cast<void>(send_string);
	std::string channel;
	std::string user;
	events result;

	line_stream >> user;
	line_stream >> channel;
	if (user.empty() || channel.empty())
	{
		event tmp = Message::msg_not_enough_arg_error_461(ident, "INVITE");
		result.insert(tmp);
	}
	else if (line_stream.rdbuf()->in_avail() != 0)
	{
		event tmp = Message::msg_mode_exceeded_arg_error_461(ident, "INVITE");
		result.insert(tmp);
	}
	else
	{
		result = _database.execute_cmd_invite(ident, user, channel);
	}
	register_multiple_write_events(result, ident, 0);
}

void Parser::parse_cmd_pass(const uintptr_t &ident, std::stringstream &line_stream, std::string &send_string)
{
	static_cast<void>(send_string);
	std::string pw;
	event result;

	line_stream >> pw;

	result.first = ident;
	if (pw.empty())
	{
		result = Message::msg_not_enough_arg_error_461(ident, "PASS");
		register_one_write_event(result);
		return;
	}
	if (_password != pw)
	{
		result = Message::msg_password_error_464(ident);
	}
	else
	{
		result = _database.execute_cmd_pass(ident);
	}
	register_one_write_event(result);
}

void Parser::parse_cmd_nick(const uintptr_t &ident, std::stringstream &line_stream, std::string &send_string)
{
	static_cast<void>(send_string);
	std::string nick;
	events result;

	line_stream >> nick;
	if (nick.empty())
	{
		event tmp = Message::msg_not_enough_arg_error_461(ident, "NICK");
		register_one_write_event(tmp);
		return;
	}
	result = _database.execute_cmd_nick(ident, nick);
	register_multiple_write_events(result, ident, 0);
}

void Parser::parse_cmd_user(const uintptr_t &ident, std::stringstream &line_stream, std::string &real_name)
{
	events result;
	event tmp;
	std::string argument[3];
	std::string real;

	line_stream >> argument[0] >> argument[1] >> argument[2] >> real;
	for (std::size_t i(0); i < 3; ++i)
	{
		if (argument[i].empty() || (argument[i].size() && argument[i].at(0) == ':'))
		{
			tmp = Message::msg_not_enough_arg_error_461(ident, "USER");
			register_one_write_event(tmp);
			return;
		}
	}
	real = resize_msg(real, real_name);
	if (real.empty())
	{
		tmp = Message::msg_not_enough_arg_error_461(ident, "USER");
		register_one_write_event(tmp);
		return;
	}
	tmp = _database.execute_cmd_user(ident, argument[0], argument[1], argument[2], real);
	result.insert(tmp);
	register_multiple_write_events(result, ident, 0);
}

void Parser::parse_cmd_ping(const uintptr_t &ident, std::stringstream &line_stream, std::string &send_string)
{
	event result;
	std::string msg;

	line_stream >> msg;
	msg = resize_msg(msg, send_string);
	if (msg.empty())
	{
		result = Message::msg_not_enough_arg_error_461(ident, "PING");
		register_one_write_event(result);
		return;
	}
	result = _database.execute_cmd_pong(ident, msg);
	register_one_write_event(result);
}

void Parser::parse_cmd_quit(const uintptr_t &ident, std::stringstream &line_stream, std::string &send_string)
{
	events result;
	std::string nick, tmp;

	while (line_stream >> tmp)
	{
		if (nick.size() && nick.at(0) != ':')
		{
			nick = tmp + " ";
		}
	}
	nick += send_string;
	result = _database.execute_cmd_quit(ident, send_string);
	register_multiple_write_events(result, ident, 1);
}

void Parser::parse_cmd_privmsg(const uintptr_t &ident, std::stringstream &line_stream, std::string &send_string)
{
	std::string target, msg;
	events result;

	line_stream >> target;
	line_stream >> std::ws;
	if (target.empty())
	{
		event tmp = Message::msg_not_enough_arg_error_461(ident, "PRIVMSG");
		result.insert(tmp);
	}
	else
	{
		std::getline(line_stream, msg);
		msg = resize_msg(msg, send_string);
		result = _database.execute_cmd_privmsg(ident, target, msg);
	}
	register_multiple_write_events(result, ident, 0);
}

void Parser::parse_cmd_notice(const uintptr_t &ident, std::stringstream &line_stream, std::string &send_string)
{
	std::string target, msg;
	events result;

	line_stream >> target;
	line_stream >> std::ws;
	if (target.empty())
	{
		event tmp = Message::msg_not_enough_arg_error_461(ident, "NOTICE");
		result.insert(tmp);
	}
	else
	{
		std::getline(line_stream, msg);
		msg = resize_msg(msg, send_string);
		result = _database.execute_cmd_notice(ident, target, msg);
	}
	register_multiple_write_events(result, ident, 0);
}

void Parser::parse_cmd_join(const uintptr_t &ident, std::stringstream &line_stream, std::string &send_string)
{
	static_cast<void>(send_string);
	std::string ch_name;
	std::string tmp_password;
	events result;

	line_stream >> ch_name >> tmp_password;
	result = _database.execute_cmd_join(ident, ch_name, tmp_password);
	register_multiple_write_events(result, ident, 2);
}

void Parser::parse_cmd_part(const uintptr_t &ident, std::stringstream &line_stream, std::string &send_string)
{
	events result;
	std::string ch_name, msg;

	line_stream >> ch_name;
	line_stream >> std::ws;
	std::getline(line_stream, msg);
	msg = resize_msg(msg, send_string); 
	UserInfo parter = _database.select_user(ident);
	result = _database.execute_cmd_part(ident, ch_name, msg);

	register_multiple_write_events(result, ident, 2);
}

void Parser::parse_cmd_topic(const uintptr_t &ident, std::stringstream &line_stream, std::string &send_string)
{
	events result;
	std::string ch_name, msg;

	line_stream >> ch_name;
	if (ch_name.empty())
	{
		event tmp = Message::msg_not_enough_arg_error_461(ident, "TOPIC");
		result.insert(tmp);
	}
	else
	{
		line_stream >> std::ws;
		std::getline(line_stream, msg);
		msg = resize_msg(msg, send_string);
		result = _database.set_ch_topic(ident, ch_name, msg);
	}
	register_multiple_write_events(result, ident, 2);
}

void Parser::parse_cmd_kick(const uintptr_t &ident, std::stringstream &line_stream, std::string &send_string)
{
	events result;
	event tmp;
	std::string ch_name, target_name, msg;

	line_stream >> ch_name >> target_name >> msg;
	if (ch_name.empty() || target_name.empty())
	{
		event tmp = Message::msg_not_enough_arg_error_461(ident, "KICK");
		result.insert(tmp);
	}
	else
	{
		line_stream >> std::ws;
		msg = resize_msg(msg, send_string);
		result = _database.execute_cmd_kick(ident, target_name, ch_name, msg);
	}
	register_multiple_write_events(result, ident, 2);
}

void Parser::register_one_write_event(event &result) 
{
	if (result.second.empty())
	{
		Delivery::get_kqueue().register_read_event(result.first);
		return;
	}
	_parser_events.insert(result);
	(Delivery::get_kqueue()).register_write_event(result.first);
}

void Parser::register_multiple_write_events(events &result, const uintptr_t &ident, const int flag)
{
	events_iter target = result.find(ident);

	if (result.empty())
	{
		Delivery::get_kqueue().register_read_event(ident);
		return;
	}
	if (target != result.end())
	{
		if (target->second.empty() && flag == 0)
		{
			Delivery::get_kqueue().register_read_event(ident);
		}
		else if (flag == 1)
		{
			_parser_events.insert(*target);
			Delivery::get_kqueue().register_exit_event(target->first);
		}
		else
		{
			_parser_events.insert(*target);
			Delivery::get_kqueue().register_write_event(target->first);
		}
	}
	for (events_iter iter = result.begin(); iter != result.end(); ++iter)
	{
		if (target != result.end() && iter->first == ident)
		{
			continue;
		}
		_parser_events.insert(*iter);
		(Delivery::get_kqueue()).register_write_event(iter->first);
	}
}
