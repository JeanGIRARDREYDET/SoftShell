/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findword.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <jegirard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:35:05 by jegirard          #+#    #+#             */
/*   Updated: 2024/11/29 11:40:32 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

typedef struct s_findworlf
{
	size_t		e;
	size_t		i;
	size_t		lenfind;
	char		*dic;
}	t_findworlf;

bool	ft_findword(const char *dic, const char *find)
{
	t_findworlf		fw;

	if (find == NULL || dic == NULL || find[0] == '\0')
		return (false);
	fw.lenfind = ft_strlen(find);
	fw.i = 0;
	fw.dic = (char *)dic;
	fw.e = 0;
	while (*fw.dic != '\0')
	{
		fw.i = 0;
		while (*fw.dic == ' ' && *fw.dic != '\0' )
			fw.dic++;
		while (find[fw.i] == *fw.dic && *fw.dic != '\0')
		{
			fw.dic++;
			fw.i++;
		}
		if (find[fw.i] == '\0' && (*fw.dic == ' ' || *fw.dic == '\0'))
			return (true);
		while (*fw.dic != ' ' && *fw.dic != '\0' )
			fw.dic++;
	}
	return (false);
}
