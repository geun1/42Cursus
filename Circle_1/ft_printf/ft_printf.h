/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:00:52 by gsong             #+#    #+#             */
/*   Updated: 2022/08/25 14:24:30 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		print_c(char c);
int		print_s(char *s);
int		print_p(unsigned long int p);
size_t	ft_strlen(const char *s);
char	*baseset(char type);
int		ft_nbr_base(long long nbr, char *base, int base_size);
int		ft_strlen_base(long long nbr, int type);
int		print_nbr(long long nbr, const char type);
int		ft_check_fmt(char c, va_list *ap);
int		ft_printf(const char *fmt, ...);
#endif