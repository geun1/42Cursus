/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:46:38 by seokang           #+#    #+#             */
/*   Updated: 2022/07/25 14:43:20 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_blank(char a)
{
	if ((9 <= a && a <= 13) || a == 32)
		return (1);
	else
		return (0);
}

static int	ft_is_sign(char a, int *sign)
{
	if (a == '+')
		return (1);
	else if (a == '-')
	{
		*sign = -1;
		return (1);
	}
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] && ft_is_blank(str[i]))
		i++;
	if (str[i] && ft_is_sign(str[i], &sign))
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	result *= sign;
	return (result);
}
