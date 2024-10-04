/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:08:01 by doferet           #+#    #+#             */
/*   Updated: 2024/09/10 14:56:19 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_status;
char *ft_findcommand(char *line)
{
	int	i;
	int	c1;
	int	c2;

	i = 0;
	while (line[i] < 33)
		i++;
	c1= i;	
	while (line[i] > 32)
		i++;
	c2 = i;
	while (line[i] < 33)
		i++;
	return (ft_substr(line, c1, (c2- c1)));
}




void	ft_enleverspacedeavnt(char *ln)
{
	while (ln[0] < 33 && ln[0] != '\0')
	{
		ln++;
//		i = 0;
	}
}



t_pipe *mi_create_pipe(void)
{
	t_pipe	*pipe;

	pipe = ft_calloc(1, sizeof (t_pipe));
	if (!pipe)
		return (NULL);
	pipe->pid = 0;
	pipe->full_cmd = NULL;
	pipe->cmd = NULL;
	pipe->arg = NULL;
	pipe->args = NULL;
	pipe->error.num = 0;
	pipe->error.msg = NULL;
	pipe->duplexe_canal[0] = 0;
	pipe->duplexe_canal[1] = 0;
	pipe->fdd[0][0] = 0;
	pipe->fdd[0][1] = 0;
	pipe->fdd[1][0] = 0;
	pipe->fdd[1][1] = 0;
	pipe->file = NULL;
	pipe->next = NULL;
	return (pipe);
}






void mi_oneexec (t_pipe *pipe, t_sys *mi_sys)
{


	if (ft_strncmp(pipe->cmd, "exit", 5)==0)
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
}

void mi_exec (t_pipe *pipe, t_sys *mi_sys)
{
	if (mi_sys->nb_pipe == 0)
		mi_oneexec(pipe, mi_sys);
	else
	{}


}


int	main(int ac, char **argv, char **env)
{
	char	*line;
	int		l_len;
	t_sys	mi_sys;
	t_pipe	mi_pipe;

	if (ac > 1)
	{
		printf("Error: minishell does not take arguments. Try: ./%s\n", argv[0]);
		exit(0);
	}
	mi_sysinitialization(env, &mi_sys);
	while (1)
	{	
		line = readline("minishell> ");
		l_len = ft_strlen(line);
		mi_sys.nb_pipe = 0;
		mi_pipe = *mi_create_pipe();
		mi_lexingline (line, 0, &mi_pipe, &mi_sys);
		mi_sys.pipe = &mi_pipe;
		mi_syspipeiter (&mi_sys, &mi_expand_interface);
		mi_pipeiter (&mi_pipe, &mi_pipeparsse);
		mi_pipeiter (&mi_pipe, &mi_pipeargparsse);
		mi_oneexec(&mi_pipe, &mi_sys);
		add_history(line);
	}
}
