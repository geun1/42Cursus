/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 23:04:19 by gsong             #+#    #+#             */
/*   Updated: 2022/12/18 18:51:56 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_min(t_stack	*stack_a)
{
	int		ret;
	int		times;
	t_node	*tmp_node;

	tmp_node = stack_a->top->next;
	ret = tmp_node->index;
	times = 0;
	while (times < stack_a->num_of_data - 1)
	{
		if (ret > tmp_node->next->index)
			ret = tmp_node->next->index;
		tmp_node = tmp_node->next;
		times++;
	}
	return (ret);
}

int	get_stack_max(t_stack	*stack_a)
{
	int		ret;
	int		times;
	t_node	*tmp_node;

	tmp_node = stack_a->top->next;
	ret = tmp_node->index;
	times = 0;
	while (times < stack_a->num_of_data - 1)
	{
		if (ret < tmp_node->next->index)
			ret = tmp_node->next->index;
		tmp_node = tmp_node->next;
		times++;
	}
	return (ret);
}

void	sort_leavings(t_stack	*stack_a)
{
	int	first_location;

	first_location = find_min(stack_a);
	while (first_location)
	{
		if (first_location > 0)
		{
			ra(stack_a);
			first_location--;
		}
		else
		{
			rra(stack_a);
			first_location++;
		}
	}
}
