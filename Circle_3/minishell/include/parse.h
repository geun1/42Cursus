/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:38:59 by yback             #+#    #+#             */
/*   Updated: 2023/03/02 19:39:00 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PARSE_H
# define PARSE_H

# include "../src/parser/parse_tree.h"

/* @ Convert tokens lists to Abstract Syntax tree 
 *
 * NOTE : must use 'delete_tree_node()' while traversing each node!
 *
 * */
extern t_tree	*parse(t_list *tokens);

#endif /* PARSE_H */
