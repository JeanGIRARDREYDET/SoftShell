/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit .c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:01:34 by jegirard          #+#    #+#             */
/*   Updated: 2024/10/14 11:01:41 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_exit(t_sys *mi_sys)
{
	int		code_exit;
	char	*arg;
	int		i;
	int		n;

	i = 0;
	n = 0;
	code_exit = 255;
	if (mi_sys->cmd && mi_sys->cmd->arg)
	{
		arg = mi_sys->cmd->arg;
		ft_cnt_arg(arg, &i, &n);
		if (n > 1)
			return (mi_logerror(2, "too many arguments", mi_sys));
		ft_subchars(arg, "\"\'");
		if (arg != NULL)
		{
			code_exit = 0xFF & ft_atoi(arg);
			if (code_exit == 0)
				return (mi_logerror(130, "numeric argument required", mi_sys));
		}
	}
	write(STDOUT_FILENO, "exit", 5);
	mi_freesys(mi_sys);
	exit(code_exit);
}
