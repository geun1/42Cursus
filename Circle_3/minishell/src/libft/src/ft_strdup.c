/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:46:53 by yback             #+#    #+#             */
/*   Updated: 2023/03/02 19:46:55 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

extern size_t	ft_strlen(const char *str);

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*tmp;

	size = ft_strlen(s1);
	tmp = malloc(sizeof(*tmp) * (size + 1));
	if (!tmp)
		return (NULL);
	while (size > 0)
	{
		tmp[size] = s1[size];
		--size;
	}
	tmp[0] = s1[0];
	return (tmp);
}
