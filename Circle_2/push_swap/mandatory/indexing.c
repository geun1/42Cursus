/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:24:40 by gsong             #+#    #+#             */
/*   Updated: 2023/01/10 23:03:13 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing2(t_stack	*stack, int min)
{
	int		next_min;
	int		index;

	next_min = 2147483647;
	index = 1;
	while (++index <= stack->num_of_data)
	{
		stack->curr = stack->top->next;
		while (stack->curr->next)
		{
			if (min < stack->curr->value && stack->curr->value < next_min)
				next_min = stack->curr->value;
			stack->curr = stack->curr->next;
		}
		stack->curr = stack->top->next;
		while (stack->curr->next)
		{
			if (next_min == stack->curr->value)
				stack->curr->index = index;
			stack->curr = stack->curr->next;
		}
		min = next_min;
		next_min = 2147483647;
	}
}

void	indexing(t_stack	*stack)
{
	int	min;

	stack->curr = stack->top->next;
	min = 2147483647;
	while (stack->curr->next)
	{
		if (min > stack->curr->value)
		{
			min = stack->curr->value;
			stack->curr->index = 1;
		}
		stack->curr = stack->curr->next;
	}
	indexing2(stack, min);
}
