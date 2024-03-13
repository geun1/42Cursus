/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:42:30 by gsong             #+#    #+#             */
/*   Updated: 2022/09/12 16:45:58 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	cnt;

	cnt = 0;
	while (s[cnt])
		cnt++;
	return (cnt);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;
	char	*total_s;

	if (!s1 || !s2)
		return (0);
	i = -1;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	total_len = s1_len + s2_len;
	total_s = malloc (sizeof(char) * total_len + 1);
	if (!total_s)
		return (0);
	while (++i < s1_len)
		total_s[i] = s1[i];
	i = -1;
	while (++i < s2_len)
		total_s[s1_len + i] = s2[i];
	total_s[total_len] = '\0';
	return (total_s);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		else
			s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

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
	{
		tmp = (char *)malloc(sizeof(char));
		if (! tmp)
			return (NULL);
	}
	tmp[i] = '\0';
	return (tmp);
}
