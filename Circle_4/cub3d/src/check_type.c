/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:41:48 by gsong             #+#    #+#             */
/*   Updated: 2023/06/16 15:42:31 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	check_type_component(char *line)
{
	if (!ft_strncmp(line, "NO ", 3))
		return (NO);
	else if (!ft_strncmp(line, "SO ", 3))
		return (SO);
	else if (!ft_strncmp(line, "WE ", 3))
		return (WE);
	else if (!ft_strncmp(line, "EA ", 3))
		return (EA);
	else
		return (FALSE);
}

static int	check_type_color(char *line)
{
	if (!ft_strncmp(line, "F ", 2))
		return (F);
	else if (!ft_strncmp(line, "C ", 2))
		return (C);
	else
		return (FALSE);
}

static int	check_type_map(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (!is_contain("01NSEW ", line[i]))
			return (FALSE);
	}
	return (MAP);
}

int	check_type(char *line)
{
	int	type;

	type = check_type_component(line);
	if (type)
		return (type);
	type = check_type_color(line);
	if (type)
		return (type);
	type = check_type_map(line);
	return (type);
}
