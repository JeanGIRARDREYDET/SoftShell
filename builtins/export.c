/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:47:28 by doferet           #+#    #+#             */
/*   Updated: 2024/09/10 11:37:52 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// export sans argument a un comportement indefini donc il faut le definir
// export transfere une donnee entree dans le parent ex : $myname = "dollyne" si on fit un echo, le parent 
// renvoie bien dollyne, si on ouvre un autre bash, il n'aura pas cette variable donc si on utilise exporte
// l'enfant a bien la variable myname