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

void	builtin_exit(char **args,t_sys *mi_sys)
{
	int		code_exit;
	size_t	arglen;

	code_exit = 255;
	if (args)
	{
		arglen = ft_tablen(args);
		if (arglen > 2)
			mi_logerror2(2, args[1], "too many arguments", mi_sys);
		if (args[1] != NULL)
		{
			code_exit = 0xFF & ft_atoi(args[1]);
			if (code_exit == 0)
				mi_logerror2(130, args[1], "numeric argument required", mi_sys);
		}
	}
	write(STDOUT_FILENO, "exit", 5);
	mi_freecmd(mi_sys);
	mi_freesys(mi_sys);
	exit(code_exit);
}
