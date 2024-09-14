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
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < n - 1)
	{
		i++;
	}
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}


int	ft_strin(const char *s, const char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
	}
	if (s[i] == c)
		return (1);
	return (0);
}

char	*ft_left_sep(char *src, const char c)
{
	size_t	i;
	char	*p;

	p = ft_strdup(src);
	i = 0;
	while (p[i] != '\0' && p[i] != c)
	{
		i++;
	}
	p[i]='\0';
	return (p);
}

char	*ft_post_left_sep(char *src, const char c)
{
	char	*p;

	p = (char *)src;
	while (*p != '\0' && *p != c)
		p++;
	if (*p == c)
		p++;
	return (p);
}

int	main(int ac, char **argv, char **env)
{
	char	*line;
	char	*ar;
	t_sys	s_sys;

	if (ac > 1)
	{
		printf("Error: minishell does not take arguments. Try: ./minishell\n");
		ar = argv[0];
		exit(0);
	}
	common_initialization(env, &s_sys);
	while (1)
	{
		line = readline("minishell> ");
		printf("%s \n", ft_left_sep(line, ' '));
		printf("%s \n", ft_post_left_sep(line, ' '));
		printf("%s \n", ft_left_sep(line, ' '));
		
		if (ft_strncmp(line, "exit", 5) == 0 && ft_strlen(line) == 4)
		{
			printf("exit\n");
			exit(0);
		}
		else if (ft_strncmp(line, "env", 4) == 0)
			builtin_env(&s_sys);
		else if (ft_strncmp(line, "pwd", 4) == 0)
			builtin_pwd(&s_sys);
		else if (ft_strncmp(line, "unset", 5) == 0)
			builtin_unset(line, &s_sys);
		// else if (ft_strncmp(line, "echo", 5) == 0)
		// 	builtin_echo();
		add_history(line);
	}
}
