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


int	main(int ac, char **argv, char **env)
{
	char	*line;
	t_sys	s_sys;

	if (ac > 1)
	{
		printf("Error: minishell does not take arguments. Try: ./%s\n", argv[0]);
		exit(0);
	}
	common_initialization(env, &s_sys);
	while (1)
	{
		line = readline("minishell> ");
		if (ft_strncmp(line, "exit", 5) == 0 && ft_strlen(line) == 4)
		{
			printf("exit\n");
			exit(0);
		}
		else if (ft_strncmp(line, "env", 4) == 0)
			builtin_env(&s_sys);
		else if (ft_strncmp(line, "pwd", 4) == 0)
			builtin_pwd(&s_sys);
		else if (ft_strncmp(line, "cd ", 3) == 0)
			builtin_cd(ft_post_left_sep(line, ' '), &s_sys);	
		else if (ft_strncmp(line, "unset", 5) == 0)
			builtin_unset(ft_post_left_sep(line, ' '), &s_sys);
		else if (ft_strncmp(line, "export", 6) == 0)
			builtin_export(ft_post_left_sep(line, ' '), &s_sys);
		// else if (ft_strncmp(line, "echo", 5) == 0)
		// 	builtin_echo();
		add_history(line);
	}
}
