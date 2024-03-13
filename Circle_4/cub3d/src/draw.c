/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:33:15 by gsong             #+#    #+#             */
/*   Updated: 2023/06/10 16:33:16 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	dda(t_info *g)
{
	while (g->hit == 0)
	{
		if (g->s_dist_x < g->s_dist_y)
		{
			g->s_dist_x += g->d_dist_x;
			g->map_x += g->step_x;
			g->side = 0;
		}
		else
		{
			g->s_dist_y += g->d_dist_y;
			g->map_y += g->step_y;
			g->side = 1;
		}
		if (g->map.saved_map[g->map_x][g->map_y] > '0')
			g->hit = 1;
	}
	if (g->side == 0)
		g->pw_dist = (g->map_x - g->p_x + (1 - g->step_x) / 2) / g->raydir_x;
	else
		g->pw_dist = (g->map_y - g->p_y + (1 - g->step_y) / 2) / g->raydir_y;
}

void	check_draw_point(t_info *g)
{
	g->line_height = (int)(HEIGHT / g->pw_dist);
	g->draw_begin = (-1 * g->line_height / 2) + (HEIGHT / 2);
	if (g->draw_begin < 0)
		g->draw_begin = 0;
	g->draw_end = g->line_height / 2 + HEIGHT / 2;
	if (g->draw_end >= HEIGHT)
		g->draw_end = HEIGHT - 1;
}

void	draw(t_info *g, t_texture wall_tex, int x)
{
	int	color;
	int	y;

	y = g->draw_begin - 1;
	while (++y < g->draw_end)
	{
		g->tex_y = (int)(g->tex_pos) & (wall_tex.height - 1);
		g->tex_pos += g->step;
		color = g->wall_data[wall_tex.height * g->tex_y + g->tex_x];
		if (g->side == 1)
			color = (color >> 1) & 8355711;
		g->screen_data[y * WIDTH + x] = color;
	}
}
