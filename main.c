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
char *find_command(char *line)
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
	return (ft_substr(line,c1,(c2-c1)));
}

char *find_expand(char *line)
{
	int	i;
	int	c1;
	int	c2;
	// 34 39
	i = 0;
	while (line[i] != '\0')
	{
		while (line[i] != '$')
		{
			i++;
			c1 = i;
		}

		while (line[i] > 32)
		{
			i++;
			c2 = i;
		}

		while (line[i] < 33)
			i++;
	}
	return (ft_substr(line,c1,(c2-c1)));
} 

int	main(int ac, char **argv, char **env)
{
	char	*line;
	int		l_len;
	t_sys	s_sys;

	if (ac > 1)
	{
		printf("Error: minishell does not take arguments. Try: ./%s\n", argv[0]);
		exit(0);
	}
	common_initialization(env, &s_sys);
	dprintf(2,"debug\n");
	while (1)
	{	
		line = readline("minishell> ");
		l_len = ft_strlen(line);		
		if (ft_strncmp(line, "exit", 5) == 0 && ft_strlen(line) == 4)
		{
			printf("exit\n");
			exit(0);
		}
		else if (ft_strncmp(line, "env", 4) == 0)
			builtin_env(&s_sys);
		else if (ft_strncmp(line, "env", 4) == 0)
			builtin_env(&s_sys);	
		else if (ft_strncmp(line, "pwd", 4) == 0)
			builtin_pwd();
		else if (ft_strncmp(line, "echo", 4) == 0 && ( l_len==4 || (l_len >4  && (line[4]) < 33 ) ))	
			builtin_echo(ft_post_left_sep(line, ' '));
		else if (ft_strncmp(line, "cd", 2) == 0 && ( l_len==2 || (l_len >2  && (line[2]) < 33 ) ))
			builtin_cd(ft_post_left_sep(line, ' '), &s_sys);
		else if (ft_strncmp(line, "unset", 5) == 0)
			s_unset(ft_post_left_sep(line, ' '), &s_sys);
		else if (ft_strncmp(line, "export", 6) == 0)
			builtin_export(ft_post_left_sep(line, ' '), &s_sys);
		// else if (ft_strncmp(line, "echo", 5) == 0)
		// 	builtin_echo();
		add_history(line);
	}
}
