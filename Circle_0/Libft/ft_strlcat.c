/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:44:22 by gsong             #+#    #+#             */
/*   Updated: 2022/07/21 15:56:57 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_i;
	size_t	dst_i;
	size_t	src_len;
	size_t	dst_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	src_i = 0;
	dst_i = dst_len;
	if (dstsize <= dst_len)
		return (src_len + dstsize);
	while (src[src_i] && dst_i < dstsize - 1)
		dst[dst_i++] = src[src_i++];
	dst[dst_i] = '\0';
	return (src_len + dst_len);
}
