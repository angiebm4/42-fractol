/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:39:03 by abarrio-          #+#    #+#             */
/*   Updated: 2023/10/21 19:18:27 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_flag_less_char(int c, t_flags *check_flags)
{
	int	size;
	int	nb;

	size = 0;
	size += write(1, &c, 1);
	nb = check_flags->fmw - size;
	while (nb > 0)
	{
		size += write(1, " ", 1);
		nb -= 1;
	}
	check_flags->less = 0;
	check_flags->fmw = 0;
	return (size);
}

static int	ft_width_char(int c, t_flags *check_flags)
{
	int	len;
	int	size;

	size = 0;
	len = check_flags->fmw - 1;
	while (len > 0)
	{
		size += write(1, " ", 1);
		len -= 1;
	}
	size += write(1, &c, 1);
	check_flags->fmw = 0;
	return (size);
}

int	ft_check_char(int c, t_flags *check_flags)
{
	int	size;

	size = 0;
	if (check_flags->less == 1)
		return (ft_flag_less_char(c, check_flags));
	if (check_flags->fmw != 0)
		return (ft_width_char(c, check_flags));
	size += write(1, &c, 1);
	return (size);
}
