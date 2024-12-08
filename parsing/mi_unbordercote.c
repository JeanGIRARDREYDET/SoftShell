/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_unbordercote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard  <jegirard@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:38:34 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/07 13:24:53 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mi_unbordercote(char *args, t_sys *mi_sys)
{
	int			i;
	int			j;
	char		replace;

	i = 0;
	j = 0;
	if (mi_sys->nb_error > 0 || args == NULL)
		return ;
	while (args[i] == '$' && args[i] != '\0')
		i++;
	while (args[i] != '\'' && args[i] != '\"' && args[i] != '\0')
		i++;
	if (args[i] == '\'' || args[i] == '\"')
		replace = args[i];
	else
		return ;
	while (args[i] != '\0')
	{
		while (args[i] == replace)
			i++;
		args[j] = args[i];
		i++;
		j++;
	}
	args[j] = '\0';
}
