/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:39:56 by gsong             #+#    #+#             */
/*   Updated: 2022/09/12 17:59:49 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_ptr(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
	return (NULL);
}

static char	*separate_by_newline(char **backup)
{
	char	*result;
	char	*backup_before;
	int		i;

	i = 0;
	if (!ft_strchr(*backup, '\n'))
	{
		backup_before = *backup;
		*backup = NULL;
		free(*backup);
		return (backup_before);
	}
	while ((*backup)[i] != '\n')
		i++;
	backup_before = *backup;
	result = ft_substr(backup_before, 0, i + 1);
	*backup = ft_substr(backup_before, i + 1, ft_strlen(backup_before) - i);
	free(backup_before);
	return (result);
}

static char	*get_line(int fd, char *buff, char **backup)
{
	int		byte_check;
	char	*result;
	char	*old_backup;

	byte_check = 1;
	while (byte_check && !(ft_strchr(*backup, '\n')))
	{
		byte_check = read(fd, buff, BUFFER_SIZE);
		if (byte_check < 0)
		{
			free(buff);
			return (free_ptr(backup));
		}
		buff[byte_check] = '\0';
		old_backup = *backup;
		*backup = ft_strjoin(old_backup, buff);
		free(old_backup);
	}
	free(buff);
	if (!**backup)
		return (free_ptr(backup));
	result = separate_by_newline(backup);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buff;
	char		*result;

	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	if (BUFFER_SIZE <= 0 || fd > OPEN_MAX || fd < 0)
	{
		free(buff);
		return (NULL);
	}
	if (!backup)
		backup = ft_substr("", 0, 0);
	result = get_line(fd, buff, &backup);
	return (result);
}
