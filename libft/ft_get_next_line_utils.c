/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:59:10 by abarrio-          #+#    #+#             */
/*   Updated: 2023/11/08 12:58:25 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	int		size;
	char	*memory;
	int		i;

	if (!src)
		return (NULL);
	size = ft_strlen(src);
	memory = (char *)malloc((size + 1) * sizeof(char));
	if (memory == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		memory[i] = src[i];
		i++;
	}
	memory[i] = '\0';
	return (memory);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
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

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == '\0' && (unsigned char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;

	if ((start + len) > (unsigned long)ft_strlen(s))
		len = (unsigned long)ft_strlen(s) - start;
	if (!s)
		return (ft_free(s, NULL));
	if (start >= (unsigned int)ft_strlen(s))
		return (ft_free(s, NULL));
	substring = (char *)malloc((len + 1) * sizeof(char));
	if (substring == NULL)
		return (ft_free(s, NULL));
	i = 0;
	while (s[start] != '\0' && i < len)
	{
		substring[i] = s[start];
		i++;
		start++;
	}
	substring[i] = '\0';
	free(s);
	return (substring);
}
