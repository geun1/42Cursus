/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 00:31:39 by song-geun-i       #+#    #+#             */
/*   Updated: 2022/08/25 14:41:53 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	print_s(char *s)
{
	int	len;	
	int	check_fail;

	len = 0;
	if (!s)
		s = "(null)";
	while (*s)
	{
		check_fail = write(1, s++, 1);
		if (check_fail == -1)
			return (-1);
		len++;
	}
	return (len);
}

int	print_p(unsigned long int p)
{
	int	len;

	len = 0;
	if (p >= 16)
	{
		len += print_p(p / 16);
		len += print_p(p % 16);
	}
	if (p < 16)
	{
		if (p < 10)
			len += print_c(p + 48);
		else
			len += print_c(p + 87);
	}
	return (len);
}

int	ft_check_fmt(char c, va_list *ap)
{
	if (c == 'c')
		return (print_c(va_arg(*ap, int)));
	else if (c == 's')
		return (print_s(va_arg(*ap, char *)));
	else if (c == 'p')
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		return (print_p(va_arg(*ap, unsigned long int)) + 2);
	}
	else if (c == 'd' || c == 'i')
		return (print_nbr(va_arg(*ap, int), c));
	else if (c == 'u' || c == 'x' || c == 'X')
		return (print_nbr(va_arg(*ap, unsigned int), c));
	else if (c == '%')
		return (print_c('%'));
	else
		return (-1);
}

int	ft_printf(const char *fmt, ...)
{
	int		len;
	int		check_fail;
	va_list	ap;

	len = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt != '%')
		{
			if (print_c(*fmt) == -1)
				return (-1);
			len++;
		}
		else
		{
			check_fail = ft_check_fmt((int)*++fmt, &ap);
			if (check_fail == -1)
				return (-1);
			len += check_fail;
		}
		fmt++;
	}
	va_end(ap);
	return (len);
}
