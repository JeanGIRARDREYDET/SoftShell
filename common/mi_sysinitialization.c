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

void	mi_checkmsargument(int argc, char **argv)
{
	if (argc > 1)
	{
		write (2, "Error: minishell does not take arguments. Try: ", 47);
		write (2, argv[0], ft_strlen(argv[0]));
		write (2, "\n", 1);
		exit(0);
	}
}

void	mi_setdefaul_initialization( t_sys *mi_sys)
{
	mi_sys->senv = (t_env *) ft_calloc (1, sizeof (t_env));
	mi_sys->senv->path = "/usr/bin";
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

void	mi_init_shlvl(t_sys *mi_sys)
{
	int		new_shlvl;
	char	*shlvl;

	new_shlvl = 1;
	if (mi_getenv("SHLVL", mi_sys))
		new_shlvl = 1 + ft_atoi(mi_getenv("SHLVL", mi_sys));
	shlvl = ft_itoa(new_shlvl);
	s_env_create_update_key_value("SHLVL", shlvl, mi_sys);
	free(shlvl);
}

void	mi_sysinitialization(char **env, t_sys *mi_sys, int argc, char **argv)
{
	int		i;

	i = 0;
	mi_checkmsargument(argc, argv);
	mi_setdefaul_initialization(mi_sys);
	mi_sys->len_env = 0;
	while (env[mi_sys->len_env])
		mi_sys->len_env++;
	mi_sys->len_env = -1;
	mi_sys->env = (char **)ft_calloc(0, sizeof(char *));
	s_env_create_update_key_value("SHLVL", "0", mi_sys);
	s_env_create_update_key_value("PWD", mi_sys->senv->pwd, mi_sys);
	s_env_create_update_key_value("_", "/usr/bin/env", mi_sys);
	while (env[i])
	{
		s_env_create_update_value (env[i], mi_sys);
		i++;
	}
	mi_init_shlvl(mi_sys);
	mi_sys->nb_error = 0;
}
