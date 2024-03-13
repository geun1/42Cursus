/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:26:55 by gsong             #+#    #+#             */
/*   Updated: 2023/01/10 23:02:25 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# define TRUE	1
# define FALSE	0
# define SUCCESS	1
# define FAILURE	0

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	t_node	*curr;
	int		num_of_data;
}	t_stack;

void		init_stack(t_stack	*stack);
t_node		*get_new_node(int num);
void		push_top(t_stack *stack, t_node *new_node);
void		push_bottom(t_stack *stack, t_node *new_node);
t_node		*pop_top(t_stack *stack);
t_node		*pop_bottom(t_stack *stack);

void		sa(t_stack	*stack_a);
void		sb(t_stack	*stack_b);
void		ss(t_stack	*stack_a, t_stack	*stack_b);
void		pa(t_stack	*stack_a, t_stack	*stack_b);
void		pb(t_stack	*stack_a, t_stack	*stack_b);
void		ra(t_stack	*stack_a);
void		rb(t_stack	*stack_b);
void		rr(t_stack	*stack_a, t_stack	*stack_b);
void		rra(t_stack	*stack_a);
void		rrb(t_stack	*stack_b);
void		rrr(t_stack	*stack_a, t_stack	*stack_b);

long long	ft_atoi(const char *str);
void		ft_error(void);
char		**ft_split(char const *s, char c);
void		ft_check_valid_param(char	*av, t_stack	*stack);

void		indexing(t_stack	*stack);

int			check_sorting(t_stack *stack);
void		sort(t_stack	*stack_a, t_stack	*stack_b);
void		sort_three_data(t_stack	*stack);

void		compute_min(t_stack *stack_a, t_stack *stack_b, int	*a, int *b);
int			find_temp_a(int value, t_stack *stack_a);

void		rotate_all(t_stack *stack_a, t_stack *stack_b, int *a, int *b);
void		rotate_a(t_stack *stack_a, int a_location);
void		rotate_b(t_stack *stack_b, int b_location);

int			get_stack_max(t_stack	*stack_a);
int			get_stack_min(t_stack	*stack_a);
void		sort_leavings(t_stack	*stack_a);
int			find_min(t_stack *stack_a);

#endif
