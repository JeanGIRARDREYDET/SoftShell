/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <jegirard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:47:03 by doferet           #+#    #+#             */
/*   Updated: 2024/10/20 19:15:36 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <dirent.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>
# include <stdarg.h>
# include <string.h>
# include <stddef.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <linux/limits.h>
# include <stdbool.h>
# include "./libft/libft.h"

# define PIPE 1
# define HEREDOC 2
# define APPEND 3
# define INPUT 4
# define OUTPUT 5
# define SPE 6

# define WSPACE " \a\b\t\n\v\f\r"
# define TECHAP "\"'"
# define BUILTINS " echo cd pwd export unset env exit "

extern int	g_signal;

typedef struct s_env
{
	char			*oldpwd;
	char			*pwd;
	char			*path;
	char			*shlvl;
	char			*_;
	char			*home;
}	t_env;

typedef struct s_error
{
	int				code_error;
	char			*msg;
	struct s_error	*next;
}	t_error;

typedef struct s_redirection
{
	int						redir_type;
	int						fd_here_doc;
	char					*file_name;
	struct s_redirection	*next;
}	t_redirection;

typedef struct s_cmd
{
	int				id;
	int				no;
	char			*full_cmd;
	char			**split_cmd;
	char			*cmd;
	bool			cmd_found;
	char			*arg;
	char			*type;
	char			**args;
	bool			builtin;
	int				nb_error;
	t_error			*error;
	int				fd[2];
	t_redirection	*redirection;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_sys
{
	int				status;
	int				here_doc;
	int				nb_pipe;
	int				nb_herdoc;
	int				nb_error;
	char			**cmd_args;
	int				terror[2];
	int				code_error;
	t_error			*error;
	int				fd_in;
	t_env			*senv;
	char			**env;
	int				len_env;
	t_cmd			*cmd;
	int				exit_status;
}	t_sys;

void	mi_freesys(t_sys *mi_sys);
void	signal_handle_sigint(int sign);
bool	ft_findword(const char *source, const char *find);
void	builtin_cd(char *key, t_sys *s_sys);
void	builtin_echo(char *key);
void	builtin_env(t_sys *s_sys);
void	builtin_exit(t_sys *s_sys);
void	builtin_export(char *key, t_sys *s_sys);
void	print_export(t_sys *s_sys);
void	builtin_pwd(void);
void	builtin_unset(char *key, t_sys *s_sys);
void	mi_checkbuiltin(t_cmd *mi_cmd);
void	mi_checkpathaccess(t_cmd *mi_cmd, t_sys *mi_sys);
char	*mi_getenv(char *key, t_sys *s_sys);
void	mi_unset(char *key, t_sys *s_sys);
void	mi_sysinitialization(char **env, t_sys *s_sys);
int		mi_setenv(char *key, char *value, t_sys *s_sys);

t_error	*mi_errornew(int code_error, char *msg);
void	mi_exebuiltin(t_cmd *mi_cmd, t_sys *mi_sys);
void	mi_expand_interface(t_cmd *mi_cmd, t_sys *mi_sys);
void	mi_exec(t_cmd *me_cmd, t_sys *mi_sys);
void	mi_exefind(t_cmd *mi_cmd, t_sys *mi_sys);
void	mi_oneexec(t_cmd *me_cmd, t_sys *mi_sys);

void	mi_cmdparsse(t_cmd *me_cmd);
void	mi_cmdargparsse(t_cmd *lst);
void	mi_cmditer(t_cmd *lst, void (*f)(t_cmd *lst));
void	mi_syscmditer(t_sys *sys, void (*f)(t_cmd *lst, t_sys *sys));
void	mi_lexingline(char *ln, int i, t_cmd *me_cmd, t_sys *mi_sys);
int		mi_pospasscote(char *ln, int i, t_sys *mi_sys);
void	mi_logerror(int code_error, char *msg, t_sys *mi_sys);
void	mi_logerror2(int id, char *msg, t_error *mi_error);
void	mi_logerrorlong(int code, char *m1, char *m2, char *m3, t_sys *mi_sys);
int		mi_intlogerror(t_sys *mi_sys, char *s, int code);
void	mi_parseredirtocken(int *i, int *n, t_cmd *mi_cmd, t_sys *mi_sys);
char	*ft_findcommand(char *line);

void	mi_closecmd(t_cmd *mi_cmd, int nb);
t_cmd	*mi_createcmd(t_sys *mi_sys);
void	mi_execbuiltin(t_cmd *mi_cmd, t_sys *mi_sys);
int		mi_execcmd(t_cmd *mi_cmd, t_sys *mi_sys);
int		mi_execchild(t_cmd *mi_cmd, t_sys *mi_sys);
void	mi_exec(t_cmd *mi_cmd, t_sys *mi_sys);
void	mi_execone(t_cmd *mi_cmd, t_sys *mi_sys);
void	mi_freecmd(t_sys *mi_sys);
void	mi_waitingpipe(t_sys *mi_sys);
void	mi_cmdherdoc(t_cmd *mi_cmd);
void	mi_cmdsplitcmd(t_cmd *mi_cmd, t_sys *mi_sys);
char	*mi_getenv_env(char *key, char **env);

t_redirection	*mi_createredirection(int redir_type);

#endif
