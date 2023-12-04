/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:17:03 by abarrio-          #+#    #+#             */
/*   Updated: 2023/09/21 17:29:08 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *buffer, int c, size_t count)
{
	char	*buffer1;
	size_t	i;

	i = 0;
	buffer1 = (char *)buffer;
	while (i < count)
	{
		if (buffer1[i] == (char)c)
			return ((void *)&buffer1[i]);
		i++;
	}
	return (NULL);
}
