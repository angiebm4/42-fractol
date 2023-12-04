/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:58:51 by abarrio-          #+#    #+#             */
/*   Updated: 2023/10/03 22:10:36 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == '\0' && (unsigned char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

/*
int	main(int argc, char **argv)
{
	(void)argc;
	char *result = ft_strchr(argv[1], *argv[2]);
	printf("%s", result);
	return (0);
}
*/