/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard  <jegirard@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:38:34 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/07 13:24:53 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_exit(t_sys *mi_sys)
{
	int		code_exit;
	char	*arg;
	size_t	arglen;

	code_exit = 255;
	if (mi_sys->cmd && mi_sys->cmd->arg)
	{
		arglen = ft_tablen(mi_sys->cmd->args);
		arg = mi_sys->cmd->arg;
		if (arglen > 2)
			return (mi_logerror(2, "too many arguments", mi_sys));
		//t_subchars(args[1], "\"\'");
		if (mi_sys->cmd->args[1] != NULL)
		{
			code_exit = 0xFF & ft_atoi(mi_sys->cmd->args[1]);
			if (code_exit == 0)
				return (mi_logerror(130, "numeric argument required", mi_sys));
		}
	}
	write(STDOUT_FILENO, "exit", 5);
	mi_freecmd(mi_sys);
	mi_freesys(mi_sys);
	exit(code_exit);
}
