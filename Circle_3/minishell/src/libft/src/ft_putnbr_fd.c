/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:46:31 by yback             #+#    #+#             */
/*   Updated: 2023/03/02 19:46:35 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static int	ft_pow(unsigned int num, int power)
{
	int	result;

	if (power < 0)
		return (-1);
	result = 1;
	while (power-- > 0)
		result *= num;
	return (result);
}

void	ft_putnbr_fd(int n, int fd)
{
	size_t			nbr_len;
	char			digit;
	unsigned int	divider;
	unsigned int	n_tmp;

	n_tmp = n;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n_tmp = -n;
		write(fd, "-", 1);
	}
	nbr_len = ft_nbrlen(n_tmp);
	while (nbr_len > 0)
	{
		divider = ft_pow(10, nbr_len - 1);
		digit = (n_tmp / divider) + '0';
		n_tmp %= divider;
		nbr_len--;
		write(fd, &digit, 1);
	}
}
