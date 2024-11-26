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

void	echo_param(char **param, int *j, int len, int *nl)
{
	int	k;

	while (*j < len && *nl == 1 && param[*j][0] == '-')
	{
		k = 1;
		while (param[*j][k] == 'n')
			k++;
		if (param[*j][k - 1] == 'n' && param[*j][k] == '\0')
		{
			*nl = 0;
			*j = *j + 1;
		}
		else
			break ;
	}
}

void	builtin_echo(t_cmd *mi_cmd, int fd)
{
	int		nl;
	int		len;
	int		j;

	nl = 1;
	len = ft_tablen2(mi_cmd->args);
	j = 1;
	echo_param(mi_cmd->args, &j, len, &nl);
	while (j < len)
	{
		write(fd, mi_cmd->args[j], ft_strlen(mi_cmd->args[j]));
		if (j < len)
			write(fd, " ", 1);
		j++;	
	}
	if (nl == 1)
		write(fd, "\n", 1);
	
}
