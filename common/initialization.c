/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:12:48 by doferet           #+#    #+#             */
/*   Updated: 2024/09/10 14:42:11 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_sys_get_pwd()
	{
	char buffer[PATH_MAX];
	if ( getcwd( buffer, PATH_MAX ) == NULL )
	{
		fprintf( stderr, "Cannot get current working directory path\n" );
		if ( errno == ERANGE ) {
			fprintf( stderr, "Buffer size is too small.\n" );
		}
		exit( EXIT_FAILURE );
	}
	return (stderr);
}

void	common_initialization(char **env, t_sys *s_sys)
{
	int		i;
	char	**ienv;

	s_sys->shlvl = "0";
	s_sys->env_len = 0;
	while (env[s_sys->env_len])
	{
		if (ft_strnstr (env[s_sys->env_len], "PATH=", 5) != 0)
			s_sys->path = env[s_sys->env_len] + 5;
		if (ft_strnstr (env[s_sys->env_len], "PWD=", 4) != 0)
			s_sys->pwd = env[s_sys->env_len] + 4;
		if (ft_strnstr (env[s_sys->env_len], "SHLVL=", 6) != 0)
			s_sys->shlvl = ft_itoa((1 + ft_atoi(env[s_sys->env_len] + 6)));
		if (ft_strnstr (env[s_sys->env_len], "_=", 2) != 0)
			s_sys->_ = env[s_sys->env_len] + 2;
		s_sys->env_len++;
	}
	s_sys->env_len++;
	if	(s_sys->pwd == 0)
	{
		s_sys->pwd;
		s_sys->env_len++;
	}
		
	if(s_sys->shlvl == 0)
		s_sys->env_len++;
	if(s_sys->_ == 0)
		s_sys->env_len++;
	ienv = (char **)ft_calloc(s_sys->env_len, sizeof(char *));
	i = -1;
	while (env[++i])
	{
		if (ft_strnstr (env[i], "SHLVL=", 6) != 0)
			ienv[i] = ft_strjoin("SHLVL=", s_sys->shlvl);
		else
			ienv[i] = ft_strdup(env[i]);
	}
	if	(s_sys->pwd == 0)
		ienv[i++] = ft_strjoin("PWD=",ft_sys_get_pwd());




	s_sys->env = ienv;
}
