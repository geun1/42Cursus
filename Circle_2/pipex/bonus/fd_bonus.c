/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 20:42:56 by gsong             #+#    #+#             */
/*   Updated: 2023/09/05 02:56:38 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	here_doc(char *av, t_info *info)
{
	int		file;
	char	*line;

	unlink(".tmp");
	file = open(".tmp", O_CREAT | O_WRONLY | O_TRUNC, O_CREATE_CHMOD);
	if (file < 0)
		perror_exit(ERR_HEREDOC, info->result);
	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(0);
		if (!line)
			exit(info->result);
		if (!ft_strncmp(av, line, ft_strlen(av)) \
		&& ft_strlen(av) == (ft_strlen(line) - 1))
			break ;
		write(file, line, ft_strlen(line));
		free(line);
	}
	free(line);
	close(file);
}

void	get_fd(t_info *info, int ac, char **av)
{
	if (!ft_strncmp(av[1], "here_doc", 8))
	{
		info->here_doc = 1;
		here_doc(av[2], info);
		info->input_fd = open(".tmp", O_RDONLY);
		if (info->input_fd < 0)
		{
			unlink(".tmp");
			perror_exit(ERR_HEREDOC, info->result);
		}
	}
	else
	{
		info->input_fd = open(av[1], O_RDONLY);
		if (info->input_fd < 0)
			perror("invalid file");
	}
	if (info->here_doc)
		info->output_fd = open(av[ac - 1], \
		O_RDWR | O_APPEND | O_CREAT, O_CREATE_CHMOD);
	else
		info->output_fd = open(av[ac - 1], \
		O_RDWR | O_CREAT | O_TRUNC, O_CREATE_CHMOD);
	if (info->output_fd < 0)
		perror_exit("invalid file", EXIT_ERROR);
}

void	close_fd(t_info *info)
{
	close(info->input_fd);
	close(info->output_fd);
	if (info->here_doc)
		unlink(".tmp");
	free(info->pipe_fd);
}
