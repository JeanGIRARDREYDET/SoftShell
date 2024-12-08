/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegirard  <jegirard@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 10:41:04 by jegirard          #+#    #+#             */
/*   Updated: 2024/12/07 13:24:53 by jegirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function :
				ft_lstiter	
Prototype :
				void ft_lstiter(t_list *lst, void (*f)(void *));
Paramètres :
				lst: L’adresse du pointeur vers un élément.
				f: L’adresse de la fonction à appliquer.
Description :
				Itère sur la liste ’lst’ et applique la fonction ’f’ au contenu
				chaque élément.
 */

#include "../minishell.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*i_element;

	i_element = lst;
	while (i_element != NULL)
	{
		(*f)(i_element->content);
		i_element = i_element->next;
	}
}
