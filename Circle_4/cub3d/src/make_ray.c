/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:34:03 by gsong             #+#    #+#             */
/*   Updated: 2023/06/16 16:26:37 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	check_d_dist(t_info *g)
{
	if (g->raydir_y == 0)
		g->d_dist_x = 0;
	else if (g->raydir_x == 0)
		g->d_dist_x = 1;
	else
		g->d_dist_x = fabs(1 / g->raydir_x);
	if (g->raydir_x == 0)
		g->d_dist_y = 0;
	else if (g->raydir_y == 0)
		g->d_dist_y = 1;
	else
		g->d_dist_y = fabs(1 / g->raydir_y);
}

static void	check_s_dist(t_info *g)
{
	if (g->raydir_x < 0)
	{
		g->step_x = -1;
		g->s_dist_x = (g->p_x - g->map_x) * g->d_dist_x;
	}
	else
	{
		g->step_x = 1;
		g->s_dist_x = (g->map_x + 1.0 - g->p_x) * g->d_dist_x;
	}
	if (g->raydir_y < 0)
	{
		g->step_y = -1;
		g->s_dist_y = (g->p_y - g->map_y) * g->d_dist_y;
	}
	else
	{
		g->step_y = 1;
		g->s_dist_y = (g->map_y + 1.0 - g->p_y) * g->d_dist_y;
	}
}

void	make_background(t_info *g)
{
	int	y;
	int	x;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (y < HEIGHT / 2)
				g->screen_data[y * WIDTH + x] = g->img.c_color;
			else if (y > HEIGHT / 2)
				g->screen_data[y * WIDTH + x] = g->img.f_color;
			else
				g->screen_data[y * WIDTH + x] = 0;
		}
	}
}

void	init_ray(t_info *g, int x)
{
	g->camera = 2 * x / (double)(WIDTH - 1) - 1;
	g->raydir_x = g->dir_x + g->plane_x * g->camera;
	g->raydir_y = g->dir_y + g->plane_y * g->camera;
	g->map_x = (int)(g->p_x);
	g->map_y = (int)(g->p_y);
	check_d_dist(g);
	check_s_dist(g);
	g->hit = 0;
}
