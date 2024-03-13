/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 19:32:44 by gsong             #+#    #+#             */
/*   Updated: 2023/01/10 17:05:44 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	node->prev = ((void *)0);
	node->next = ((void *)0);
	return (node);
}

void	ft_free(char **split_av, int i)
{
	while (i--)
		free(split_av[i]);
	free(split_av);
}
