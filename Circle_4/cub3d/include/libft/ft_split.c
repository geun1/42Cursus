/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 12:49:29 by seokang           #+#    #+#             */
/*   Updated: 2022/07/25 13:43:59 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(const char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str && *str != c)
		{
			count++;
			while (*str && *str != c)
				str++;
		}
	}
	return (count);
}

static char	*ft_strlen_dup(const char **str, char c)
{
	int		w_len;
	int		cnt;
	char	*copy;

	w_len = 0;
	while (*(*str) && *(*str) != c)
	{
		w_len++;
		(*str)++;
	}
	*str -= w_len;
	copy = malloc(sizeof(char) * (w_len + 1));
	if (!copy)
		return (0);
	cnt = 0;
	while (*(*str) && ++cnt <= w_len)
		*copy++ = *(*str)++;
	*copy = '\0';
	copy -= w_len;
	return (copy);
}

static char	**free_copy(char **str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		c_word;
	int		i;

	if (!s)
		return (0);
	i = 0;
	c_word = ft_count_word(s, c);
	result = malloc(sizeof(char *) * (c_word + 1));
	if (!result)
		return (0);
	while (i < c_word)
	{
		while (*s && *s == c)
			s++;
		result[i] = ft_strlen_dup(&s, c);
		if (!result[i])
			return (free_copy(result, i));
		i++;
	}
	result[i] = 0;
	return (result);
}
