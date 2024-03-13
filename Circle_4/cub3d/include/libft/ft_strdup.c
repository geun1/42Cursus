/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:01:19 by seokang           #+#    #+#             */
/*   Updated: 2022/07/25 15:36:29 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strcpy(char *dst, const char *s1)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
}

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	s_len;

	s_len = ft_strlen(s1);
	dst = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!dst)
		return (0);
	ft_strcpy(dst, s1);
	return (dst);
}
