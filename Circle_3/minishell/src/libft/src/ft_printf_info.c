/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:46:00 by yback             #+#    #+#             */
/*   Updated: 2023/03/02 19:46:01 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

t_print	*init_info_malloc(void)
{
	t_print	*pa_info;

	pa_info = malloc(sizeof(*pa_info));
	pa_info->state = PRINTF_NORMAL;
	pa_info->print_cnt = 0;
	return (pa_info);
}

void	reset_state(t_print *_info)
{
	_info->state = PRINTF_NORMAL;
}
