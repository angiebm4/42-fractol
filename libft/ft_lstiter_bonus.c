/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:26:15 by abarrio-          #+#    #+#             */
/*   Updated: 2023/09/22 22:31:37 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*auxnode;

	if (!lst || !f)
		return ;
	auxnode = lst;
	while (auxnode != NULL)
	{
		f(auxnode->content);
		auxnode = auxnode->next;
	}
}
