/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:47:34 by abarrio-          #+#    #+#             */
/*   Updated: 2023/09/22 22:32:37 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;
	t_list	*next;

	if (!lst || !del)
		return ;
	aux = *lst;
	while (aux != NULL)
	{
		next = aux->next;
		del(aux->content);
		free(aux);
		aux = next;
	}
	*lst = NULL;
}
