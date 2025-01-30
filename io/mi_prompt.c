/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <jegirard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:38:34 by jegirard          #+#    #+#             */
/*   Updated: 2025/01/17 16:40:10 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mi_prompt(t_sys *mi_sys)
{
	char	*line;

	while (1)
	{
		line = readline("Softshell:>");
		if (line == NULL)
			mi_freecmdsysexit(1, 0, mi_sys);;
		if (*line == '\0')
			continue ;
		mi_sys->input = ft_strtrim(line, WSPACE);
		free(line);
		if (!mi_sys->input)
			mi_freecmdsysexit(1, 0, mi_sys);
		else if (*mi_sys->input == '\0')
		{
			free(mi_sys->input);
			continue ;
		}
		break ;
	}
}
