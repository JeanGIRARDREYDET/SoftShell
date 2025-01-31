/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_checksyntax.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard  <jegirard@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 09:43:56 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/07 13:24:53 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	mi_checksyntax2(char *line)
{
	int		i;
	char	*new_line;

	i = 0;
	new_line = ft_strdup(line);
	if (!new_line)
		return (false);
	while (new_line[i])
	{
		if ((size_t)i <= (ft_strlen(new_line) - 1))
		{
			if ((new_line[i] == '>' && (new_line[i + 1] == '<'
						|| new_line[i + 1] == '|')) || (new_line[i] == '<'
					&& (new_line[i + 1] == '|' || new_line[i + 1] == '>')))
			{
				free(new_line);
				return (true);
			}
		}
		i++;
	}
	free(new_line);
	return (false);
}

void	mi_checksyntax(char *line, t_sys *mi_sys)
{
	if (!line || !*line)
		return ;
	if (mi_checksyntax2(line) == true)
		mi_logerror(2, "syntax error near unexpected token", mi_sys);
	else if (ft_strlen(line) == 1 && (*line == '|' || *line == '<'
			|| *line == '>'))
		mi_logerror(2, "syntax error near unexpected token", mi_sys);
	else if (ft_strrchr(line, '|') != NULL && (ft_strrchr(line, '|') == line
			|| *(ft_strrchr(line, '|') + 1) == '\0' || *(ft_strrchr(line, '|')
				+ 1) == '|'))
		mi_logerror(2, "syntax error near unexpected token `|'", mi_sys);
	else if (ft_strrchr(line, '>') != NULL && (*(ft_strrchr(line, '>')
				+ 1) == '\0' || *(ft_strrchr(line, '>') + 1) == '>'))
		mi_logerror(2, "syntax error near unexpected token `>'", mi_sys);
	else if (strrchr(line, '<') != NULL && (*(strrchr(line, '<') + 1) == '\0'
			|| *(ft_strrchr(line, '<') + 1) == '<'))
		mi_logerror(2, "syntax error near unexpected token `<'", mi_sys);
}
