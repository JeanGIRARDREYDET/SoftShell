/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <jegirard@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:38:34 by jegirard          #+#    #+#             */
/*   Updated: 2025/01/17 16:40:10 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char mi_prompt_text(t_sys *mi_sys)
{
	char *prompt_text;
	char *code_error;
	char *prompt_input;

	code_error = ft_itoa(mi_sys->code_error);
	prompt_text = ft_strjoin(code_error, " SoftShell>");
	free(prompt_input);
	free(prompt_text);
	free(code_error);
return (prompt_text);
}

void mi_prompt(t_sys *mi_sys)
{
	char *line;
	char *input;
	char *prompt_text;

	prompt_text = mi_prompt_text(mi_sys);
	while(1)
	{
		init_signal();
		line = readline(prompt_text);
		mi_sys->input = ft_strtrim(line, WSPACE); 
        free(line);
        if (!mi_sys->input)
        {
			free(mi_sys->input);
			free(prompt_text);
			mi_freecmdsysexit(1, 0, &mi_sys);
        }
		else if (*line == '\0')
		{
			free(mi_sys->input);
			continue ;
		}
		free(prompt_text);
	break;
	}
}

