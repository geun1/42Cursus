/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:32:09 by gsong             #+#    #+#             */
/*   Updated: 2023/04/03 16:32:10 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# define ERROR                  -1
# define SUCCESS                0
# define EATTING                1

typedef struct s_status
{
	int	end;
	int	n_full;
}	t_status;

typedef struct s_arg
{
	int	n_philo;
	int	die_time;
	int	eat_time;
	int	sleep_time;
	int	must_eat;
}	t_arg;

typedef struct s_info
{
	t_arg			arg;
	pthread_mutex_t	mtx_print;
	t_status		stat;
	size_t			birth_t;
}	t_info;

typedef struct s_philo
{
	int				idx;
	pthread_t		tid;
	int				cnt_eat;
	size_t			last_eat_t;
	t_info			*info;
	pthread_mutex_t	*mtx_left;
	pthread_mutex_t	*mtx_right;
}	t_philo;

size_t		get_time(void);
void		smart_timer(int time);
void		monitor(t_philo *philo);
void		mutex_free(t_philo *philo, t_info *info, t_arg *arg);
void		*action(void *param);
int			arg_atoi(const char *str);
int			ft_error(char *str);
#endif
