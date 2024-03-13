#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <exception>
#include <cctype>
#include <stack>
#include <cstdlib>

struct	rpn_s {
	char	op;
	int	(*operate)(int nb1, int nb2);
};

bool	checkOperator(char c);
void	checkArgumentErrors(int ac, char *av, int i);
void	rpn(char *av, int i);

#endif