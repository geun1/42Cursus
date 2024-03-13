/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:27:42 by gsong             #+#    #+#             */
/*   Updated: 2023/01/18 15:21:41 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_s(t_map *map)
{
	int	x;
	int	y;

	x = map->x + 1;
	y = map->y;
	if (map->map_line[x][y] == 'C')
		map->item_cnt++;
	if (map->map_line[x][y] == 'E' && map->c_cnt == map->item_cnt)
		exit_game(map);
	else if (map->map_line[x][y] != '1' && \
			map->map_line[x][y] != 'E')
	{
		map->map_line[map->x][map->y] = '0';
		map->map_line[x][y] = 'P';
		map->x++;
		map->walk_cnt++;
		ft_putnbr_fd(map->walk_cnt, 1);
		write(1, "\n", 1);
		setting_img_s(map);
	}
}

static void	setting_img_s2(t_map *map, int hei, int wid)
{
	int	h64;
	int	w64;

	h64 = hei * 64;
	w64 = wid * 64;
	if (map->map_line[hei][wid] == '1')
		put_img(map, map->obj->tr, w64, h64);
	else if (map->map_line[hei][wid] == 'C')
		put_img_c(map, w64, h64);
	else if (map->map_line[hei][wid] == 'P')
		put_img_char(map, map->obj->s1, w64, h64);
	else if (map->map_line[hei][wid] == 'E')
	{
		put_img(map, map->obj->ld, w64, h64);
		if (map->item_cnt == map->c_cnt)
			put_img(map, map->obj->d2, w64 + 16, h64 + 16);
		else
			put_img(map, map->obj->d1, w64 + 16, h64 + 16);
	}
	else
		put_img(map, map->obj->ld, w64, h64);
}

void	setting_img_s(t_map *map)
{
	int		hei;
	int		wid;

	hei = 0;
	while (hei < map->row)
	{
		wid = 0;
		while (wid < map->col)
		{
			setting_img_s2(map, hei, wid);
			wid++;
		}
		hei++;
	}
}
