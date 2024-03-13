/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handle.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:49:42 by yback             #+#    #+#             */
/*   Updated: 2023/03/02 19:49:44 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_HANDLE_H
# define SIGNAL_HANDLE_H

# include "signal_handle.h"
# include "minishell.h"

void	*new_pid(pid_t pid);
void	del_pid(void *content);

/* Waits every pids in config->pid_list.
 * then saves wstatus of last_cmd_pid to config->last_cmd_wstatus */
void	wait_every_pid(t_shell_config *config);

#endif /* SIGNAL_HANDLE_H */
