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

#include "../minishell.h"

//utiliser la fonction getcwd qui copie le chemin d'acces absolu du repertoire 
//de travail courant dans la chaine pointee par buf qui est de longueur size

#include "../minishell.h"

void	builtin_cd(char *key, t_sys *s_sys)
{
	printf("%s %s\n", key, s_sys->pwd);

	if (access(s_sys->pwd, F_OK) == 0) {
		printf("%s is existing\n", key);
	}
	else
	{
		perror("access");
		exit(EXIT_FAILURE);
	}
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
}
