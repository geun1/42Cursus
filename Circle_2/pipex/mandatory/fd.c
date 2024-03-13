/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:34:05 by gsong             #+#    #+#             */
/*   Updated: 2023/09/05 02:14:44 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	get_fd(t_info *info, int ac, char **av)
{
	info->input_fd = open(av[1], O_RDONLY);
	if (info->input_fd < 0)
		perror(ERR_INFILE);
	info->output_fd = open(av[ac - 1], \
	O_RDWR | O_CREAT | O_TRUNC, O_CREATE_CHMOD);
	if (info->output_fd < 0)
		perror_exit(ERR_OUTFILE, EXIT_ERROR);
}

void	close_fd(t_info *info)
{
	close(info->input_fd);
	close(info->output_fd);
}
