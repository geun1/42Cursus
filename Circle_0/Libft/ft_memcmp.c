/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:40:09 by gsong             #+#    #+#             */
/*   Updated: 2022/07/15 17:03:33 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (n && (((unsigned char *) s1)[i] == ((unsigned char *) s2)[i]))
	{
		n--;
		i++;
	}
	if (n == 0)
		return (0);
	return (((unsigned char *) s1)[i] - ((unsigned char *) s2)[i]);
}
