/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:09:49 by jegirard          #+#    #+#             */
/*   Updated: 2023/11/28 13:09:53 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function :
				ft_lstclear
Prototype :
				void ft_lstclear(t_list **lst, void (*del)(void*));
Paramètres :
				lst: L’adresse du pointeur vers un élément.
				del: L’adresse de la fonction permettant de supprimer le contenu
				d’un élément.
Externes :
				free
Description :
				Supprime et libère la mémoire de l’élément passé en paramètre,
				et de tous les éléments qui suivent, à l’aide de ’del’ et de
				free(3)
				Enfin, le pointeur initial doit être mis à NULL.
*/

#include "../minishell.h"

void	ft_lstclear(t_list **lst, void (*del)(void*) )
{
	t_list	*p_element_next_dell;

	while (lst && *lst != NULL && del != NULL)
	{
		p_element_next_dell = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = p_element_next_dell;
	}
}
