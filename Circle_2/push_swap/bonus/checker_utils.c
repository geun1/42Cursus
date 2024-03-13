/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:31:13 by gsong             #+#    #+#             */
/*   Updated: 2023/01/07 19:41:07 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	checker(t_stack *stack_a, t_stack *stack_b)
{
	int		idx;
	int		check;
	t_node	*a;

	idx = stack_a->num_of_data;
	a = stack_a->top->next;
	check = 0;
	while (idx > 1)
	{
		if (a->index - a->next->index < 0)
			check++;
		idx--;
		a = a->next;
	}
	if (check == stack_a->num_of_data - 1 && stack_b->num_of_data == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	operation(char *op, t_stack *stack_a, t_stack *stack_b)
{
	if (!ft_strcmp(op, "sa\n"))
		sa(stack_a);
	else if (!ft_strcmp(op, "sb\n"))
		sb(stack_b);
	else if (!ft_strcmp(op, "ss\n"))
		ss(stack_a, stack_b);
	else if (!ft_strcmp(op, "pa\n"))
		pa(stack_a, stack_b);
	else if (!ft_strcmp(op, "pb\n"))
		pb(stack_a, stack_b);
	else if (!ft_strcmp(op, "ra\n"))
		ra(stack_a);
	else if (!ft_strcmp(op, "rb\n"))
		rb(stack_b);
	else if (!ft_strcmp(op, "rr\n"))
		rr(stack_a, stack_b);
	else if (!ft_strcmp(op, "rra\n"))
		rra(stack_a);
	else if (!ft_strcmp(op, "rrb\n"))
		rrb(stack_b);
	else if (!ft_strcmp(op, "rrr\n"))
		rrr(stack_a, stack_b);
	else
		ft_error();
}

void	operating(t_stack *stack_a, t_stack *stack_b)
{
	char	*op;

	while (1)
	{
		op = get_next_line(0);
		if (!op)
			break ;
		operation(op, stack_a, stack_b);
		free(op);
	}
}
