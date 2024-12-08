/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard  <jegirard@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:38:34 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/07 13:24:53 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cd_home(char **new_pwd, t_sys *mi_sys)
{
	if (!mi_sys->senv->home)
	{
		mi_logerror(1, "cd: HOME not set", mi_sys);
		*new_pwd = ft_strdup("");
		return ;
	}
	*new_pwd = ft_strdup(mi_sys->senv->home);
}

void	cd_back(char **new_pwd, int fd, t_sys *mi_sys)
{
	if (!mi_sys->senv->oldpwd)
	{
		mi_logerror(1, "cd: OLDPWD not set", mi_sys);
		*new_pwd = ft_strdup("");
		return ;
	}
	*new_pwd = ft_strdup(mi_sys->senv->oldpwd);
	write(fd, mi_sys->senv->oldpwd, ft_strlen(mi_sys->senv->oldpwd));
	write(fd, "\n", 1);
}

void	cd_parent(char **new_pwd, t_sys *mi_sys)
{
	int		i;
	char	*back;

	i = 0;
	back = getcwd(NULL, 0);
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
	free(back);
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
