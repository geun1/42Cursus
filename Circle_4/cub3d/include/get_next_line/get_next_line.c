/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:32:48 by seokang           #+#    #+#             */
/*   Updated: 2022/09/18 14:31:32 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_baguni_pugi(int fd, char *backup)
{
	char	*baguni;
	int		reres;

	baguni = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!baguni)
		return (NULL);
	reres = read(fd, baguni, BUFFER_SIZE);
	while (reres > 0)
	{
		baguni[reres] = '\0';
		backup = gnl_strjoin(backup, baguni);
		if (gnl_strchr(backup, '\n'))
			break ;
		reres = read(fd, baguni, BUFFER_SIZE);
	}
	free(baguni);
	return (backup);
}

static char	*ft_na_nugi(char **result, char *backup)
{
	int		idx_end;
	int		idx_nl;
	char	*temp;

	idx_end = 0;
	idx_nl = -1;
	while (backup[idx_end] && backup[idx_end] != '\n')
		idx_end++;
	if (backup[idx_end] == '\n')
		idx_nl = idx_end;
	if (idx_nl == -1)
	{
		if (*backup != '\0')
			*result = gnl_strndup(backup, 0, gnl_strlen(backup));
		free(backup);
		return (NULL);
	}
	else
	{
		*result = gnl_strndup(backup, 0, idx_nl + 1);
		temp = gnl_strndup(backup, idx_nl + 1, gnl_strlen(backup) - idx_nl);
		free(backup);
		backup = temp;
	}
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*result;
	static char	*backup;

	result = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!backup)
	{
		backup = gnl_strndup("", 0, 0);
		if (!backup)
			return (NULL);
		*backup = '\0';
	}
	backup = ft_baguni_pugi(fd, backup);
	if (!backup)
		return (NULL);
	backup = ft_na_nugi(&result, backup);
	return (result);
}
