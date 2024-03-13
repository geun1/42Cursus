/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:30:56 by seokang           #+#    #+#             */
/*   Updated: 2022/07/13 13:58:48 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*dest;
	unsigned char	input;
	size_t			i;

	dest = (unsigned char *)b;
	input = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		dest[i] = input;
		i++;
	}
	return (dest);
}
