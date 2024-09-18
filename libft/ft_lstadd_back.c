/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:08:50 by jegirard          #+#    #+#             */
/*   Updated: 2023/11/28 13:08:55 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Description :	Ajoute l’élément ’new’ à la fin de la liste.

Name :			ft_lstadd_back

Prototype :		void ft_lstadd_back(t_list **lst, t_list *new);

Paramètres :	lst: L’adresse du pointeur vers le premier élément de la liste.
				new: L’adresse du pointeur vers l’élément à rajouter à la liste.
*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*element;

	if (!new)
		return ;
	if (lst && *lst)
	{
		element = *lst;
		element = ft_lstlast(*lst);
		element->next = new;
		return ;
	}
	*lst = new;
	return ;
}
