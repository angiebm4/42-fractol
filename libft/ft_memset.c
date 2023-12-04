/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:58:35 by abarrio-          #+#    #+#             */
/*   Updated: 2023/09/21 17:29:53 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	char	*dest;
	size_t	i;

	dest = (char *)str;
	i = 0;
	while (i < n)
	{
		dest[i] = c;
		i++;
	}
	return (dest);
}
