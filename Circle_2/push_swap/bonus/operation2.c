/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:44:13 by gsong             #+#    #+#             */
/*   Updated: 2023/01/07 19:33:26 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_stack	*stack_a)
{
	push_bottom(stack_a, pop_top(stack_a));
}

void	rb(t_stack	*stack_b)
{
	push_bottom(stack_b, pop_top(stack_b));
}

void	rr(t_stack	*stack_a, t_stack	*stack_b)
{
	push_bottom(stack_a, pop_top(stack_a));
	push_bottom(stack_b, pop_top(stack_b));
}
