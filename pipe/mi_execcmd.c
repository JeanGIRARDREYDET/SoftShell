/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_execcmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:07:44 by jegirard          #+#    #+#             */
/*   Updated: 2024/07/24 12:07:48 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	mi_execcmd(t_pipe *app, char **argv, int ind, char **env)
{
	char	**arg;

	if (app->cmd == NULL)
		return (1);
	arg = ft_split(argv[ind + 2], '\x20');
	if (arg == NULL)
	{
		free(arg);
		perror(argv[ind + 2]);
		return (1);
	}
	FILE *fptr = fopen("sample.txt", "w");
	fprintf(fptr, "Error: (%s)\n", app->cmd);
	if (execve(app->cmd, arg, env) == -1)
	{
		perror(ft_strjoin("Command :", app->cmd));
		mi_logerror(126, "Command found but in error ", &app->error);
		free(arg);
		return (errno);
	}
	return (1);
}
