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

typedef struct s_sys
{
	int		duplexe_canal[2];
	int		fdd[2][2];
	int		pid;
	int		status;
	int		here_doc;
	char	*pwd;
	char	*path;
	char	*SHLVL;
	char	**cmd_args;
	char	**env;
	char	*exe[5];
	char	*cmd;
	int		error[2];
}	t_sys;

void	builtin_env(t_sys *sys);
void	builtin_pwd(t_sys *sys);
void	common_initialization(char **env, t_sys *sys);
char	*ft_strdup(const char *s);
char	*ft_strnstr(const char *source, const char *find, size_t len);
size_t	ft_strlen(char const *s);

#endif
