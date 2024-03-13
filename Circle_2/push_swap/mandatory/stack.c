/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 19:32:44 by gsong             #+#    #+#             */
/*   Updated: 2022/12/12 15:20:47 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack)
{
	stack->top = get_new_node(0);
	stack->bottom = get_new_node(0);
	stack->top->next = stack->bottom;
	stack->bottom->prev = stack->top;
	stack->num_of_data = 0;
}

t_node	*get_new_node(int num)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		ft_error();
	node->value = num;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}
