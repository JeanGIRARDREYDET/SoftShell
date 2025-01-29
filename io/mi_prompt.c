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

char	*mi_prompt_text(t_sys *mi_sys)
{
	char	*prompt_text2;
	char	*code_error;

	code_error = ft_itoa(mi_sys->code_error);
	prompt_text2 = ft_strjoin(code_error, " SoftShell>");
	free(code_error);
	return (prompt_text2);
}

void	mi_prompt(t_sys *mi_sys)
{
	char	*line;
//	char	*prompt_text2;

///	prompt_text2 = "toto";
	while (1)
	{
		line = readline("MicroShell>");
		if (line == NULL)
			mi_freecmdsysexit(1, 0, mi_sys);;
		if (*line == '\0')
			continue ;
		mi_sys->input = ft_strtrim(line, WSPACE);
		free(line);
		if (!mi_sys->input)
		{
			//free(prompt_text2);
			mi_freecmdsysexit(1, 0, mi_sys);
		}
		else if (*mi_sys->input == '\0')
		{
			free(mi_sys->input);
			continue ;
		}
		//free(prompt_text2);
		break ;
	}
}
