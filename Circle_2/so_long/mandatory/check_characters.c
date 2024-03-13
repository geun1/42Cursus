/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:59:55 by gsong             #+#    #+#             */
/*   Updated: 2023/01/18 20:07:46 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_characters(t_map	*map)
{
	int	i;
	int	j;

	i = -1;
	map->e_x = -1;
	map->e_y = -1;
	while (++i < map->row)
	{
		j = -1;
		while (++j < map->col)
		{
			if (map->map_line[i][j] == 'E')
			{
				map->e_x = i;
				map->e_y = j;
			}
			else if (map->map_line[i][j] == 'P')
			{
				map->x = i;
				map->y = j;
			}
			else if (map->map_line[i][j] == 'C')
				map->c_cnt++;
		}
	}
}
