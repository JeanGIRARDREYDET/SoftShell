/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:38:34 by jegirard          #+#    #+#             */
/*   Updated: 2025/01/17 16:33:19 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mi_freecmdsysexit(int fd, int status, t_sys *mi_sys)
{
	if (fd > 0)
		write(fd, "exit\n", 5);
	mi_freecmd(mi_sys);
	mi_freesysexit(status, mi_sys);
}

void	builtin_exit(char **args, t_sys *mi_sys)
{
	int			code_exit;
	size_t		arglen;

	code_exit = mi_sys->code_error;
	if (args)
	{
		arglen = ft_tablen(args);
		arglen = ft_tablen(args);
		if (arglen > 2)
		{
			code_exit = 1;
			mi_logerror2(1, args[1], "too many arguments", mi_sys);
		}
		else if (args[1] != NULL)
		{
			code_exit = 0xFF & ft_atoi(args[1]);
			if (code_exit == 0)
			{
				code_exit = 2;
				mi_logerror2(2, args[1], "numeric argument required", mi_sys);
			}
		}
	}
	mi_freecmdsysexit(STDOUT_FILENO, code_exit, mi_sys);
}
