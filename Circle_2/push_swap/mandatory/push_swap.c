/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 22:02:04 by gsong             #+#    #+#             */
/*   Updated: 2023/01/11 15:05:50 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	generate_stack(char	**av, t_stack	*stack)
{
	int	idx;

	idx = 0;
	while (av[++idx])
	{
		if (av[idx][0] == '\0')
			ft_error();
		else
			ft_check_valid_param(av[idx], stack);
	}
}

int	check_sorting(t_stack *stack)
{
	int	check;
	int	num;

	check = 0;
	num = stack->num_of_data;
	stack->curr = stack->top->next;
	while (stack->curr->next->next)
	{
		if (stack->curr->value < stack->curr->next->value)
			check++;
		stack->curr = stack->curr->next;
	}
	if (check == num - 1)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (ac < 2)
		return (FALSE);
	if (!av[1][0])
		ft_error();
	init_stack (&stack_a);
	init_stack (&stack_b);
	generate_stack (av, &stack_a);
	indexing(&stack_a);
	sort(&stack_a, &stack_b);
	exit(0);
}
