/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:47:40 by yback             #+#    #+#             */
/*   Updated: 2023/03/02 19:47:41 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	size;

	size = 0;
	while (*s)
	{
		s++;
		size++;
	}
	if (size == 0 && c == 0)
		return ((char *)s);
	while (size > 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		s--;
		size--;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
