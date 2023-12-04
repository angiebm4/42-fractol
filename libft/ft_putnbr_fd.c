/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:07:13 by abarrio-          #+#    #+#             */
/*   Updated: 2023/09/22 20:00:41 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	char	c;

	nb = n;
	if (nb < 0)
	{
		write (fd, "-", 1);
		nb = nb * -1;
	}
	if (nb > 9)
		ft_putnbr_fd(nb / 10, fd);
	c = (nb % 10) + '0';
	write (fd, &c, 1);
}
