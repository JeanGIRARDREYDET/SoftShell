/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_waitingpipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:37:40 by jegirard          #+#    #+#             */
/*   Updated: 2024/10/08 11:37:42 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// dans cette fonction, on attend la fin de l'execution du deriers processus 
// lance
// pour le dernier a rendre la main ou aurai utilise 
// while (i < mi_sys->nb_pipe && wait (&status) != 32512)

#include "../minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

void	mi_waitingpipe(t_sys *mi_sys)
{
	int	i;
	int	status;

	i = 1;
	while (i < mi_sys->nb_pipe)
		i++;
	wait (&status);
	if (!(mi_sys->nb_pipe == 1 && mi_sys->cmd->builtin))
	{
		mi_freeerror (mi_sys);
		mi_logerror (WEXITSTATUS(status), NULL, mi_sys);
	}	
}
