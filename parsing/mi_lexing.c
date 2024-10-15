/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_lexing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <jegirard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:36:52 by jegirard          #+#    #+#             */
/*   Updated: 2024/10/15 03:28:46 by jegirard         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../minishell.h"

void	mi_lexingline(char *ln, int i, t_cmd *mi_cmd, t_sys *mi_sys)
{	
	t_cmd		*new_cmd;
	// const char *redir_token[] = {"<", ">", ">>", "<<", NULL};
	printf("mi_lexingline\n");
	printf("\t%s\n", ln);
	printf("\t%d\n", i);
	printf("\t%c\n", ln[i]);
	
	if (!ln[i] || ln[i] == '\0')
	{
		mi_cmd->full_cmd = ft_strtrim_param(ln, 0, i, WSPACE);
		mi_cmd->next = NULL;
		return ;
	}
	else if (ft_strin(TECHAP, ln[i]))
	{
		i = mi_pospasscote(ln, i, &mi_cmd->error);

	printf("\t%s\n", ln);
	printf("\t%d\n", i);
	printf("\t%c\n", ln[i]);
		
		mi_lexingline (ln, i, mi_cmd, mi_sys);
	}
	else  if (ln[i] == '|')
	{
		new_cmd = mi_createcmd(mi_sys);
		mi_cmd->full_cmd = ft_strtrim_param(ln, 0, i -1, WSPACE);
		mi_cmd->next = new_cmd;
		mi_lexingline (ln + (++i), 0, new_cmd, mi_sys);
	}
	else
	{
		printf("\t%s\n", ln);
		printf("\t%d\n", i);
		printf("\t%c\n", ln[i]);

		mi_lexingline (ln, ++i, mi_cmd, mi_sys);
	}
		
}
