/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:10:00 by gsong             #+#    #+#             */
/*   Updated: 2022/07/25 16:24:40 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n;

	n = ft_strlen(needle);
	if (! *needle)
		return ((char *) haystack);
	while (*haystack && n <= len--)
	{
		if (*haystack == *needle && ! ft_memcmp(haystack, needle, n))
			return ((char *) haystack);
		haystack++;
	}
	return (NULL);
}
