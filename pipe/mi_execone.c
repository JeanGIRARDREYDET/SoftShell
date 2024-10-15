/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_execone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 19:50:42 by jegirard          #+#    #+#             */
/*   Updated: 2024/10/04 19:50:46 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mi_exefind(t_cmd *mi_cmd, t_sys *mi_sys)
{
	char		*cmd;
	char		**paths;
	int			i;
	char		*error_msg;

	i = 0;
	if (access(mi_cmd->cmd, F_OK) == 0)
		return ;
	i = 0;
	cmd = join_3(mi_getenv("PWD", mi_sys), "/", mi_cmd->cmd);
	if (access(mi_cmd->cmd, F_OK) == 0)
		return ;
	paths = ft_split (mi_getenv("PATH", mi_sys), ':');
	while (paths && paths[++i])
	{
		cmd = join_3(paths[i], "/", mi_cmd->cmd);
		if (access(cmd, F_OK) == 0)
		{
			mi_cmd->cmd = cmd;
			free(paths);
			return ;
		}
		free(cmd);
	}
	error_msg = join_3 ("minishell: ", mi_cmd->cmd, ": command not found\n");
	mi_logerror(126, error_msg, &mi_cmd->error);
	free(cmd);
	free(paths);
	return ;
}

void	mi_exepermis(t_cmd *pi, t_sys *mi_sys)
{
	if (access(pi->cmd, X_OK) == 0)
		return ;
	mi_logerrorlong(126, "mi: ", pi->cmd, ": Permission denied", &pi->error);
	mi_sys->nb_error++;
}

int	mi_execchild(t_cmd *mi_cmd, char **argv, int ind, char **env)
{
	printf("10\n");
	if (mi_cmd->id == 0)

		return (0);
	mi_cmd->id = fork();
	if (mi_cmd->id == -1)
		return (mi_intlogerror (mi_cmd, "fork out failed", 1));
	if (mi_cmd->id != 0)
		return (0);
	if (mi_cmd->no != 0)
	{
		if (dup2(mi_cmd->fdd[0], STDIN_FILENO) == -1)
			return (1);
		close (mi_cmd->fdd[0]);
	}
	if (mi_cmd->next)
	{
		if (dup2(mi_cmd->fdd[1], STDOUT_FILENO) == -1)
			return (1);
		close (mi_cmd->fdd[1]);
	}
	if (mi_cmd->cmd != NULL)
		mi_execcmd(mi_cmd, argv, ind, env);
	dprintf(1, "%s\n", mi_cmd->cmd);
	mi_freepipe (mi_cmd);
	exit (EXIT_FAILURE);
	return (1);
}

void	mi_execone(t_cmd *pipe, t_sys *mi_sys)
{
	if (ft_strncmp(pipe->cmd, "exit", 5) == 0)
	{
		printf("exit\n");
		exit(0);
	}
	else if (ft_strncmp(pipe->cmd, "env", 4) == 0)
		builtin_env(mi_sys);
	else if (ft_strncmp(pipe->cmd, "env", 4) == 0)
		builtin_env(mi_sys);
	else if (ft_strncmp(pipe->cmd, "pwd", 4) == 0)
		builtin_pwd();
	else if (ft_strncmp(pipe->cmd, "echo", 4) == 0)
		builtin_echo(ft_post_left_sep(pipe->cmd, WSPACE));
	else if (ft_strncmp(pipe->cmd, "cd", 2) == 0)
		builtin_cd(ft_post_left_sep(pipe->cmd, WSPACE), mi_sys);
	else if (ft_strncmp(pipe->cmd, "unset", 5) == 0)
		builtin_unset(pipe->args[0], mi_sys);
	else if (ft_strncmp(pipe->cmd, "export", 6) == 0)
		builtin_export(ft_post_left_sep(pipe->cmd, WSPACE), mi_sys);
	else
		pipe->builtin = false;
	if (pipe->builtin == false)
	{
		mi_exefind(pipe, mi_sys);
		if (pipe->cmd)
			mi_exepermis(pipe, mi_sys);
		if (pipe->cmd)
			mi_execchild(pipe, pipe->args, 0, mi_sys->env);
	}
}
