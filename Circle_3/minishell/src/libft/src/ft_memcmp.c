/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:45:30 by yback             #+#    #+#             */
/*   Updated: 2023/03/02 19:45:37 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_uchar;
	const unsigned char	*s2_uchar;

	s1_uchar = (const unsigned char *)s1;
	s2_uchar = (const unsigned char *)s2;
	while ((n > 0) && (*s1_uchar == *s2_uchar))
	{
		++s1_uchar;
		++s2_uchar;
		--n;
	}
	if (n == 0)
		return (0);
	else
		return ((int)*s1_uchar - (int)*s2_uchar);
}
