/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_sysinitialization.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <jegirard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:12:48 by doferet           #+#    #+#             */
/*   Updated: 2024/10/20 18:34:59 by jegirard         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../minishell.h"

void	read_env_line(char *line, t_sys *s_sys)

{
	if (ft_strnstr (line, "PATH=", 5) != 0)
		s_sys->senv.path = line + 5;
	if (ft_strnstr (line, "PWD=", 4) != 0)
		s_sys->senv.pwd = line + 4;
	if (ft_strnstr (line, "HOME=", 5) != 0)
		s_sys->senv.home = line + 5;
	if (ft_strnstr (line, "SHLVL=", 6) != 0)
		s_sys->senv.shlvl = ft_itoa((1 + ft_atoi(line + 6)));
	if (ft_strnstr (line, "_=", 2) != 0)
		s_sys->senv._ = line + 2;
}

int	read_env(char **env, t_sys *s_sys)
{
	s_sys->senv.shlvl = "1";
	s_sys->senv.len = 0;
	while (env[s_sys->senv.len])
	{
		read_env_line(env[s_sys->senv.len], s_sys);
		s_sys->senv.len++;
	}
	s_sys->senv.len++;
	if (s_sys->senv.pwd == 0)
		s_sys->senv.len++;
	if (s_sys->senv.shlvl == NULL)
		s_sys->senv.len++;
	if (s_sys->senv._ == 0)
		s_sys->senv.len++;
	return (s_sys->senv.len);
}

void	mi_setdefaul_initialization( t_sys *s_sys)
{
	s_sys->senv.path = "/usr/bin:/bin:/usr/sbin:/sbin";
	s_sys->senv.pwd = NULL;
	s_sys->nb_pipe = 0;
	s_sys->senv.shlvl = "1";
	s_sys->senv._ = NULL;
	s_sys->senv.home = NULL;
	s_sys->senv.len = 0;
	s_sys->fd_in = STDIN_FILENO;
}

void	mi_sysinitialization(char **env, t_sys *s_sys)
{
	int		i;
	char	**ienv;
	bool	shlvl;

	shlvl = false;
	mi_setdefaul_initialization(s_sys);
	s_sys->senv.len = read_env(env, s_sys);
	ienv = (char **)ft_calloc(s_sys->senv.len + 1, sizeof(char *));
	i = -1;
	while (env[++i])
	{
		if (ft_strnstr (env[i], "SHLVL=", 6) != 0 && !shlvl)
		{
			ienv[i] = ft_strjoin("SHLVL=", s_sys->senv.shlvl);
			shlvl = true;
		}
		if (ft_strnstr (env[i], "SHLVL=", 6) == 0)
			ienv[i] = ft_strdup(env[i]);
	}
	if (s_sys->senv.pwd == NULL)
	{
		ft_sys_get_pwd(&s_sys->senv.pwd);
		ienv[i++] = ft_strjoin("PWD=", s_sys->senv.pwd);
	}
	if(!shlvl)
		ienv[i++] = ft_strjoin("SHLVL=", s_sys->senv.shlvl);
	s_sys->env = ienv;
	s_sys->senv.len = i;
}
