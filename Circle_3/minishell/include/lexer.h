/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:38:50 by yback             #+#    #+#             */
/*   Updated: 2023/03/02 19:38:52 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LEXER_H
# define LEXER_H

/* Libft functions */
# include "./libft.h"

/* t_string header */
# include "../src/string/string.h"
# include "../src/iterator/iterator.h"
# include "../src/lexer/token.h"
# include "../src/lexer/scanner.h"

/* @ Returns t_token list.
 * @ NOTE : doesn't check synstax error!
 * */
extern t_list	*tokenize(char *line);

#endif /* LEXER_H */
