/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:50:17 by yback             #+#    #+#             */
/*   Updated: 2023/03/02 19:50:19 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

int	str_clear(t_string *str)
{
	if (str_is_empty(str))
		return (NO_ACTION);
	ft_bzero(str->text, str->capacity);
	str->text_len = 0;
	return (SUCCESS);
}

int	str_shrink_to_fit(t_string *str)
{
	if (str->text_len >= (str->capacity - 1))
		return (NO_ACTION);
	if (str_reserve(str, str->text_len + 1) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}

int	str_is_empty(t_string *str)
{
	if (str->text_len == 0)
		return (true);
	else
		return (false);
}
