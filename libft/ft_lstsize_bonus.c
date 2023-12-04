/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:13:55 by abarrio-          #+#    #+#             */
/*   Updated: 2023/11/09 16:56:47 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	nb;

	nb = 0;
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		lst = lst->next;
		nb++;
	}
	return (nb);
}
