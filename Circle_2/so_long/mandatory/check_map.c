/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:12:07 by gsong             #+#    #+#             */
/*   Updated: 2023/01/18 21:32:16 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_first_line(t_map *map, char	*line)
{
	size_t	col;

	col = 0;
	while (line[col] == '1')
		col++;
	ft_strlcpy(map->map_line[0], line, map->col + 1);
	if (ft_strlen(line)-1 != col)
		print_error("Invalid map. Please check the map.");
}

void	check_last_line(t_map *map, char	*line)
{
	size_t	col;
	int		len;

	col = 0;
	len = 0;
	while (line[col] == '1')
		col++;
	while (line[len])
		len++;
	if (len - 1 != map->col)
		print_error("Invalid map. Please check the map.");
	ft_strlcpy(map->map_line[map->row - 1], line, map->col + 1);
	if (ft_strlen(line) - 1 != col)
		print_error("Invalid map. Please check the map.");
}

void	check_map_size(t_map *map, int fd)
{
	int		size;
	char	*line;

	if (fd < 0)
		print_error("check file name, fd error");
	size = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (gnl_strchr(line) == -1)
			break ;
		size++;
		free (line);
	}
	free(line);
	map->row = size;
	if (map->row <= 2)
		print_error("Invalid map. Please check the map.");
}

void	check_map2(t_map *map, int fd)
{
	int		i;
	char	*line;

	i = -1;
	while (++i < map->row - 2)
	{
		line = get_next_line(fd);
		if (!line)
			print_error("malloc fail");
		check_middle_line(map, i, line);
		free (line);
	}
	line = get_next_line(fd);
	if (!line)
		print_error("malloc fail");
	check_last_line(map, line);
	free(line);
}

void	check_map(t_map *map, char *av)
{
	int		fd;
	char	*line;

	fd = open(av, O_RDONLY);
	check_map_size(map, fd);
	close(fd);
	fd = open(av, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		print_error("malloc fail");
	map->col = ft_strlen(line) - 1;
	generate_map(map);
	check_first_line(map, line);
	free(line);
	check_map2(map, fd);
	close (fd);
}
