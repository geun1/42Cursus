/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:38:41 by yback             #+#    #+#             */
/*   Updated: 2023/03/02 19:38:43 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUILTIN_H
# define BUILTIN_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/errno.h>

# include "../src/builtin/environ.h"
# include "libft.h"
# include "../src/main/minishell.h"

/* --------------------------------------------
 * |  NOTE : Environment variable functions   |
 * -------------------------------------------*/

/** deep copy system envp content */
char	**new_environ(char **system_envp);

/** free every environs */
void	delete_environ(char ***our_envp_ptr);

/** find Key in envp list, then return pointer to Value. 
 * NOTE : if no Key exists, then function returns NULL */
char	*get_environ_value(const char *env_key, char **envp);

/* --------------------------------------------
 * |  NOTE : Builtin functions                |
 * -------------------------------------------*/

int		exec_export(char **arglist, char ***our_envp_ptr);
int		exec_env(char **arglist, char **our_envp);
int		exec_unset(char **arglist, char ***our_envp_ptr);
int		exec_cd(char **arglist, char ***our_envp_ptr);
int		exec_echo(char **arglist, char **our_envp);
int		exec_pwd(char **arglist, char **our_envp);
int		exec_exit(char **arglist, char **our_envp, t_shell_config *config);

#endif /* BUILTIN_H */
