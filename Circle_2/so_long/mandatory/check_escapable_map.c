/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_escapable_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:50:36 by gsong             #+#    #+#             */
/*   Updated: 2023/01/18 19:45:19 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	floodfill(int x, int y, t_map *map)
{
	if (x < 0 || x >= map->row || y < 0 \
	|| y >= map->col || map->map_line[x][y] == '1' \
	|| map->map_line[x][y] == 'E')
		return ;
	if (map->memory_map[x][y] != '0')
		return ;
	map->memory_map[x][y] = '1';
	if (map->map_line[x][y] == 'C')
		map->check_c_cnt++;
	map->flood_cnt++;
	floodfill(x + 1, y, map);
	floodfill(x - 1, y, map);
	floodfill(x, y + 1, map);
	floodfill(x, y - 1, map);
	return ;
}

void	generate_memory_map(t_map *map)
{
	int	i;
	int	j;

	map->memory_map = malloc (sizeof(char *) * map->row + 1);
	if (!map->memory_map)
		print_error("malloc fail");
	i = -1;
	while (++i < map->row)
	{
		map->memory_map[i] = malloc(sizeof(char) * map->col + 1);
		if (!map->memory_map[i])
			print_error("malloc fail");
		j = -1;
		while (++j < map->col)
			map->memory_map[i][j] = '0';
		map->memory_map[i][j++] = '\0';
	}
	map->memory_map[i++] = NULL;
	return ;
}

void	check_escape_around(t_map *map)
{
	int	x;
	int	y;
	int	checker;

	x = map->e_x;
	y = map->e_y;
	checker = 0;
	if (!((map->map_line[x + 1][y] != '1' && map->memory_map[x + 1][y] == '1') \
		|| (map->map_line[x - 1][y] != '1' && map->memory_map[x - 1][y] == '1') \
		|| (map->map_line[x][y + 1] != '1' && map->memory_map[x][y + 1] == '1') \
		|| (map->map_line[x][y - 1] != '1' \
		&& map->memory_map[x][y - 1] == '1')))
		print_error("Invalid map. Please check the map.");
}

void	check_escapable_map(t_map *map)
{
	int	cnt;

	cnt = 0;
	generate_memory_map(map);
	floodfill(map->x, map->y, map);
	check_escape_around(map);
	if (map->c_cnt != map->check_c_cnt)
		print_error("Invalid map. Please check the map.");
}
