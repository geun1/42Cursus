/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:47:33 by yback             #+#    #+#             */
/*   Updated: 2023/03/02 19:47:34 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*s1_uchar;
	const unsigned char	*s2_uchar;

	s1_uchar = (const unsigned char *)s1;
	s2_uchar = (const unsigned char *)s2;
	while (*s1_uchar && *s2_uchar && (*s1_uchar == *s2_uchar) && n > 0)
	{
		s1_uchar++;
		s2_uchar++;
		n--;
	}
	if (n == 0)
		return (0);
	else
		return ((int)(*s1_uchar - *s2_uchar));
}
