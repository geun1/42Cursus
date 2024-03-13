/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 12:50:05 by seokang           #+#    #+#             */
/*   Updated: 2022/07/22 16:33:47 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long long n)
{
	int			i;

	i = 0;
	if (n <= 0)
	{
		i++;
		n *= (-1);
	}
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*result;
	int			n_len;
	long long	num;

	num = n;
	n_len = ft_intlen(num);
	result = malloc(sizeof(char) * (n_len + 1));
	if (!result)
		return (0);
	result[n_len] = '\0';
	if (num < 0)
	{
		num *= (-1);
		result[0] = '-';
	}
	if (num == 0)
		result[0] = '0';
	while (num)
	{
		result[--n_len] = num % 10 + '0';
		num /= 10;
	}
	return (result);
}
