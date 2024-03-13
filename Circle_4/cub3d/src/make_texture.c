/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:34:08 by gsong             #+#    #+#             */
/*   Updated: 2023/06/16 16:29:38 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_texture	check_texture(t_info *g)
{
	t_texture	texture;

	if (g->side == 0)
	{
		if (g->step_x == -1)
			texture = g->tex[WE];
		else
			texture = g->tex[EA];
	}
	else
	{
		if (g->step_y == -1)
			texture = g->tex[NO];
		else
			texture = g->tex[SO];
	}
	return (texture);
}

void	cal_texture(t_info *g, t_texture wall_tex)
{
	if (g->side == 0)
		g->wall_x = g->p_y + g->pw_dist * g->raydir_y;
	else
		g->wall_x = g->p_x + g->pw_dist * g->raydir_x;
	g->wall_x -= floor((g->wall_x));
	g->tex_x = (int)(g->wall_x * (double)(wall_tex.width));
	if (g->side == 0 && g->raydir_x > 0)
		g->tex_x = wall_tex.width - g->tex_x - 1;
	if (g->side == 1 && g->raydir_y < 0)
		g->tex_x = wall_tex.width - g->tex_x - 1;
	g->step = 1.0 * wall_tex.height / g->line_height;
	g->tex_pos = (g->draw_begin - HEIGHT / 2 + g->line_height / 2);
	g->tex_pos *= g->step;
}
