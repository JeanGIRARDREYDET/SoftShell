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

void	mi_checksyntax(char *line, t_sys *mi_sys)
{
	if (ft_strrchr(line, '|') != NULL && (ft_strrchr(line, '|') == line
			|| *(ft_strrchr(line, '|') + 1) == '\0'
			|| *(ft_strrchr(line, '|') + 1) == '|'))
		mi_logerror(2, "syntax error near unexpected token `|'", mi_sys);
	else if (ft_strrchr(line, '>') != NULL && (ft_strrchr(line, '>') == line
			|| *(ft_strrchr(line, '>') + 1) == '\0'
			|| *(ft_strrchr(line, '>') + 1) == '>'))
		mi_logerror(2, "syntax error near unexpected token `>'", mi_sys);
	else if (ft_strrchr(line, '<') != NULL && (ft_strrchr(line, '<') == line
			|| *(ft_strrchr(line, '<') + 1) == '\0'
			|| *(ft_strrchr(line, '<') + 1) == '<'))
		mi_logerror(2, "syntax error near unexpected token `<'", mi_sys);
}
