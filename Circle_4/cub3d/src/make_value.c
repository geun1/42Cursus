/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:34:17 by gsong             #+#    #+#             */
/*   Updated: 2023/06/16 16:09:20 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	make_value_of_element(char *value_line, int *idx)
{
	int	rgb;

	rgb = 0;
	while (value_line[++(*idx)] && ft_isdigit(value_line[*idx]))
		rgb = rgb * 10 + (value_line[*idx] - '0');
	if (rgb < 0 || 255 < rgb)
		error_exit("wrong rgb");
	return (rgb);
}

int	make_value_of_color(char *value_line)
{
	int	idx;
	int	r;
	int	g;
	int	b;
	int	color_num;

	check_color_value(value_line);
	idx = -1;
	r = make_value_of_element(value_line, &idx) * 256 * 256;
	g = make_value_of_element(value_line, &idx) * 256;
	b = make_value_of_element(value_line, &idx);
	color_num = r + g + b;
	free(value_line);
	return (color_num);
}
