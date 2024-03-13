/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_middle_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:15:45 by gsong             #+#    #+#             */
/*   Updated: 2023/01/18 19:42:35 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_middle_line(t_map *map, int i, char	*line)
{
	int	line_num;
	int	len;
	int	index;

	len = 0;
	index = 0;
	line_num = i + 1;
	while (line[len])
		len++;
	if (len - 1 != map->col)
		print_error("Invalid map. Please check the map.");
	if (line[0] != '1' || line[map->col -1] != '1')
		print_error("Invalid map. Please check the map.");
	while (index < map->col)
	{
		if (line[index] != '1' && line[index] != '0' && \
		line[index] != 'E' && line[index] != 'P' && \
		line[index] != 'C')
			print_error("Invalid map. Please check the map.");
		map->map_line[line_num][index] = line[index];
		index++;
	}
	map->map_line[line_num][index] = '\0';
}
