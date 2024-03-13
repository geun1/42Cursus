/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:41:09 by yback             #+#    #+#             */
/*   Updated: 2023/03/02 19:41:12 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H

# include "../main/minishell.h"
# include "../lexer/token.h"

char	*expand_line_each(char *line, t_shell_config *config);
int		expand_file(t_token *tok, t_shell_config *config);

#endif/* REDIRECTION_H */
