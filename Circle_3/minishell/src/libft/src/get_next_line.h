/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:48:19 by yback             #+#    #+#             */
/*   Updated: 2023/03/02 19:48:21 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>

/* for default BUFFER_SIZE */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

/* Return a line read from a file descriptor, NULL if there is 
 * nothing else to read, or an error occurred */
extern char		*get_next_line(int fd);

typedef struct s_array {
	size_t	size;
	size_t	capacity;
	char	*data;
	char	last_data;
}				t_array;

extern void		*memcpy_gnl(void *dst, const void *src, size_t n);
extern t_array	*new_array_malloc(t_array **array, size_t init_capacity);
extern char		*new_str_malloc(size_t init_size);
extern void		push_back_array(t_array *const array, int c);
extern void		reserve_array(t_array *const array, size_t new_capacity);

#endif
