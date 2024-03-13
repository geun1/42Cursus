/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:32:04 by gsong             #+#    #+#             */
/*   Updated: 2023/04/11 17:16:29 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_mutex(t_info *info, pthread_mutex_t **fork)
{
	int	i;

	*fork = malloc(sizeof(pthread_mutex_t) * info->arg.n_philo);
	if (!(*fork))
		return (ERROR);
	i = -1;
	while (++i < info->arg.n_philo)
		if (pthread_mutex_init(&(*fork)[i], PTHREAD_MUTEX_NORMAL) != 0)
			return (ERROR);
	if (pthread_mutex_init(&info->mtx_print, PTHREAD_MUTEX_NORMAL) != 0)
		return (ERROR);
	return (SUCCESS);
}

static int	init_philo(t_philo **philo, t_info *info, t_arg *arg
		, pthread_mutex_t *fork)
{
	int	i;

	(*philo) = malloc(sizeof(t_philo) * arg->n_philo);
	if (*philo == NULL)
		return (ERROR);
	i = 0;
	while (i < arg->n_philo)
	{
		(*philo)[i].idx = i;
		(*philo)[i].cnt_eat = 0;
		(*philo)[i].info = info;
		(*philo)[i].mtx_left = &fork[i];
		(*philo)[i].mtx_right = &fork[(i + 1) % arg->n_philo];
		(*philo)[i].last_eat_t = get_time();
		++i;
	}
	pthread_mutex_lock(&info->mtx_print);
	i = -1;
	while (++i < arg->n_philo)
		if (pthread_create(&(*philo)[i].tid, NULL, action, &(*philo)[i]))
			return (ERROR);
	info->birth_t = get_time();
	pthread_mutex_unlock(&info->mtx_print);
	return (SUCCESS);
}

static int	init_info(t_philo **philo, t_info *info)
{
	pthread_mutex_t	*fork;

	info->stat.end = 0;
	info->stat.n_full = 0;
	if (init_mutex(info, &fork) == ERROR)
		return (ERROR);
	if (init_philo(philo, info, &info->arg, fork) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

static int	parse_arg(int argc, char **argv, t_info *info)
{
	if (!(argc == 5 || argc == 6))
		return (ft_error("argument count"));
	info->arg.n_philo = arg_atoi(argv[1]);
	if (info->arg.n_philo <= 0)
		return (ft_error("philosophers_n argument"));
	info->arg.die_time = arg_atoi(argv[2]);
	info->arg.eat_time = arg_atoi(argv[3]);
	info->arg.sleep_time = arg_atoi(argv[4]);
	if (info->arg.die_time <= 0 || info->arg.eat_time <= 0
		|| info->arg.sleep_time <= 0)
		return (ft_error("time argument"));
	info->arg.must_eat = 0;
	if (argc == 6)
	{
		info->arg.must_eat = arg_atoi(argv[5]);
		if (info->arg.must_eat <= 0)
			return (ft_error("must_eat_n argument"));
	}
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	int		i;
	t_info	info;
	t_philo	*philo;

	if (parse_arg(argc, argv, &info) == ERROR)
		return (ERROR);
	if (init_info(&philo, &info) == SUCCESS)
		monitor(philo);
	i = -1;
	while (++i < philo->info->arg.n_philo)
		pthread_mutex_unlock(philo[i].mtx_left);
	i = -1;
	while (++i < philo->info->arg.n_philo)
		pthread_join(philo[i].tid, NULL);
	mutex_free(philo, philo->info, &philo->info->arg);
	return (0);
}
