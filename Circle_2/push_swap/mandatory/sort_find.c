/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:15:53 by gsong             #+#    #+#             */
/*   Updated: 2022/12/18 18:49:00 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack	*stack_a)
{
	int		ret;
	int		idx;
	int		temp;
	t_node	*tmp_node;

	ret = 0;
	idx = 0;
	tmp_node = stack_a->top->next;
	idx = get_stack_min(stack_a);
	while (ret < stack_a->num_of_data)
	{
		temp = tmp_node->index;
		if (temp == idx)
			break ;
		ret++;
		tmp_node = tmp_node->next;
	}
	if (ret >= (stack_a->num_of_data + 1) / 2)
		ret = (stack_a->num_of_data - ret) * -1;
	return (ret);
}

int	find_max(t_stack	*stack_a)
{
	int		ret;
	int		idx;
	int		temp;
	t_node	*tmp_node;

	ret = 0;
	idx = 0;
	tmp_node = stack_a->top->next;
	idx = get_stack_max(stack_a);
	while (ret < stack_a->num_of_data)
	{
		temp = tmp_node->index;
		if (temp == idx)
			break ;
		ret++;
		tmp_node = tmp_node->next;
	}
	ret++;
	if (ret >= (stack_a->num_of_data + 1) / 2)
		ret = (stack_a->num_of_data - ret) * -1;
	return (ret);
}

int	find_mid(int value, t_stack	*stack_a)
{
	int		ret;
	int		idx;
	t_node	*tmp_node;

	ret = 1;
	idx = 0;
	tmp_node = stack_a->top->next;
	while (idx < stack_a->num_of_data)
	{
		if (tmp_node->next->index == 0)
			return (0);
		if (value > tmp_node->index && value < tmp_node->next->index)
			break ;
		ret++;
		tmp_node = tmp_node->next;
		idx++;
	}
	if (ret >= (stack_a->num_of_data + 1) / 2)
		ret = (stack_a->num_of_data - ret) * -1;
	return (ret);
}

int	find_temp_a(int value, t_stack	*stack_a)
{
	int	a_loc;

	if (value < get_stack_min(stack_a))
		a_loc = find_min(stack_a);
	else if (value > get_stack_max(stack_a))
		a_loc = find_max(stack_a);
	else
		a_loc = find_mid(value, stack_a);
	return (a_loc);
}
