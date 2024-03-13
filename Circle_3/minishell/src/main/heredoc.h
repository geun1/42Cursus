/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:49:06 by yback             #+#    #+#             */
/*   Updated: 2023/03/02 19:49:08 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include "../lexer/token.h"

void	expand_quote(t_string *str, t_iterator *iter, char quote_type);
bool	is_limiter(const char *line, const char *limiter);
char	*readline_prompt_heredoc(void);
int		set_heredoc(t_list *tokens);

#endif /* HEREDOC_H */
