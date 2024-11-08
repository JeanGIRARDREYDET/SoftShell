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
	int	n;
	int i;

	n = 1;
	i = 2;
	if (key != NULL && *key == '-' && key[1] == 'n')
	{
		key++;
		while(*key == 'n')
			key++;
		if (*key < 33)
			n = 0;
	}
	while (*key < 33)
		key++;
	write(STDOUT_FILENO, key, ft_strlen(key));
	if (n == 1)
		write(STDOUT_FILENO, "\n", 1);
}
