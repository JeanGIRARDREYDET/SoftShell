/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:46:02 by doferet           #+#    #+#             */
/*   Updated: 2024/09/10 14:42:49 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//utiliser la fonction getcwd qui copie le chemin d'acces absolu du repertoire 
//de travail courant dans la chaine pointee par buf qui est de longueur size

#include "../minishell.h"

void cd_home( t_sys *mi_sys)
{
	if(!mi_sys->senv.home)
	{
		printf("cd: HOME not set\n");
		return ;
	}
	mi_sys->senv.pwd = mi_sys->senv.home;
	mi_setenv("PWD", mi_sys->senv.home, mi_sys);
}

void cd_back( t_sys *mi_sys)
{
	int	i;

	i = 0;
	mi_sys->senv.pwd = mi_getenv("PWD", mi_sys);
	if (!mi_sys->senv.pwd)
	{
		printf("cd: DIR not set\n");
		return ;
	}
	while (mi_sys->senv.pwd[i])
			i++;
	while (mi_sys->senv.pwd[i] != '/' && i >1)
		i--;
	mi_setenv("PWD", ft_substr(mi_sys->senv.pwd, 0, i), mi_sys);
	mi_sys->senv.pwd = mi_getenv("PWD", mi_sys);
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
		chdir(key);
		mi_sys->senv.pwd = getcwd(NULL, 0);
		mi_setenv("PWD", getcwd(NULL, 0), mi_sys);
	}
	printf("key : %s value : %s\n", key, mi_sys->senv.pwd);
	if (access(mi_sys->senv.pwd, F_OK) == 0)
	{
		printf("%s is existing\n", key);
	}
	else
	{
		perror("access");
		exit(EXIT_FAILURE);
	}
/*
	// changing the current 
	// working directory(cwd)
	// to /usr 
	if (chdir("/usr") != 0) 
		perror("chdir() to /usr failed"); 
 
	// changing the cwd to /tmp 
	if (chdir("/tmp") != 0) 
		perror("chdir() to /temp failed"); 
 
	// there is no /error 
	// directory in my pc 
	if (chdir("/error") != 0) 
 
	// so chdir will return -1 
	perror("chdir() to /error failed"); 
	*/
}
