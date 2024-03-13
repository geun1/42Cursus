/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:41:54 by gsong             #+#    #+#             */
/*   Updated: 2023/04/11 17:16:32 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_space(int c)
{
	return (c == ' ' || (9 <= c && c <= 13));
}

static int	is_sign(int c)
{
	return (c == '-' || c == '+');
}

static int	is_digit(int c)
{
	return ('0' <= c && c <= '9');
}

int	arg_atoi(const char *str)
{
	int	num;

	num = 0;
	while (is_space(*str))
		++str;
	if (is_sign(*str))
	{
		if (*str == '-')
			return (ERROR);
		++str;
	}
	while (is_digit(*str))
		num = num * 10 + *str++ - '0';
	if (*str == '\0')
		return (num);
	else
		return (ERROR);
}
