/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:50:14 by jegirard          #+#    #+#             */
/*   Updated: 2023/11/15 09:50:18 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Description : 
				Ecrit La chaîne de caractères ’s’ sur le descripteur de fichier
				donné suivie d’un retour à la ligne.
Name :
				ft_putendl_fd
Prototype :
				void ft_putendl_fd(char *s, int fd);
Paramètres :
				s: La chaîne de caractères à écrire.
				d: Le descripteur de fichier sur lequel écrire.

Retour :
				Aucune
Autorisées :
				write
*/

void	ft_putendl_fd(char *s, int fd)
{
	if (s)
	{
		write(fd, s, ft_strlen(s));
		write(fd, "\n", 1);
	}
}
