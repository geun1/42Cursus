/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:45:25 by gsong             #+#    #+#             */
/*   Updated: 2023/01/10 17:06:19 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE   42
# endif

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
	struct s_node	*top;
	struct s_node	*bottom;
	struct s_node	*curr;
	int				num_of_data;
}	t_stack;

// checker.c
int			main(int ac, char **av);

// get_next_line_utils.c
int			gnl_strlen(const char *s);
int			gnl_strchr(char *s);
char		*gnl_strjoin(char *s1, char *s2);

// get_next_line.c
char		*get_next_line(int fd);

// indexing.c
void		indexing(t_stack	*stack);
void		indexing2(t_stack	*stack, int min);

// operations.c
void		sa(t_stack	*stack_a);
void		sb(t_stack	*stack_b);
void		ss(t_stack	*stack_a, t_stack	*stack_b);
void		pa(t_stack	*stack_a, t_stack	*stack_b);
void		pb(t_stack	*stack_a, t_stack	*stack_b);

// operation2.c
void		ra(t_stack	*stack_a);
void		rb(t_stack	*stack_b);
void		rr(t_stack	*stack_a, t_stack	*stack_b);

// operation3.c
void		rra(t_stack	*stack_a);
void		rrb(t_stack	*stack_b);
void		rrr(t_stack	*stack_a, t_stack	*stack_b);
long long	ft_atoi(const char *str);
void		ft_error(void);

// stack.c
void		init_stack(t_stack *stack);
t_node		*get_new_node(int num);
void		ft_free(char **split_av, int i);

// stack_utils.c
void		push_top(t_stack	*stack, t_node	*new_node);
void		push_bottom(t_stack *stack, t_node *new_node);
t_node		*pop_top(t_stack *stack);
t_node		*pop_bottom(t_stack *stack);

//ft_check_valid_param.c
void		ft_check_valid_param(char	*av, t_stack	*stack);
void		check_sorting(t_stack *stack);

// ft_split.c
char		**ft_split(char const *s, char c);

// checker_utils.c
void		operating(t_stack *stack_a, t_stack *stack_b);
void		operation(char *op, t_stack *stack_a, t_stack *stack_b);
void		checker(t_stack *stack_a, t_stack *stack_b);
#endif
