/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:06:32 by jegirard          #+#    #+#             */
/*   Updated: 2023/11/28 13:07:15 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Description :	Ajoute l’élément ’new’ au début de la liste.

Function :		ft_lstadd_front

Prototype :		void ft_lstadd_front(t_list **lst, t_list *new);

Paramètres :	lst: L’adresse du pointeur vers le premier élément de la liste.

				new: L’adresse du pointeur vers l’élément à rajouter à la liste.

*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!(lst && new))
		return ;
	new->next = *lst;
	*lst = new;
}
