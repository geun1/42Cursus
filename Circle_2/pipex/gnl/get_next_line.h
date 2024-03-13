/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:54:38 by gsong             #+#    #+#             */
/*   Updated: 2023/01/11 20:54:38 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE   42
# endif

/* get_next_line.c */
char	*get_next_line(int fd);

/* get_next_line_utils.c */
int		gnl_strlen(const char *s);
int		gnl_strchr(char *s);
char	*gnl_strjoin(char *s1, char *s2);

#endif
