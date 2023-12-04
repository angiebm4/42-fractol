/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:00:48 by abarrio-          #+#    #+#             */
/*   Updated: 2023/10/16 23:20:15 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	void	*aux;
	t_list	*newnode;

	if (!lst || !f || !del)
		return (NULL);
	newlist = NULL;
	while (lst != NULL)
	{
		aux = f(lst->content);
		newnode = ft_lstnew(aux);
		if (!newnode || !aux)
		{
			del(aux);
			ft_lstclear(&newlist, (*del));
			free(newnode);
			return (NULL);
		}
		ft_lstadd_back(&newlist, newnode);
		lst = lst->next;
	}
	return (newlist);
}
