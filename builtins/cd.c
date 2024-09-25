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

void cd_home( t_sys *s_sys)
{
	if(!s_sys->senv.home)
	{
		printf("cd: HOME not set\n");
		return ;
	}
	s_sys->senv.pwd = s_sys->senv.home;
	s_setenv("PWD", s_sys->senv.home, s_sys);
}

void cd_back( t_sys *s_sys)
{
	int	i;

	i = 0;
	s_sys->senv.pwd = (s_getenv("PWD", s_sys));
	if (!s_sys->senv.pwd)
	{
		printf("cd: DIR not set\n");
		return ;
	}
	while (s_sys->senv.pwd[i])
			i++;
	while (s_sys->senv.pwd[i] != '/' && i >1)
		i--;
	s_setenv("PWD", ft_substr(s_sys->senv.pwd, 0, i), s_sys);
	s_sys->senv.pwd = s_getenv("PWD", s_sys);
}

void	builtin_cd(char *key, t_sys *s_sys)
{
	//g_status = 0;
	s_sys->senv.oldpwd = s_sys->senv.pwd;
	s_setenv("OLDPWD", s_sys->senv.oldpwd, s_sys);
	if (key == NULL || key[0] == '\0')
		cd_home(s_sys);
	else if (ft_strncmp(key, "..", 3) == 0)
		cd_back(s_sys);
	else
	{
		chdir(key);
		s_sys->senv.pwd = getcwd(NULL, 0);
		s_setenv("PWD", getcwd(NULL, 0), s_sys);
	}
	printf("key : %s value : %s\n", key, s_sys->senv.pwd);
	if (access(s_sys->senv.pwd, F_OK) == 0)
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
