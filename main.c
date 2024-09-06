/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:08:01 by doferet           #+#    #+#             */
/*   Updated: 2024/09/06 12:34:19 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/home/doferet/Documents/minishell/includes/minishell.h"
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

size_t	ft_strlen(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int main(void)
{
    char *line; 
    
    while(1)
    {
        line = readline("minishell > ");
        if (ft_strncmp(line, "exit", 4) == 0 && ft_strlen(line) == 4)
            exit(0);
    }
}
