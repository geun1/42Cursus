/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 13:21:48 by gsong             #+#    #+#             */
/*   Updated: 2023/01/18 21:26:08 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_error(char *message)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	exit(1);
}

static void	valid_args(char *av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	if (ft_strncmp(av + i - 4, ".ber", 4) != 0)
		print_error("Invalid file extension. Please check the file extension.");
}

int	exit_game(t_map *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	press_key(int key_code, t_map *map)
{
	if (key_code == KEY_ESC)
		exit_game(map);
	if (key_code == KEY_W)
		move_w(map);
	if (key_code == KEY_A)
		move_a(map);
	if (key_code == KEY_S)
		move_s(map);
	if (key_code == KEY_D)
		move_d(map);
	return (0);
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		print_error("Put valid map");
	ft_memset(&map, 0, sizeof(t_map));
	valid_args(av[1]);
	check_map(&map, av[1]);
	check_characters(&map);
	if (map.e_x == -1 || map.e_y == -1)
		print_error("Invalid map. Please check the map.");
	check_escapable_map(&map);
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, map.col * 64, map.row * 64, "so_long");
	obj_init(&map);
	setting_img(&map);
	mlx_hook(map.win, X_EVENT_KEY_RELEASE, 0, &press_key, &map);
	mlx_hook(map.win, X_EVENT_KEY_EXIT, 0, &exit_game, &map);
	mlx_loop(map.mlx);
	exit(0);
}
