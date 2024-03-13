/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:55:36 by gsong             #+#    #+#             */
/*   Updated: 2023/01/11 20:55:37 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_size(int n)
{
	int		size;
	long	ln;

	ln = (long)n;
	size = 0;
	if (n < 0)
	{
		size++;
		ln *= -1;
	}
	while (ln > 9)
	{
		size++;
		ln = ln / 10;
	}
	size++;
	return (size);
}

char	*put_itoa(char *c, int n, int size)
{
	long	un;

	un = (long)n;
	size--;
	if (n < 0)
	{
		c[0] = '-';
		un *= -1;
		while (size > 0)
		{
			c[size] = (un % 10) + '0';
			un /= 10;
			size--;
		}
	}
	else
	{
		while (size >= 0)
		{
			c[size] = (un % 10) + '0';
			un /= 10;
			size--;
		}
	}
	return (c);
}

char	*ft_itoa(int n)
{
	int				size;
	char			*c;

	size = find_size(n);
	c = (char *)malloc(sizeof(char) * (size + 1));
	if (!c)
		return (0);
	c = put_itoa(c, n, size);
	c[size] = '\0';
	return (c);
}
