/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:21:19 by gsong             #+#    #+#             */
/*   Updated: 2023/01/18 19:34:21 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	obj_init(t_map *map)
{
	int	wd;
	int	hg;

	map->obj = (t_obj *)malloc(sizeof(t_obj));
	if (!map->obj)
		return ;
	map->obj->ld = mlx_xpm_file_to_image(map->mlx, "./img/ld.xpm", &wd, &hg);
	map->obj->tr = mlx_xpm_file_to_image(map->mlx, "./img/tr1.xpm", &wd, &hg);
	map->obj->it = mlx_xpm_file_to_image(map->mlx, "./img/it.xpm", &wd, &hg);
	map->obj->d1 = mlx_xpm_file_to_image(map->mlx, "./img/d1.xpm", &wd, &hg);
	map->obj->d2 = mlx_xpm_file_to_image(map->mlx, "./img/d2.xpm", &wd, &hg);
	map->obj->s1 = mlx_xpm_file_to_image(map->mlx, "./img/s1.xpm", &wd, &hg);
	map->obj->s1 = mlx_xpm_file_to_image(map->mlx, "./img/s1.xpm", &wd, &hg);
	map->obj->s1 = mlx_xpm_file_to_image(map->mlx, "./img/s1.xpm", &wd, &hg);
	map->obj->s4 = mlx_xpm_file_to_image(map->mlx, "./img/s4.xpm", &wd, &hg);
	map->obj->s7 = mlx_xpm_file_to_image(map->mlx, "./img/s7.xpm", &wd, &hg);
	map->obj->s10 = mlx_xpm_file_to_image(map->mlx, "./img/s10.xpm", &wd, &hg);
}

void	generate_map(t_map *map)
{
	int	i;

	map->map_line = malloc (sizeof(char *) * map->row + 1);
	if (!map->map_line)
		print_error("malloc실패");
	i = -1;
	while (++i < map->row)
	{
		map->map_line[i] = malloc(sizeof(char) * map->col + 1);
		if (!map->map_line[i])
			print_error("malloc실패");
	}
	return ;
}
