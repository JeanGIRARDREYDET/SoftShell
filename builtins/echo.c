/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard  <jegirard@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:44:12 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/07 13:24:53 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//dans bash echo -n ecrit ce qu'il y a apres n sans retour a la ligne
//si "-n" est reconnu et qu'il y a une chaine de caractere alors il ne fait pas 
// de retour a la ligne et la print
//si "-n" est reconnu mais qu'il n'y a pas de parametre, rien ne se passe

void	echo_param(char **param, int *j, int len, int *nl)
{
	int	k;

	while (*j < len && param[*j][0] == '-')
	{
		k = 1;
		while (param[*j][k] == 'n')
			k++;
		if (param[*j][k - 1] == 'n' && !param[*j][k])
		{
			*nl = 0;
			*j = *j + 1;
		}
	}
	return ;
}

void	builtin_echo(t_cmd *mi_cmd, int fd)
{
	int		nl;
	int		len;
	int		j;
	int		start;

	nl = 1;
	len = ft_tablen(mi_cmd->args);
	j = 1;
	echo_param(mi_cmd->args, &j, len, &nl);
	start = j;
	while (j < len)
	{
		if (j != start)
			write(fd, " ", 1);
		write(fd, mi_cmd->args[j], ft_strlen(mi_cmd->args[j]));
		j++;
	}
	if (nl == 1)
		write(fd, "\n", 1);
}
