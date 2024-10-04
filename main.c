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
		mi_pipe = *mi_createpipe();
		mi_lexingline (line, 0, &mi_pipe, &mi_sys);
		mi_sys.pipe = &mi_pipe;
		mi_syspipeiter (&mi_sys, &mi_expand_interface);
		mi_pipeiter (&mi_pipe, &mi_pipeparsse);
		mi_pipeiter (&mi_pipe, &mi_pipeargparsse);
		mi_exec(&mi_pipe, &mi_sys);
		add_history(line);
	}
}
