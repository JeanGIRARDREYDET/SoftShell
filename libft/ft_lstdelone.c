/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:09:19 by jegirard          #+#    #+#             */
/*   Updated: 2023/11/28 13:09:23 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Description :
				Libère la mémoire de l’élément passé en argument en utilisant 
				la fonction ’del’ puis avec free(3). 
				La mémoire de ’next’ ne doit pas être free.
Prototype :
				void ft_lstdelone(t_list *lst, void (*del)(void *));
Paramètres :
				lst: L’élément à free 
				del: L’adresse de la fonction permettant de supprimer le contenu
				de l’élément.
Externes :
				free
*/

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst && lst->content && del)
	{
		(del)(lst->content);
		free(lst);
	}
}
