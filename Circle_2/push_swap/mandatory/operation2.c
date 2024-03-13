/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:44:13 by gsong             #+#    #+#             */
/*   Updated: 2022/12/07 19:44:34 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack	*stack_a)
{
	push_bottom(stack_a, pop_top(stack_a));
	write(1, "ra\n", 3);
}

void	rb(t_stack	*stack_b)
{
	push_bottom(stack_b, pop_top(stack_b));
	write(1, "rb\n", 3);
}

void	rr(t_stack	*stack_a, t_stack	*stack_b)
{
	push_bottom(stack_a, pop_top(stack_a));
	push_bottom(stack_b, pop_top(stack_b));
	write(1, "rr\n", 3);
}
