/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tree_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:49:46 by yback             #+#    #+#             */
/*   Updated: 2023/03/02 19:49:48 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_tree.h"

bool	is_type_redir_arg(t_list *target_next)
{
	t_token	*tok;

	tok = target_next->content;
	if (tok->type == E_TYPE_REDIR_ARG \
			|| tok->type == E_TYPE_REDIR_ARG_HEREDOC_QUOTED)
		return (true);
	else
		return (false);
}
