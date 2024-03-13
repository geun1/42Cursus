/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:26:16 by song-geun-i       #+#    #+#             */
/*   Updated: 2022/07/25 16:21:03 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	long long	i;
	int			len;

	i = n;
	len = 1;
	if (i < 0)
	{
		i *= -1;
		len++;
	}
	while (i >= 10)
	{
		i /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long long	num;
	int			len;
	char		*result;

	num = n;
	len = ft_intlen(n);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	if (num == 0)
		result[0] = '0';
	if (num < 0)
	{
		result[0] = '-';
		num *= -1;
	}
	result[len] = '\0';
	while (num)
	{
		result[--len] = num % 10 + '0';
		num /= 10;
	}
	return (result);
}
