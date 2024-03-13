/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:25:03 by gsong             #+#    #+#             */
/*   Updated: 2023/09/05 02:02:10 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	perror_exit(char *msg, int code)
{
	perror(msg);
	exit(code);
}

void	clean_free(char **to_free)
{
	free(*to_free);
	*to_free = NULL;
}

char	*find_path(char **envp)
{
	int		i;
	char	*ret_path;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
		{
			ret_path = ft_strdup(envp[i] + 5);
			return (ret_path);
		}
		i++;
	}
	return (NULL);
}

void	close_pipes(t_info *info)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		close(info->pipe_fd[i]);
		i++;
	}
}
