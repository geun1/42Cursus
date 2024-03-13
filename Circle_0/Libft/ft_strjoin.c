/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:31:08 by gsong             #+#    #+#             */
/*   Updated: 2022/07/25 16:26:25 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*tmp;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	tmp = (char *)malloc(i + j + 1);
	if (!tmp)
		return (NULL);
	if (s1)
		ft_strlcpy(tmp, s1, i + 1);
	if (s2)
		ft_strlcpy(tmp + i, s2, j + 1);
	return (tmp);
}
