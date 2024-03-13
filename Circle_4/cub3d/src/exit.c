/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:33:21 by gsong             #+#    #+#             */
/*   Updated: 2023/06/16 16:24:43 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	error_exit(char *message)
{
	ft_putstr_fd("ERROR: ", 2);
	if (message)
		ft_putendl_fd(message, 2);
	exit(1);
}

int	press_exit(t_info *game)
{
	ft_putendl_fd("EXIT CUB3D", 0);
	free_all_data(game, 0);
	exit(1);
}
