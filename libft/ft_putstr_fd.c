/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:49:48 by jegirard          #+#    #+#             */
/*   Updated: 2023/11/15 09:49:51 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Description : 
			Écrit la chaîne de caractères ’s’ sur le descripteur de 
			fichier donné.
Prototype :
			void ft_putstr_fd(char *s, int fd);
Paramètres :
			s: La chaîne de caractères à écrire.
			d: Le descripteur de fichier sur lequel écrire.

Autorisées : 
			write
*/

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}
