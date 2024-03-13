/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:34:24 by gsong             #+#    #+#             */
/*   Updated: 2023/06/16 13:40:30 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	is_valid_extention(char *file_name, char *extension)
{
	int	file_len;
	int	res;

	file_len = ft_strlen(file_name);
	if (!ft_strncmp(file_name + file_len - 4, extension, 4))
		res = true;
	else
		res = false;
	return (res);
}

bool	is_contain(char *str, char c)
{
	int	idx;

	idx = -1;
	while (str[++idx])
	{
		if (str[idx] == c)
			return (true);
	}
	return (false);
}

void	check_saved_component(t_info *game)
{
	if (!game->tex[1].tex_path_malloc || \
		!is_valid_extention(game->tex[1].tex_path_malloc, ".xpm"))
		error_exit("wrong file");
	if (!game->tex[2].tex_path_malloc || \
		!is_valid_extention(game->tex[2].tex_path_malloc, ".xpm"))
		error_exit("wrong file");
	if (!game->tex[3].tex_path_malloc || \
		!is_valid_extention(game->tex[3].tex_path_malloc, ".xpm"))
		error_exit("wrong file");
	if (!game->tex[4].tex_path_malloc || \
		!is_valid_extention(game->tex[4].tex_path_malloc, ".xpm"))
		error_exit("wrong file");
	if (game->img.f_color == -1 || game->img.c_color == -1 \
		|| game->img.f_color == game->img.c_color)
		error_exit("wrong file");
}

static void	check_color_value_comma(char *line)
{
	int	cnt;

	cnt = 0;
	while (*line)
	{
		if (*line == ',')
			cnt++;
		line++;
	}
	if (cnt != 2)
		error_exit("wrong file");
}

void	check_color_value(char *line)
{
	int		idx;
	int		jdx;
	char	**split_line;

	check_color_value_comma(line);
	split_line = ft_split(line, ',');
	if (!split_line)
		error_exit("wrong rgb");
	idx = -1;
	while (split_line[++idx])
	{
		jdx = -1;
		while (split_line[idx][++jdx])
			if (!ft_isdigit(split_line[idx][jdx]))
				error_exit("wrong rgb");
	}
	if (idx != 3)
		error_exit("wrong rgb");
	idx = -1;
	while (split_line[++idx])
		free(split_line[idx]);
	free(split_line);
}
