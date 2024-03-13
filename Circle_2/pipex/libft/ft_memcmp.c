/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:56:40 by gsong             #+#    #+#             */
/*   Updated: 2023/01/11 20:56:41 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*uc1;
	const unsigned char	*uc2;

	uc1 = s1;
	uc2 = s2;
	if (n == 0)
		return (0);
	while (n > 1 && *uc1 == *uc2)
	{
		uc1++;
		uc2++;
		n--;
	}
	return (*uc1 - *uc2);
}
