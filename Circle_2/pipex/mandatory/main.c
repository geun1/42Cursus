/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:50:03 by gsong             #+#    #+#             */
/*   Updated: 2023/09/05 02:14:15 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	initializing(t_info *info, int ac, char **av, char **envp)
{
	ft_memset(info, 0, sizeof(t_info));
	info->result = 0;
	info->envp = envp;
	get_fd(info, ac, av);
	if (pipe(info->pipe_fd) < 0)
		perror_exit(ERR_PIPE, EXIT_ERROR);
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
		else if (pc.idx == 1)
			dup4(pc.pipe_fd[0], pc.output_fd);
		close_pipes(&pc);
		if (execve(pc.i_cmd[pc.idx].path, pc.i_cmd[pc.idx].cmd, pc.envp) < 0)
			perror_exit(ERR_CMD, pc.result);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_info	info;

	if (ac != 5)
		perror_exit(ERR_ARGC, EXIT_FAIL);
	initializing(&info, ac, av, envp);
	parsing(&info, ac, av);
	info.idx = -1;
	while (++(info.idx) < 2)
		forking(info);
	close_pipes(&info);
	waitpid(-1, NULL, 0);
	close_fd(&info);
	return (info.result);
}
