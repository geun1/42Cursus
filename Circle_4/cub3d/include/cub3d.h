/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:32:58 by gsong             #+#    #+#             */
/*   Updated: 2023/06/16 16:30:33 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "minilibx_opengl_20191021/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <string.h>
# include <stdbool.h>

# define TRUE 1
# define FALSE 0

# define NO 1
# define SO 2
# define WE 3
# define EA 4
# define F 5
# define C 6
# define MAP 7

# define WIDTH 1920
# define HEIGHT 1080

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17

# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

typedef unsigned int	t_ui;

typedef struct s_img
{
	int		c_color;
	int		f_color;
}	t_img;

typedef struct s_img2
{
	void			*img;
	unsigned int	*data;
	int				size_l;
	int				bpp;
	int				endian;

}	t_img2;

typedef struct s_player
{
	double	dir_x;
	double	dir_y;
	char	start_point;
	double	y;
	double	x;
}	t_player;

typedef struct s_map
{
	t_player	player;
	char		*map_value;
	char		**saved_map;
	int			row;
	int			col;

}	t_map;

typedef struct s_texture
{
	char			*tex_path_malloc;
	unsigned int	*data;
	t_img2			texture;
	int				width;
	int				height;
}	t_texture;

typedef struct s_info
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_img		img;
	t_texture	tex[5];

	t_img2		wall;
	t_img2		screen;
	t_ui		*wall_data;
	t_ui		*screen_data;

	double		step;
	double		tex_pos;
	double		camera;
	double		raydir_x;
	double		raydir_y;
	double		s_dist_x;
	double		s_dist_y;
	double		d_dist_x;
	double		d_dist_y;
	double		pw_dist;
	double		p_x;
	double		p_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		wall_x;

	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_begin;
	int			draw_end;
	int			tex_x;
	int			tex_y;

}	t_info;

/* check_make_map.c */
void		check_make_map(t_map *map);

/* check_type.c */
int			check_type(char *line);

/* check_value.c */
char		*check_value_addr(char *line);
int			check_value_color(char *line);
char		*check_value_map(t_map *map, char *line);
bool		check_value_path(char *path, t_info *game, int idx);

/* init.c */
void		init_game(t_info *game, int fd);
void		init_camera(t_info *g);
int			init_window(t_info *game);
void		init_img(t_info *game);

/* input_key.c */
int			change_key(int key_code, t_info *game);

/* raycast.c */
int			main_loop(t_info *g);

/* make_ray.c */
void		make_background(t_info *g);
void		init_ray(t_info *g, int x);

/* make_texture.c */
void		cal_texture(t_info *g, t_texture wall_tex);
t_texture	check_texture(t_info *g);

/* make_type.c */
void		make_type(t_info *game, int type, char *line);

/* make_value.c */
int			make_value_of_color(char *value_line);

/* validate.c */
bool		is_valid_extention(char *file_name, char *extension);
bool		is_contain(char *str, char c);
void		check_saved_component(t_info *game);
void		check_color_value(char *line);

/* draw */
void		dda(t_info *g);
void		check_draw_point(t_info *g);
void		draw(t_info *g, t_texture wall_tex, int x);

/* exit.c */
void		error_exit(char *message);
int			press_exit(t_info *game);

/* main.c */
void		free_all_data(t_info *game, int idx);

#endif
