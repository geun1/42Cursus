/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:48:58 by yback             #+#    #+#             */
/*   Updated: 2023/03/02 19:49:00 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>

#include "../lexer/token.h"

void	expand_quote(t_string *str, t_iterator *iter, char quote_type)
{
	char	c;

	while (iter->f_has_next(iter))
	{
		c = iter->f_next(iter);
		if (c == quote_type)
			return ;
		else
			str->f_push_back(str, c);
	}
}

bool	is_limiter(const char *line, const char *limiter)
{
	if (ft_strlen(line) == ft_strlen(limiter)
		&& !ft_strncmp(line, limiter, ft_strlen(limiter)))
		return (true);
	else
		return (false);
}

char	*readline_prompt_heredoc(void)
{
	t_string	*prompt;
	static char	*line;

	prompt = new_string(64);
	prompt->f_append(prompt, "\033[31m");
	prompt->f_append(prompt, "heredoc");
	prompt->f_append(prompt, "\033[0m");
	prompt->f_append(prompt, "$ ");
	line = readline(prompt->text);
	delete_string(&prompt);
	return (line);
}
