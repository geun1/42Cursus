/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:28:07 by gsong             #+#    #+#             */
/*   Updated: 2023/01/07 19:33:15 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_stack	*stack_a)
{
	t_node	*temp1;
	t_node	*temp2;

	temp1 = pop_top(stack_a);
	temp2 = pop_top(stack_a);
	push_top(stack_a, temp1);
	push_top(stack_a, temp2);
}

void	sb(t_stack	*stack_b)
{
	t_node	*temp1;
	t_node	*temp2;

	temp1 = pop_top(stack_b);
	temp2 = pop_top(stack_b);
	push_top(stack_b, temp1);
	push_top(stack_b, temp2);
}

void	ss(t_stack	*stack_a, t_stack	*stack_b)
{
	t_node	*temp1;
	t_node	*temp2;
	t_node	*temp3;
	t_node	*temp4;

	temp1 = pop_top(stack_a);
	temp2 = pop_top(stack_a);
	push_top(stack_a, temp1);
	push_top(stack_a, temp2);
	temp3 = pop_top(stack_b);
	temp4 = pop_top(stack_b);
	push_top(stack_b, temp3);
	push_top(stack_b, temp4);
}

void	pa(t_stack	*stack_a, t_stack	*stack_b)
{
	push_top(stack_a, pop_top(stack_b));
}

void	pb(t_stack	*stack_a, t_stack	*stack_b)
{
	push_top(stack_b, pop_top(stack_a));
}
