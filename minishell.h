/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:09:10 by doferet           #+#    #+#             */
/*   Updated: 2024/09/06 10:18:30 by doferet          ###   ########.fr       */
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
# include "./libft/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <string.h>
# include <stddef.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <linux/limits.h>

typedef struct s_env
{
	int		len;
	char	*oldpwd;
	char	*pwd;
	char	*path;
	char	*shlvl;
	char	*_;
	char	*home;
}	t_env;

typedef struct s_sys
{
	int		duplexe_canal[2];
	int		fdd[2][2];
	int		pid;
	int		status;
	int		here_doc;
	char	**cmd_args;
	char	*exe;
	char	*cmd;
	int		error[2];
	t_env	senv;
	char	**env;
	struct s_sys	*next;
}	t_sys;

void	builtin_cd(char *key, t_sys *s_sys);
void	builtin_echo(char *key, t_sys *s_sys);
void	builtin_env(t_sys *sys);
void	builtin_exit(t_sys *sys);
void	builtin_export(char *key, t_sys *s_sys);
void	builtin_pwd(void);
void	builtin_unset(char *line, t_sys *sys);
char	*s_getenv(char *key, t_sys *s_sys);

void	common_initialization(char **env, t_sys *sys);
char	*s_getenv(char *key, t_sys *s_sys);
int		s_setenv(char *key, char *value, t_sys *s_sys);

#endif
