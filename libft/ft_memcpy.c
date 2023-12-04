/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:02:09 by abarrio-          #+#    #+#             */
/*   Updated: 2023/09/21 17:25:48 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *origen, size_t n)
{
	size_t		i;
	char		*dest1;
	const char	*origen1;

	dest1 = (char *)dest;
	origen1 = (const char *)origen;
	if (dest1 == NULL && origen1 == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dest1[i] = origen1[i];
		i++;
	}
	return ((void *)dest1);
}
