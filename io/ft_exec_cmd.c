/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:07:44 by jegirard          #+#    #+#             */
/*   Updated: 2024/07/24 12:07:48 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct.h"

int	ft_exec_cmd(t_app *app, char **argv, int ind, char **env)
{
	char	**arg;

	if (app->exe[ind] == NULL)
		return (1);
	arg = ft_split(argv[ind + 2], '\x20');
	if (arg == NULL)
	{
		free(arg);
		perror(argv[ind + 2]);
		return (1);
	}
	if (execve(app->exe[ind], arg, env) == -1)
	{
		perror(ft_strjoin("Command :", app->exe[ind]));
		ft_perror(app, "Command found but in error ", 126, ind);
		return (errno);
	}
	return (1);
}
