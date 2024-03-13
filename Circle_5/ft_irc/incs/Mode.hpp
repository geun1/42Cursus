#pragma once

enum e_mode_val { N_MODE_TYPE = 10};

typedef enum e_types
{
	I_PLUS,
	I_MINUS,
	T_PLUS,
	T_MINUS,
	L_PLUS,
	L_MINUS,
	O_PLUS,
	O_MINUS,
	K_PLUS,
	K_MINUS,
	MODE_TYPE_ERR
}	t_mode_type;

typedef enum e_err_type
{
	CMD_EMPTY,
	CMD_TOO_MANY,
	WRONG_MSG
}	t_err_type;


typedef struct s_mode
{
	t_mode_type mode_type;
	std::string target;
	std::string option;
	std::string param;
} t_mode;
