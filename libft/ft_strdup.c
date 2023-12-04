/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:29:19 by abarrio-          #+#    #+#             */
/*   Updated: 2023/09/20 19:00:00 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		size;
	char	*memory;
	int		i;

	size = ft_strlen(src);
	memory = (char *)malloc ((size + 1) * sizeof(char));
	if (memory == NULL)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		memory[i] = src[i];
		i++;
	}
	memory[i] = '\0';
	return (memory);
}
