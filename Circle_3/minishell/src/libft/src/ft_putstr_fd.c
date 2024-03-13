/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:46:40 by yback             #+#    #+#             */
/*   Updated: 2023/03/02 19:46:42 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/* NOTE : Dangerous if write() error occures!! */
extern size_t	ft_strlen(const char *str);

/* NOTE : Paritial write && write() error handling */
void	ft_putstr_fd(char *string, int fd)
{
	size_t	idx;
	size_t	len;
	ssize_t	writed_bytes;

	idx = 0;
	len = ft_strlen(string);
	while (idx < len)
	{
		writed_bytes = write(fd, &string[idx], len);
		if (writed_bytes < 0)
			return ;
		idx += writed_bytes;
	}
}
