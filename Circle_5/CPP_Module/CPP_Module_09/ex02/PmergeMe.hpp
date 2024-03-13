#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <exception>
#include <cctype>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <deque>

struct timer
{
	clock_t	start;
	clock_t	v_time;
	clock_t	d_time;
};

void	checkErrors(int ac, char **av);
void	sort(int ac, char **av);

#endif