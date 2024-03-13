/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 20:46:26 by gsong             #+#    #+#             */
/*   Updated: 2023/09/05 02:17:48 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
// open
# include <stdlib.h>
// exit, malloc, free
# include <stdio.h>
// perror
# include <string.h>
// strerror
# include <unistd.h>
// access, unlink, close, read, wait, pipe, dup, dup2, execve
# include <sys/wait.h>
// fork, waitpid

/* to libft */
# include "../libft/libft.h"

/* to gnl */
# include "../gnl/get_next_line.h"

# define ERR_ARGC "\033[31mError: Bad argument\n\e[0m\
Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n"
# define ERR_OUTFILE "\033[31mError: outfile error\n\e[0m"
# define ERR_INFILE "\033[31mError: infile error\n\e[0m"
# define ERR_PIPE "\033[31mError: pipe error\n\e[0m"
# define ERR_MALLOC "\033[31mError: malloc error\n\e[0m"
# define ERR_ENVP "\033[31mError: envp error\n\e[0m"
# define ERR_CMD "\033[31mError: Command not found\n\e[0m"
# define ERR_DUP2 "\033[31mError: dup2 error\n\e[0m"
# define ERR_WAITPID "\033[31mError: waitpid error\n\e[0m"
# define ERR_HEREDOC "\033[31mError: heredoc error\n\e[0m"
/* exit num define */
# define EXIT_ERROR 1
# define EXIT_NORMAL 0
# define EXIT_FAIL 0
# define EXIT_ENVP 0

/* open chmod num define */
# define O_CREATE_CHMOD 0644

typedef struct s_cmd
{
	char	**cmd;
	char	*path;
}			t_cmd;

typedef struct s_info
{
	char			**envp;
	char			**path;
	char			**hd_cmd;
	int				here_doc;
	int				*pipe_fd;
	int				input_fd;
	int				output_fd;
	int				result;
	int				idx;
	int				n_cmd;
	pid_t			pid;
	struct s_cmd	*i_cmd;
}					t_info;

/* main.c */
/* fd.c */
void	get_fd(t_info *info, int ac, char **av);
void	close_fd(t_info *info);
/* parse.c */
void	parsing(t_info *info, int ac, char **av);
void	check_cmd(t_info *info, char **av);
char	*get_cmd_av(char **path, char *cmd);
void	quotes(char **av, int i, t_info *info);
void	quotes2(t_info *info, char **tmp_info, int i, int tmp);
/* utils.c */
void	perror_exit(char *msg, int code);
void	close_pipes(t_info *info);
char	*find_path(char **envp);
void	clean_free(char **to_free);

#endif
