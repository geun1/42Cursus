/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:25:07 by gsong             #+#    #+#             */
/*   Updated: 2023/01/11 15:02:00 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (ac < 2)
		return (FALSE);
	init_stack (&stack_a);
	init_stack (&stack_b);
	generate_stack (av, &stack_a);
	indexing(&stack_a);
	operating(&stack_a, &stack_b);
	checker(&stack_a, &stack_b);
	exit(0);
}
