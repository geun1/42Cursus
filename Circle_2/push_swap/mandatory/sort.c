/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:12:44 by gsong             #+#    #+#             */
/*   Updated: 2023/01/10 23:01:36 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	sort_three_data(t_stack	*stack)
{
	int	first;
	int	second;
	int	third;

	first = stack->top->next->index;
	second = stack->top->next->next->index;
	third = stack->top->next->next->next->index;
	if (first < second && second > third && third > first)
	{
		sa(stack);
		ra(stack);
	}
	else if (first < second && second > third && third < first)
		rra(stack);
	else if (first > second && second < third && third > first)
		sa(stack);
	else if (first > second && second < third && third < first)
		ra(stack);
	else if (first > second && second > third && third < first)
	{
		ra(stack);
		sa(stack);
	}
}

void	sort_five_data(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->num_of_data != 2)
	{
		stack_a->curr = stack_a->top->next;
		if (stack_a->curr->index == 1 || stack_a->curr->index == 5)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	if (check_sorting(stack_a))
		sort_three_data(stack_a);
	while (stack_b->num_of_data)
	{
		pa(stack_a, stack_b);
		if (stack_a->top->next->index == 5)
			ra(stack_a);
	}
}

void	divide_by_pivot(t_stack	*stack_a, t_stack *stack_b)
{
	int	p1;
	int	p2;
	int	times;
	int	beginning_a_num;

	p1 = stack_a->num_of_data / 3;
	p2 = (stack_a->num_of_data / 3) * 2;
	beginning_a_num = stack_a->num_of_data;
	times = 0;
	while (times < beginning_a_num)
	{
		if (stack_a->top->next->index < p2)
		{
			pb(stack_a, stack_b);
			if (stack_b->top->next->index < p1)
				rb(stack_b);
		}
		else
			ra(stack_a);
		times++;
	}
}

void	sort_indexs(t_stack	*stack_a, t_stack	*stack_b)
{
	int	a_location;
	int	b_location;

	divide_by_pivot(stack_a, stack_b);
	while (stack_a->num_of_data > 3)
		pb(stack_a, stack_b);
	sort_three_data(stack_a);
	while (stack_b->num_of_data)
	{
		a_location = 0;
		b_location = 0;
		compute_min(stack_a, stack_b, &a_location, &b_location);
		rotate_all(stack_a, stack_b, &a_location, &b_location);
		rotate_a(stack_a, a_location);
		rotate_b(stack_b, b_location);
		pa(stack_a, stack_b);
	}
	sort_leavings(stack_a);
}

void	sort(t_stack	*stack_a, t_stack	*stack_b)
{
	if (stack_a->num_of_data == 1 || !check_sorting(stack_a))
		return ;
	else if (stack_a->num_of_data == 2)
		sa(stack_a);
	else if (stack_a->num_of_data == 3)
		sort_three_data(stack_a);
	else if (stack_a->num_of_data == 5)
		sort_five_data(stack_a, stack_b);
	else
		sort_indexs(stack_a, stack_b);
}
