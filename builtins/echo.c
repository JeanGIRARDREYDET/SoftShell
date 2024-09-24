/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:46:23 by doferet           #+#    #+#             */
/*   Updated: 2024/09/10 14:48:54 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//dans bash echo -n ecrit ce qu'il y a apres n sans retour a la ligne

//si "-n" est reconnu et qu'il y a une chaine de caractere alors il ne fait pas de retour a la ligne et la print
//si "-n" est reconnu mais qu'il n'y a pas de parametre, rien ne se passe

void	builtin_echo(char *key)
{
	int	i;
	int	n;

	i = 0;
	n = 1;
	if (key != NULL && key[0] == '-' && key[1] == 'n' && key[2] == '\0')
	{
		n = 0;
		i++;
	}

		printf("%c\n", key);
	if(n==1)
	{
		printf("\n");
	}
}
