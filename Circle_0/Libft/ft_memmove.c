/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:34:54 by gsong             #+#    #+#             */
/*   Updated: 2022/07/15 14:27:16 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void	*dst, const void	*src, size_t	len)
{
	size_t	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst < src)
	{
		i = -1;
		while (++i < len)
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
	}
	else
	{
		i = len + 1;
		while (--i)
		{
			((unsigned char *) dst)[i - 1] = ((unsigned char *) src)[i - 1];
		}
	}
	return (dst);
}
