/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 21:15:08 by gsong             #+#    #+#             */
/*   Updated: 2023/01/18 19:34:26 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

// mlxws
# include "../mlx/mlx.h"

// gnl
# include "../gnl/get_next_line.h"

// libft
# include "../libft/libft.h"

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3
# define X_EVENT_KEY_EXIT			17

# define KEY_ESC					53
# define KEY_W						13
# define KEY_A						0
# define KEY_S						1
# define KEY_D						2

typedef struct s_obj
{
	void	*ld;
	void	*tr;
	void	*it;
	void	*d1;
	void	*d2;
	void	*s1;
	void	*s4;
	void	*s7;
	void	*s10;
}				t_obj;

typedef struct s_map
{
	int				x;
	int				y;
	int				e_x;
	int				e_y;
	int				row;
	int				col;
	int				item_cnt;
	int				walk_cnt;
	int				flood_cnt;
	int				road_cnt;
	int				c_cnt;
	int				check_c_cnt;
	char			**map_line;
	char			**memory_map;
	void			*mlx;
	void			*win;
	struct s_obj	*obj;
}					t_map;

// main.c
void	print_error(char *message);
void	check_map(t_map *map, char	*av);
int		exit_game(t_map *game);

// check_middle_line.c
void	check_middle_line(t_map *map, int i, char	*line);

// check_character.c
void	check_characters(t_map	*map);

// check_escapable_map.c
void	check_escapable_map(t_map *map);

// mlx_utils.c
void	setting_img(t_map *map);
void	setting_img_2(t_map *map, int hei, int wid);
void	put_img_char(t_map *map, void *ch, int w64, int h64);
void	put_img_c(t_map *map, int w64, int h64);
void	put_img(t_map *map, void *w, int x, int y);

//init.c
void	obj_init(t_map *map);
void	generate_map(t_map *map);

void	move_w(t_map *map);
void	move_a(t_map *map);
void	move_s(t_map *map);
void	move_d(t_map *map);
void	setting_img_w(t_map *map);
void	setting_img_a(t_map *map);
void	setting_img_s(t_map *map);
void	setting_img_d(t_map *map);
#endif
