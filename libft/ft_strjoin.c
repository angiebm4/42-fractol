/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:26:14 by abarrio-          #+#    #+#             */
/*   Updated: 2023/11/23 06:31:42 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*substring;
	int		i;
	int		j;
	int		len;
	int		len1;

	if (!s1)
		return (ft_strdup(s2));
	len1 = ft_strlen(s1);
	len = ft_strlen(s2) + len1;
	substring = malloc((len + 1) * sizeof(char));
	if (substring == NULL)
		return (NULL);
	i = -1;
	while (++i <= len && s1[i])
		substring[i] = s1[i];
	j = 0;
	while (j < len && s2[j])
		substring[i++] = s2[j++];
	substring[i] = '\0';
	free(s1);
	return (substring);
}
