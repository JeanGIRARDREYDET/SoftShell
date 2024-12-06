/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_sysinitialization.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <jegirard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:12:48 by doferet           #+#    #+#             */
/*   Updated: 2024/10/20 18:34:59 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	read_env_line(char *line, t_sys *mi_sys)
{
	char	*tmp;

	if (ft_strnstr (line, "PATH=", 5) != 0)
		mi_sys->senv->path = line + 5;
	if (ft_strnstr (line, "PWD=", 4) != 0)
		mi_sys->senv->pwd = ft_strdup(line + 4);
	if (ft_strnstr (line, "OLDPWD=", 7) != 0)
		mi_sys->senv->oldpwd = ft_strdup(line + 7);
	if (ft_strnstr (line, "HOME=", 5) != 0)
		mi_sys->senv->home = line + 5;
	if (ft_strnstr (line, "SHLVL=", 6) != 0)
	{
		if (mi_sys->senv->shlvl != NULL)
			free(mi_sys->senv->shlvl);
		tmp = ft_itoa(1 + ft_atoi(line + 6));
		mi_sys->senv->shlvl = ft_strdup(tmp);
		free(tmp);
	}
	if (ft_strnstr (line, "_=", 2) != 0)
		mi_sys->senv->_ = line + 2;
}

int	read_env(char **env, t_sys *mi_sys)
{
	mi_sys->senv->shlvl = ft_strdup("1");
	mi_sys->len_env = 0;
	while (env[mi_sys->len_env])
	{
		read_env_line(env[mi_sys->len_env], mi_sys);
		mi_sys->len_env++;
	}
	mi_sys->len_env++;
	if (mi_sys->senv->pwd == 0)
		mi_sys->len_env++;
	if (mi_sys->senv->shlvl == NULL)
		mi_sys->len_env++;
	if (mi_sys->senv->_ == 0)
		mi_sys->len_env++;
	return (mi_sys->len_env);
}

void	mi_setdefaul_initialization( t_sys *mi_sys)
{
	mi_sys->senv = (t_env*) ft_calloc (1, sizeof (t_env));
	mi_sys->senv->path = "/usr/bin:/bin:/usr/sbin:/sbin";
	mi_sys->senv->pwd = NULL;
	mi_sys->nb_pipe = 0;
	mi_sys->cmd = NULL;
	mi_sys->senv->shlvl = NULL;
	mi_sys->senv->_ = NULL;
	mi_sys->senv->home = NULL;
	mi_sys->len_env = 0;
	mi_sys->fd_in = STDIN_FILENO;
	mi_sys->error = NULL;
	mi_sys->exit_status = 0;
}

void	mi_sysinitialization(char **env, t_sys *mi_sys)
{
	int		i;
	char	**ienv;
	bool	shlvl;

	shlvl = false;
	mi_setdefaul_initialization(mi_sys);
	mi_sys->len_env = read_env(env, mi_sys);
	ienv = (char **)ft_calloc(mi_sys->len_env, sizeof(char *));
	i = -1;
	while (env[++i])
	{
		if (ft_strnstr (env[i], "SHLVL=", 6) != 0 && !shlvl)
		{
			ienv[i] = ft_strjoin("SHLVL=", mi_sys->senv->shlvl);
			shlvl = true;
		}
		if (ft_strnstr (env[i], "SHLVL=", 6) == 0)
			ienv[i] = ft_strdup(env[i]);
	}
	if (mi_sys->senv->pwd == NULL)
	{
		ft_sys_get_pwd(&mi_sys->senv->pwd);
		ienv[i++] = ft_strjoin("PWD=", mi_sys->senv->pwd);
	}
	if (!shlvl)
		ienv[i++] = ft_strjoin("SHLVL=", mi_sys->senv->shlvl);
	mi_sys->env = ienv;
	mi_sys->len_env = i;
	mi_sys->nb_error = 0;
}
