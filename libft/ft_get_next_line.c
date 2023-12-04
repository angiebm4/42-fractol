/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:33:34 by abarrio-          #+#    #+#             */
/*   Updated: 2023/11/08 12:58:51 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_free(char *buff, char *aux)
{
	free(aux);
	free(buff);
	buff = NULL;
	aux = NULL;
	return (NULL);
}

char	*ft_read(int fd, char *buff)
{
	char	*aux;
	int		nb;

	nb = 1;
	aux = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!aux)
		return (ft_free(buff, NULL));
	while (nb > 0 && !ft_strchr(buff, '\n'))
	{
		nb = read(fd, aux, BUFFER_SIZE);
		if (nb == -1)
			return (ft_free(buff, aux));
		aux[nb] = '\0';
		if (aux[0] == '\0')
		{
			free(aux);
			aux = NULL;
			return (buff);
		}
		buff = ft_strjoin_gnl(buff, aux);
		if (!buff)
			return (ft_free(buff, aux));
	}
	free(aux);
	return (buff);
}

char	*ft_getline(char *buff)
{
	char	*line;
	int		i;

	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	if (buff[i] == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (ft_free(buff, NULL));
	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
	{
		line[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*readnotprint[OPEN_MAX];
	char		*line;
	int			i;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	readnotprint[fd] = ft_read(fd, readnotprint[fd]);
	if (!readnotprint[fd])
		return (NULL);
	line = ft_getline(readnotprint[fd]);
	if (!line)
		return (NULL);
	i = ft_strlen(line);
	readnotprint[fd] = ft_substr(readnotprint[fd], i,
			(ft_strlen(readnotprint[fd]) - i));
	return (line);
}
