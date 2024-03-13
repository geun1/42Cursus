/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:45:50 by yback             #+#    #+#             */
/*   Updated: 2023/03/02 19:45:52 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_nbrlen(int num)
{
	size_t	len;
	size_t	sign;

	sign = 0;
	len = 0;
	if (num < 0)
		sign = 1;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 10;
		len += 1;
	}
	return (len + sign);
}
