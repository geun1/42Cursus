/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 20:43:01 by gsong             #+#    #+#             */
/*   Updated: 2023/09/05 02:56:31 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	parsing(t_info *info, int ac, char **av)
{
	char	*temp_path;

	info->i_cmd = (t_cmd *)malloc(sizeof(t_cmd) * (ac - 3));
	if (!info->i_cmd)
		perror_exit(ERR_MALLOC, EXIT_ERROR);
	temp_path = find_path(info->envp);
	if (!temp_path)
		perror_exit(ERR_ENVP, EXIT_ENVP);
	info->path = ft_split(temp_path, ':');
	check_cmd(info, av);
	free(temp_path);
}

void	check_cmd(t_info *info, char **av)
{
	int	i;

	i = -1;
	while (++i < info->n_cmd)
	{
		while (*av[i + 2] == ' ')
			av[i + 2]++;
		if (!ft_strncmp(av[i + 2], "awk ", 4) || \
			!ft_strncmp(av[i + 2], "sed ", 4))
			quotes(av, i, info);
		else
			info->i_cmd[i].cmd = ft_split(av[i + 2], ' ');
		info->i_cmd[i].path = get_cmd_av(info->path, info->i_cmd[i].cmd[0]);
		if (info->i_cmd[i].path == NULL)
			info->result = 127;
	}
}

void	quotes(char **av, int i, t_info *info)
{
	int		j;
	int		tmp;
	char	**tmp_info;

	j = 0;
	info->i_cmd[i].cmd = ft_split(av[i + 2], ' ');
	while (ft_strncmp(info->i_cmd[i].cmd[j], "\'", 1) != 0 && \
			ft_strncmp(info->i_cmd[i].cmd[j], "\"", 1) != 0 && \
			info->i_cmd[i].cmd[j])
		j++;
	tmp = j;
	if (info->i_cmd[i].cmd[j] == 0)
		return ;
	while (info->i_cmd[i].cmd[j])
		clean_free(&(info->i_cmd[i].cmd[++j]));
	if (ft_strncmp(info->i_cmd[i].cmd[tmp], "\'", 1) == 0)
		tmp_info = ft_split(av[i + 2], '\'');
	else
		tmp_info = ft_split(av[i + 2], '\"');
	clean_free(&(info->i_cmd[i].cmd[tmp]));
	quotes2(info, tmp_info, i, tmp);
	tmp = 0;
	while (tmp_info[tmp])
		clean_free(&tmp_info[tmp++]);
	free(tmp_info);
}

void	quotes2(t_info *info, char **tmp_info, int i, int tmp)
{
	info->i_cmd[i].cmd[tmp] = ft_strdup(tmp_info[1]);
	info->i_cmd[i].cmd[tmp + 1] = NULL;
	if (ft_strncmp(info->i_cmd[i].cmd[1], "\'{", 2) == 0)
		info->result = 2;
}

char	*get_cmd_av(char **path, char *cmd)
{
	int		i;
	int		fd;
	char	*path_cmd;
	char	*tmp;

	fd = access(cmd, X_OK);
	if (fd != -1)
		return (cmd);
	path_cmd = ft_strjoin("/", cmd);
	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], path_cmd);
		fd = access(tmp, X_OK);
		if (fd != -1)
		{
			free(path_cmd);
			return (tmp);
		}
		close(fd);
		free(tmp);
		i++;
	}
	free(path_cmd);
	return (NULL);
}
