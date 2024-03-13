/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:44:43 by gsong             #+#    #+#             */
/*   Updated: 2023/01/07 19:33:34 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra(t_stack	*stack_a)
{
	push_top(stack_a, pop_bottom(stack_a));
}

void	rrb(t_stack	*stack_b)
{
	push_top(stack_b, pop_bottom(stack_b));
}

void	rrr(t_stack	*stack_a, t_stack	*stack_b)
{
	push_top(stack_a, pop_bottom(stack_a));
	push_top(stack_b, pop_bottom(stack_b));
}

long long	ft_atoi(const char *str)
{
	int			sign;
	long long	res;

	sign = 1;
	res = 0;
	while ((9 <= *str && *str <= 13) || *str == 32)
		++str;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		++str;
	}
	while (*str && ('0' <= *str && *str <= '9'))
	{
		res = res * 10 + (*str - '0');
		++str;
	}
	res *= sign;
	return (res);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(FAILURE);
}
