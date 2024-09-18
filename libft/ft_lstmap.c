/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:12:41 by jegirard          #+#    #+#             */
/*   Updated: 2023/11/28 13:12:49 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Description :
				Itère sur la liste ’lst’ et applique la fonction ’f ’au contenu 
				de chaque élément. Crée une nouvelle liste résultant des
				applications successives de ’f’.
				La fonction ’del’ est là pour détruire le contenu d’un élément
				si nécessaire.
Function :
				malloc, free
Prototype :
				t_list *ft_lstmap
				(t_list *lst, void *(*f)(void *), void (*del)(void *));

Paramètres :
				lst: L’adresse du pointeur vers un élément.
				f: L’adresse de la fonction à appliquer.
				del: L’adresse de la fonction permettant de supprimer le contenu
				 d’un élément.
Retour :
				La nouvelle liste.
				NULL si l’allocation échoue

*/

#include "../minishell.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_return;
	t_list	*element_hook;

	lst_return = NULL;
	while (lst)
	{
		element_hook = ft_lstnew ((*f)(lst->content));
		if (!element_hook)
		{
			ft_lstclear (&lst_return, del);
			return (NULL);
		}
		ft_lstadd_back (&lst_return, element_hook);
		lst = lst->next;
	}
	return (lst_return);
}
