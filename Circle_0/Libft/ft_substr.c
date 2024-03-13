/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:37:02 by song-geun-i       #+#    #+#             */
/*   Updated: 2022/07/25 15:58:57 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	if (((size_t)start < ft_strlen(s)))
	{
		if (len > ft_strlen(s))
			len = ft_strlen(s);
		tmp = (char *)malloc(sizeof(char) * (len + 1));
		if (! tmp)
			return (NULL);
		while (len-- && s[start])
			tmp[i++] = s[start++];
	}
	else
		tmp = (char *)malloc(sizeof(char));
	tmp[i] = '\0';
	return (tmp);
}
