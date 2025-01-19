/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:38:34 by jegirard          #+#    #+#             */
/*   Updated: 2025/01/17 16:12:49 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cd_error(t_sys *mi_sys)
{
	mi_logerror (1, "No such file or directory", mi_sys);
	mi_sys->exit_status = EXIT_FAILURE;
}

void	builtin_cdrun(char **key, int fd, t_sys *mi_sys)
{
	char	*start_pwd;
	char	*new_pwd;

	start_pwd = getcwd(NULL, 0);
	new_pwd = cd_getpwd(key[1], fd, mi_sys);
	if (*new_pwd != '\0' && access(new_pwd, F_OK) == 0 && chdir(new_pwd) == 0)
	{
		s_env_create_update_key_value("OLDPWD", start_pwd, mi_sys);
		if (mi_sys->senv->oldpwd)
			free(mi_sys->senv->oldpwd);
		mi_sys->senv->oldpwd = ft_strdup(start_pwd);
		free(new_pwd);
		new_pwd = getcwd(NULL, 0);
		mi_setenv("PWD", new_pwd, mi_sys);
		s_env_create_update_key_value("PWD", new_pwd, mi_sys);
		if (mi_sys->senv->pwd)
			free(mi_sys->senv->pwd);
		mi_sys->senv->pwd = ft_strdup(new_pwd);
		mi_sys->exit_status = EXIT_SUCCESS;
	}
	else if (*new_pwd != '\0')
		cd_error(mi_sys);
	free(start_pwd);
	free(new_pwd);
}

void	builtin_cd(char **key, int fd, t_sys *mi_sys)
{
	if (ft_tablen(key) > 2)
	{
		mi_logerror(1, "too many arguments", mi_sys);
		return ;
	}
	builtin_cdrun(key, fd, mi_sys);
}
