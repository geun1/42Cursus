/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:49:13 by yback             #+#    #+#             */
/*   Updated: 2023/03/02 19:49:15 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include "../../include/libft.h"

# define READ	(0)
# define WRITE	(1)

typedef struct s_shell_config
{
	char	***envp;
	int		stdin_backup;
	int		stdout_backup;
	pid_t	last_cmd_pid;
	int		last_cmd_wstatus;
	t_list	*pid_list;
}	t_shell_config;

typedef struct s_history
{
	char	*history;
	int		idx;
}	t_history;

void	load_shell_config(t_shell_config *shell_config, char **env);
int		run_shell(char *line, t_shell_config *config);
void	shell_loop(t_shell_config *config, t_history *history);
void	show_shell_logo(void);
void	sig_ctrl_c(int signal);
void	set_signal(void);
char	*readline_prompt(t_shell_config *config, t_history *history);
int		print_history(t_history *history);

#endif /* MINISHELL_H */