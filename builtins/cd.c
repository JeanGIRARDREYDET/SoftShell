/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <jegirard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:01:34 by jegirard          #+#    #+#             */
/*   Updated: 2024/11/26 22:41:24 by jegirard         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../minishell.h"
//utiliser la fonction getcwd qui copie le chemin d'acces absolu du repertoire 
//de travail courant dans la chaine pointee par buf qui est de longueur size

void	cd_home(char **new_pwd, t_sys *mi_sys)
{
	char	*home;

	home = mi_getenv("HOME", mi_sys);
	if (!home)
	{
		mi_logerror(1, "cd: HOME not set", mi_sys);
		*new_pwd = ft_strdup("");
		return ;
	}
	*new_pwd = ft_strdup(home);
}

void	cd_back(char **new_pwd, int fd, t_sys *mi_sys)
{
	char	*home;

	home = mi_getenv("OLDPWD", mi_sys);
	if (!home)
	{
		mi_logerror(1, "cd: OLDPWD not set", mi_sys);
		*new_pwd = ft_strdup("");
		return ;
	}
	*new_pwd = ft_strdup(home);
	builtin_pwd(fd);
}

void	cd_parent(char **new_pwd, t_sys *mi_sys)
{
	int		i;
	char	*back;

	i = 0;
	back = mi_getenv("PWD", mi_sys);
	if (!back)
	{
		mi_logerror(1, "cd: curent DIR not set", mi_sys);
		*new_pwd = ft_strdup("");
		return ;
	}
	while (back[i])
			i++;
	while (back[i] != '/' && i > 1)
		i--;
	*new_pwd = ft_substr(back, 0, i);
}
char	*cd_getpwd(char *key, int fd, t_sys *mi_sys)
{
	char	*new_pwd;

	if (key == NULL || key[0] == '\0')
		cd_home(&new_pwd, mi_sys);
	else if (ft_strncmp(key, "..", 3) == 0)
		cd_parent(&new_pwd, mi_sys);
	else if (ft_strncmp(key, "-", 3) == 0)
		cd_back(&new_pwd, fd, mi_sys);
	else
		new_pwd = ft_strdup(key);
	return (new_pwd);
}

void	builtin_cd(char **key, int fd, t_sys *mi_sys)
{
	char	*tmp_pwd;
	char	*new_pwd;

	new_pwd = cd_getpwd(key[1], fd, mi_sys);
	if (*new_pwd != '\0' && access(new_pwd, F_OK) == 0 && chdir(new_pwd) == 0)
	{
		tmp_pwd = ft_strjoin("OLDPWD=", mi_getenv("PWD", mi_sys));
		s_env_create_update_value (tmp_pwd, mi_sys);
	//	mi_export_values({"dd",tmp_pwd}, mi_sys);
	//	free(tmp_pwd);
		mi_setenv("OLDPWD", mi_getenv("PWD", mi_sys), mi_sys);
		tmp_pwd = getcwd(NULL, 0);
		mi_setenv("PWD", tmp_pwd, mi_sys);
	//	free(tmp_pwd);
		mi_sys->exit_status = EXIT_SUCCESS;
	}
	else if (*new_pwd != '\0')
	{
		// perror("access");
		mi_logerror(1, "No such file or directory", mi_sys);
		mi_sys->exit_status = EXIT_FAILURE;
	}
//	free(new_pwd);
}
