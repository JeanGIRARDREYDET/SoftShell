/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:01:34 by jegirard          #+#    #+#             */
/*   Updated: 2024/10/14 11:01:41 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
//utiliser la fonction getcwd qui copie le chemin d'acces absolu du repertoire 
//de travail courant dans la chaine pointee par buf qui est de longueur size

#include "../minishell.h"

void	cd_home(t_sys *mi_sys)
{
	if (!mi_sys->senv.home)
	{
		ft_putstr_fd("cd: HOME not set\n", STDOUT_FILENO);
		return ;
	}
	mi_sys->senv.pwd = mi_sys->senv.home;
	mi_setenv("PWD", mi_sys->senv.home, mi_sys);
}

void	cd_back(t_sys *mi_sys)
{
	int	i;

	i = 0;
	mi_sys->senv.pwd = mi_getenv("PWD", mi_sys);
	if (!mi_sys->senv.pwd)
	{
		ft_putstr_fd ("cd: DIR not set\n", STDOUT_FILENO);
		return ;
	}
	while (mi_sys->senv.pwd[i])
			i++;
	while (mi_sys->senv.pwd[i] != '/' && i > 1)
		i--;
	mi_sys->senv.pwd = ft_substr(mi_sys->senv.pwd, 0, i);
}

void	mi_logerrorsys(int no, char *msg, t_sys *mi_sys)
{
	if (msg)
	{
		write(STDERR_FILENO, msg, ft_strlen(msg));
		write(STDERR_FILENO, "\n", 1);
	}
	mi_sys->error2 = mi_errornew(no, msg);
}

void	builtin_cd(char *key, t_sys *mi_sys)
{
	mi_sys->senv.oldpwd = mi_sys->senv.pwd;
	mi_setenv("OLDPWD", mi_sys->senv.oldpwd, mi_sys);
	if (key == NULL || key[0] == '\0')
		cd_home(mi_sys);
	else if (ft_strncmp(key, "..", 3) == 0)
		cd_back(mi_sys);
	else
	{
		if (chdir(key))
		{
			mi_logerror(errno, strerror(errno), &mi_sys->error);
			mi_logerrorsys(errno, strerror(errno), mi_sys);
		}
		mi_sys->senv.pwd = getcwd(NULL, 0);
		mi_setenv("PWD", getcwd(NULL, 0), mi_sys);
	}
	if (access(mi_sys->senv.pwd, F_OK) == 0)
	{
		if ( chdir(mi_sys->senv.pwd))
			mi_logerror(errno, strerror(errno), &mi_sys->error);
		mi_setenv("PWD", getcwd(NULL, 0), mi_sys);
		// ft_putstr_fd("cd: DIR not set\n" ,STDOUT_FILENO);
		mi_sys->exit_status = EXIT_SUCCESS;
	}
	else
	{
		perror("access");
		mi_sys->exit_status = EXIT_FAILURE;
	}
}
