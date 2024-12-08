/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard  <jegirard@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 10:41:04 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/07 13:24:53 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Description : 
				Écrit l’entier ’n’ sur le descripteur de fichier donné.
Name :
				ft_putnbr_fd
Prototype :
				void ft_putnbr_fd(int n, int fd);
Paramètres :
				n: L’entier à écrire.
				fd: Le descripteur de fichier sur lequel écrire.
Retour :
				Aucune
Autorisées :
				write
*/

void	ft_putnbr_fd(int n, int fd)
{
	long	number;

	number = n;
	if (number < 0)
	{
		ft_putchar_fd('-', fd);
		number = -number;
	}
	if (number > 9)
	{
		ft_putnbr_fd(number / 10, fd);
		ft_putchar_fd('0' + (number % 10), fd);
	}
	else
		ft_putchar_fd('0' + number, fd);
	return ;
}
