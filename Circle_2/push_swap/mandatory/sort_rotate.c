/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:53:59 by gsong             #+#    #+#             */
/*   Updated: 2022/12/18 18:56:44 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	rotate_all(t_stack *stack_a, t_stack *stack_b, int *a, int	*b)
{
	while (*a && *b && (*a > 0 && *b > 0))
	{
		rr(stack_a, stack_b);
		*a = *a - 1;
		*b = *b - 1;
	}
	while (*a && *b && (*a < 0 && *b < 0))
	{
		rrr(stack_a, stack_b);
		*a = *a + 1;
		*b = *b + 1;
	}
}

void	rotate_a(t_stack	*stack_a, int a_location)
{
	while (a_location)
	{
		if (a_location > 0)
		{
			ra(stack_a);
			a_location--;
		}
		else
		{
			rra(stack_a);
			a_location++;
		}
	}
}

void	rotate_b(t_stack	*stack_b, int b_location)
{
	while (b_location)
	{
		if (b_location > 0)
		{
			rb(stack_b);
			b_location--;
		}
		else
		{
			rrb(stack_b);
			b_location++;
		}
	}
}

int	get_bigger(int a_location, int b_location, int temp_a, int temp_b)
{
	if (a_location < 0)
		a_location = a_location * -1;
	if (b_location < 0)
		b_location = b_location * -1;
	if (temp_a < 0)
		temp_a = temp_a * -1;
	if (temp_b < 0)
		temp_b = temp_b * -1;
	if (a_location + b_location > temp_a + temp_b)
		return (1);
	return (0);
}

void	compute_min(t_stack	*stack_a, t_stack *stack_b, int	*a, int *b)
{
	int		temp_a;
	int		temp_b;
	int		idx;
	int		num;
	t_node	*tmp_node;

	idx = 0;
	tmp_node = stack_b->top->next;
	while (idx < stack_b->num_of_data)
	{
		num = tmp_node->index;
		temp_a = find_temp_a(num, stack_a);
		if (idx >= (stack_b->num_of_data + 1) / 2)
			temp_b = (stack_b->num_of_data - idx) * -1;
		else
			temp_b = idx;
		if (idx == 0 || get_bigger(*a, *b, temp_a, temp_b))
		{
			*a = temp_a;
			*b = temp_b;
		}
		tmp_node = tmp_node->next;
		idx++;
	}
}
