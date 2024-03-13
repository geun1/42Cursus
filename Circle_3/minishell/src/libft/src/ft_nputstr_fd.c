/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nputstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:45:53 by yback             #+#    #+#             */
/*   Updated: 2023/03/02 19:45:55 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_nputstr_fd(const char *string, int fd, size_t n)
{
	size_t	idx;
	ssize_t	writed_bytes;
	size_t	len;

	len = ft_strlen(string);
	if (n > len)
		n = len;
	idx = 0;
	while (idx < n)
	{
		writed_bytes = write(fd, &string[idx], n);
		if (writed_bytes < 0)
			return ;
		idx += writed_bytes;
	}
}
