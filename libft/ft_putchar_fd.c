/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:49:26 by jegirard          #+#    #+#             */
/*   Updated: 2023/11/15 09:49:29 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Description :
				Écrit le caractère ’c’ sur le descripteur de fichier donné.
Paramètres :
				c: Le caractère à écrire.
				fd: Le descripteur de fichier sur lequel écrire.
Retour :
				 Aucune
Autorisées :
				write
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
