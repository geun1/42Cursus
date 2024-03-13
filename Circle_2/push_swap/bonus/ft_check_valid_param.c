/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid_param.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 21:32:13 by gsong             #+#    #+#             */
/*   Updated: 2023/01/10 21:48:21 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_number(char	*number)
{
	int	check;

	check = 0;
	while ((9 <= *number && *number <= 13) || *number == ' ')
		number++;
	if (*number == '-' || *number == '+')
		number++;
	if (*number == '\0')
		return (FALSE);
	while (*number)
	{
		if (*number < '0' || *number > '9')
			return (FALSE);
		if (*number == '\"')
			return (FALSE);
		check++;
		number++;
	}
	if (check == 0)
		return (FALSE);
	return (TRUE);
}

int	is_int(long long number)
{
	if (number < -2147483648 || 2147483647 < number)
		return (FALSE);
	return (TRUE);
}

int	is_not_duplicate(int number, t_stack	*stack)
{
	stack->curr = stack->top->next;
	while (stack->curr->next)
	{
		if (stack->curr->value == number)
			return (FALSE);
		stack->curr = stack->curr->next;
	}
	return (TRUE);
}

void	ft_check_valid_param(char	*av, t_stack	*stack)
{
	char	**split_av;
	int		i;

	i = -1;
	split_av = ft_split(av, ' ');
	if (!split_av || !*split_av)
		ft_error();
	while (split_av[++i])
	{
		if (!is_number(split_av[i]))
			ft_error();
		if (!is_int(ft_atoi(split_av[i])))
			ft_error();
		if (!is_not_duplicate(ft_atoi(split_av[i]), stack))
			ft_error();
		push_bottom(stack, get_new_node(ft_atoi(split_av[i])));
	}
	ft_free(split_av, i);
}

void	check_sorting(t_stack *stack)
{
	int	check;
	int	num;

	check = 0;
	num = stack->num_of_data;
	stack->curr = stack->top->next;
	while (stack->curr->next->next)
	{
		if (stack->curr->value - stack->curr->next->value < 0)
			check++;
		stack->curr = stack->curr->next;
	}
	if (check == num - 1)
		exit(0);
}
