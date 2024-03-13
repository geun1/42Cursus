/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 20:42:59 by gsong             #+#    #+#             */
/*   Updated: 2023/09/05 03:13:13 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	initializing(t_info *info, int ac, char **av, char **envp)
{
	int	i;

	ft_memset(info, 0, sizeof(t_info));
	info->result = 0;
	info->envp = envp;
	get_fd(info, ac, av);
	info->n_cmd = ac - info->here_doc - 3;
	info->pipe_fd = (int *)malloc(sizeof(int) * 2 * (info->n_cmd - 1));
	if (!info->pipe_fd)
		perror_exit(ERR_MALLOC, EXIT_ERROR);
	i = -1;
	while (++i < info->n_cmd - 1)
	{
		if (pipe(info->pipe_fd + 2 * i) < 0)
		{
			free(info->pipe_fd);
			perror_exit(ERR_PIPE, EXIT_ERROR);
		}
	}
}

static void	dup4(int zero, int first)
{
	dup2(zero, 0);
	dup2(first, 1);
}

void	forking(t_info pc)
{
	pc.pid = fork();
	if (!pc.pid)
	{
		if (pc.idx == 0)
			dup4(pc.input_fd, pc.pipe_fd[1]);
		else if (pc.idx == pc.n_cmd - 1)
			dup4(pc.pipe_fd[2 * pc.idx - 2], pc.output_fd);
		else
			dup4(pc.pipe_fd[2 * pc.idx - 2], pc.pipe_fd[2 * pc.idx + 1]);
		close_pipes(&pc);
		if (execve(pc.i_cmd[pc.idx].path, pc.i_cmd[pc.idx].cmd, pc.envp) < 0)
			perror_exit(ERR_CMD, pc.result);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_info	info;
	int		acs;

	if (av[1] && !ft_strncmp("here_doc", av[1], 9))
		acs = 6;
	else
		acs = 5;
	if (ac < acs)
		perror_exit(ERR_ARGC, EXIT_ERROR);
	initializing(&info, ac, av, envp);
	parsing(&info, ac - (&info)->here_doc, av + (&info)->here_doc);
	info.idx = -1;
	while (++(info.idx) < info.n_cmd)
		forking(info);
	close_pipes(&info);
	waitpid(-1, NULL, 0);
	close_fd(&info);
	return (info.result);
}
