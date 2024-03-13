/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:33:45 by gsong             #+#    #+#             */
/*   Updated: 2023/06/16 16:24:43 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_game(t_info *game, int fd)
{
	int		type;
	char	*line;

	ft_memset(game, 0, sizeof(t_info));
	game->img.f_color = -1;
	game->img.c_color = -1;
	line = get_next_line(fd);
	while (line != NULL)
	{
		line[ft_strlen(line) - 1] = '\0';
		if (line[0] != '\0')
		{
			type = check_type(line);
			if (!type)
				error_exit("wrong map");
			make_type(game, type, line);
		}
		free(line);
		line = get_next_line(fd);
	}
	check_make_map(&game->map);
	close(fd);
	free(line);
}

void	init_camera(t_info *game)
{
	double	angle;

	game->p_x = game->map.player.y + 0.5f;
	game->p_y = game->map.player.x + 0.5f;
	if (game->map.player.start_point == 'W')
		angle = M_PI;
	else if (game->map.player.start_point == 'S')
		angle = M_PI_2;
	else if (game->map.player.start_point == 'E')
		angle = 0;
	else
		angle = -M_PI_2;
	game->dir_x = cos(angle);
	game->dir_y = sin(angle);
	game->plane_x = 0.66 * cos(angle - M_PI_2);
	game->plane_y = 0.66 * sin(angle - M_PI_2);
}

int	init_window(t_info *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (1);
	game->win = mlx_new_window(game->mlx, (int)WIDTH, \
		(int)HEIGHT, "CUB_3D");
	if (!game->win)
		return (1);
	return (0);
}

void	init_img(t_info *game)
{
	t_texture	*tx;

	tx = game->tex;
	tx[1].texture.img = mlx_xpm_file_to_image(game->mlx, \
		tx[1].tex_path_malloc, &(tx[1].width), &(tx[1].height));
	tx[2].texture.img = mlx_xpm_file_to_image(game->mlx, \
		tx[2].tex_path_malloc, &(tx[2].width), &(tx[2].height));
	tx[3].texture.img = mlx_xpm_file_to_image(game->mlx, \
		tx[3].tex_path_malloc, &(tx[3].width), &(tx[3].height));
	tx[4].texture.img = mlx_xpm_file_to_image(game->mlx, \
		tx[4].tex_path_malloc, &(tx[4].width), &(tx[4].height));
	game->screen.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
}
