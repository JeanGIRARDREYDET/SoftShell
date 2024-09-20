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

void	builtin_cd(t_sys *sys , char *argv)
{
	int	i;

	i = 0;
   if (argv=='-')
    {
    
    }


	while (sys->env != NULL && sys->env[i] && sys->env[i] != NULL)
	{
		if (ft_strin(sys->env[i], '='))
			printf("%s\n", sys->env[i]);
		i++;
	}
}