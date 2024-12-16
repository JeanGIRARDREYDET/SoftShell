/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_sysinitialization.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard  <jegirard@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:38:34 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/07 13:24:53 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mi_setdefaul_initialization( t_sys *mi_sys)
{
	mi_sys->senv = (t_env *) ft_calloc (1, sizeof (t_env));
	mi_sys->senv->path = "/usr/bin:/bin:/usr/sbin:/sbin";
	mi_sys->senv->pwd = getcwd(NULL, 0);
	mi_sys->nb_pipe = 0;
	mi_sys->cmd = NULL;
	mi_sys->senv->shlvl = 0;
	mi_sys->senv->_ = NULL;
	mi_sys->senv->home = NULL;
	mi_sys->len_env = 0;
	mi_sys->fd_in = STDIN_FILENO;
	mi_sys->error = NULL;
	mi_sys->exit_status = 0;
	mi_sys->code_error = 0;
}

void	mi_sysinitialization(char **env, t_sys *mi_sys)
{
	int		i;
	
	i = 0;
	mi_setdefaul_initialization(mi_sys);
	mi_sys->len_env = 0;
	while (env[mi_sys->len_env])
		mi_sys->len_env++;
	mi_sys->len_env=-1;
	mi_sys->env = (char **)ft_calloc(0 , sizeof(char *));
	s_env_create_update_key_value("SHLVL", "0", mi_sys);
	s_env_create_update_key_value("PWD", mi_sys->senv->pwd, mi_sys);
	while (env[i])
	{
		dprintf(2,"env[i] = %s\n", env[i]);
		s_env_create_update_value (env[i], mi_sys);
		i++;
	}
	mi_sys->senv->shlvl = 1 + ft_atoi(mi_getenv("SHLVL", mi_sys));
	s_env_create_update_key_value("SHLVL",ft_itoa(mi_sys->senv->shlvl), mi_sys);
	mi_sys->nb_error = 0;
}
