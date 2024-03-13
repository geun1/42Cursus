/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:51:15 by gsong             #+#    #+#             */
/*   Updated: 2022/12/20 16:24:19 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push_top(t_stack	*stack, t_node	*new_node)
{
	new_node->next = stack->top->next;
	stack->top->next->prev = new_node;
	new_node->prev = stack->top;
	stack->top->next = new_node;
	(stack->num_of_data)++;
}

void	push_bottom(t_stack *stack, t_node *new_node)
{
	new_node->prev = stack->bottom->prev;
	stack->bottom->prev->next = new_node;
	new_node->next = stack->bottom;
	stack->bottom->prev = new_node;
	(stack->num_of_data)++;
}

t_node	*pop_top(t_stack *stack)
{
	t_node	*temp;

	temp = stack->top->next;
	if (temp)
	{
		stack->top->next = temp->next;
		temp->next->prev = stack->top;
		(stack->num_of_data)--;
		return (temp);
	}
	else
		return ((void *)0);
}

t_node	*pop_bottom(t_stack *stack)
{
	t_node	*temp;

	temp = stack->bottom->prev;
	if (temp)
	{
		stack->bottom->prev = temp->prev;
		temp->prev->next = stack->bottom;
		(stack->num_of_data)--;
		return (temp);
	}
	else
		return ((void *)0);
}
