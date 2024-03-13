/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:34:13 by gsong             #+#    #+#             */
/*   Updated: 2023/06/16 16:24:43 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	make_type_component(t_info *game, int type, char *line)
{
	char	*value_line;

	value_line = check_value_addr(line);
	if (type == NO && (game->tex[NO].tex_path_malloc \
			|| !check_value_path(value_line, game, NO)))
		error_exit("wrong file");
	else if (type == SO && (game->tex[SO].tex_path_malloc \
			|| !check_value_path(value_line, game, SO)))
		error_exit("wrong file");
	else if (type == WE && (game->tex[WE].tex_path_malloc \
			|| !check_value_path(value_line, game, WE)))
		error_exit("wrong file");
	else if (type == EA && (game->tex[EA].tex_path_malloc \
			|| !check_value_path(value_line, game, EA)))
		error_exit("wrong file");
	free(value_line);
}

static void	make_type_color(t_img *img, int type, char *line)
{
	if (type == F)
	{
		if (img->f_color != -1)
			error_exit("wrong file");
		img->f_color = check_value_color(line);
	}
	else if (type == C)
	{
		if (img->c_color != -1)
			error_exit("wrong file");
		img->c_color = check_value_color(line);
	}
}

static void	make_type_map(t_map *map, t_info *game, char *line)
{
	check_saved_component(game);
	map->map_value = check_value_map(map, line);
}

void	make_type(t_info *game, int type, char *line)
{
	if (NO <= type && type <= EA)
		make_type_component(game, type, line);
	else if (F <= type && type <= C)
		make_type_color(&game->img, type, line);
	else
		make_type_map(&game->map, game, line);
}
