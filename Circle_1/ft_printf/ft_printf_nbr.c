/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:05:10 by gsong             #+#    #+#             */
/*   Updated: 2022/08/25 14:41:52 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	cnt;

	cnt = 0;
	while (s[cnt])
		cnt++;
	return (cnt);
}

char	*baseset(char type)
{
	if (type == 'i' || type == 'd' || type == 'u')
		return ("0123456789");
	if (type == 'x' || type == 'p')
		return ("0123456789abcdef");
	if (type == 'X')
		return ("0123456789ABCDEF");
	return (0);
}

int	ft_nbr_base(long long nbr, char *base, int base_size)
{
	char	stack[12];
	int		i;
	int		result;

	i = 0;
	if (nbr < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		nbr *= -1;
	}
	while (nbr)
	{
		stack[i++] = base[nbr % base_size];
		nbr /= base_size;
	}
	result = i--;
	while (i >= 0)
		if (write(1, &stack[i--], 1) == -1)
			return (-1);
	return (result);
}

int	ft_strlen_base(long long nbr, int type)
{
	int	cnt;

	cnt = 1;
	if (nbr < 0)
	{
		nbr *= -1;
		cnt++;
	}
	while (1)
	{
		if (nbr < type)
			break ;
		nbr /= type;
		cnt++;
	}
	return (cnt);
}

int	print_nbr(long long nbr, const char type)
{
	int		len;
	char	*base;
	int		base_size;

	len = 0;
	base = baseset(type);
	base_size = ft_strlen(base);
	if (nbr == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	if (ft_nbr_base(nbr, base, base_size) == -1)
		return (-1);
	if (type == 'x' || type == 'X')
		len = ft_strlen_base(nbr, 16);
	if (type == 'd' || type == 'i' || type == 'u')
		len = ft_strlen_base(nbr, 10);
	return (len);
}
