/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:38:45 by yback             #+#    #+#             */
/*   Updated: 2023/03/02 19:38:48 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef EXECUTE_H
# define EXECUTE_H

# include "../src/executer/executer.h"

/* @ Traverse tokens lists, then execute each node's simple command.
 * returns (0) on error. 
 * else, function returns (1):success
 * */

extern int	execute(t_tree *syntax_tree, t_shell_config *config);

#endif /* EXECUTE_H */
