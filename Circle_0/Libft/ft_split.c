/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 20:49:09 by gsong             #+#    #+#             */
/*   Updated: 2022/07/25 16:30:08 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	count_word(char	const *s, char c)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == c))
			i++;
		if (s[i] && !(s[i] == c))
			cnt++;
		while (s[i] && !(s[i] == c))
			i++;
	}
	return (cnt);
}

static int	word_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && !(s[i] == c))
	{
		if (s[i] && s[i] == c)
			break ;
		i++;
	}
	return (i);
}

static char	**ft_free_return(char **s, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		free(s[i]);
	free(s);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		count;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	count = count_word(s, c);
	result = (char **) malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	while (i < count)
	{
		while (*s == c)
			s++;
		result[i] = ft_substr(s, 0, word_len(s, c));
		s += (word_len(s, c));
		if (!result[i])
			return (ft_free_return(result, i));
		i++;
	}
	result[i] = 0;
	return (result);
}
