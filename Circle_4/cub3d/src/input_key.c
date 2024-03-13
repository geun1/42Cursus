/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:33:50 by gsong             #+#    #+#             */
/*   Updated: 2023/06/16 16:26:37 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	moveable(t_info *game, double nx, double ny)
{
	int	x;
	int	y;

	x = (int)nx;
	y = (int)ny;
	if (x < 0 || y < 0 || x >= game->map.row || y >= game->map.col)
		return (0);
	if (game->map.saved_map[x][y] > '0')
		return (0);
	else
		return (1);
}

static void	paralleling(t_info *g, double angle)
{
	double	y;
	double	x;

	y = (g->p_y);
	x = (g->p_x + (g->dir_x * cos(angle) - g->dir_y * sin(angle)) * 0.1);
	if (moveable(g, x, y))
		g->p_x = x;
	y = (g->p_y + (g->dir_x * sin(angle) + g->dir_y * cos(angle)) * 0.1);
	x = (g->p_x);
	if (moveable(g, x, y))
		g->p_y = y;
}

static void	rotating(t_info *g, double angle)
{
	double	new_dirx;
	double	new_diry;
	double	new_planex;
	double	new_planey;

	new_dirx = g->dir_x * cos(angle) - g->dir_y * sin(angle);
	new_diry = g->dir_x * sin(angle) + g->dir_y * cos(angle);
	new_planex = g->plane_x * cos(angle) - g->plane_y * sin(angle);
	new_planey = g->plane_x * sin(angle) + g->plane_y * cos(angle);
	g->dir_x = new_dirx;
	g->dir_y = new_diry;
	g->plane_x = new_planex;
	g->plane_y = new_planey;
}

int	change_key(int key_code, t_info *game)
{
	if (key_code == ESC)
		press_exit(game);
	else if (key_code == W || key_code == UP)
		paralleling(game, 0);
	else if (key_code == S || key_code == DOWN)
		paralleling(game, M_PI);
	else if (key_code == A)
		paralleling(game, M_PI_2);
	else if (key_code == D)
		paralleling(game, -M_PI_2);
	else if (key_code == RIGHT)
		rotating(game, -M_PI_4 * 0.1f);
	else if (key_code == LEFT)
		rotating(game, M_PI_4 * 0.1f);
	return (0);
}
