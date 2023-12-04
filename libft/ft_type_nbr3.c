/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:53:05 by abarrio-          #+#    #+#             */
/*   Updated: 2023/10/21 19:40:00 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_case_one_pre_nbr(long nb, t_flags *check_flags)
{
	int	size;

	size = 0;
	check_flags->fmw = check_flags->pre;
	size += ft_flag_zero_nbr(nb, check_flags);
	ft_initialize_struct(check_flags);
	return (size);
}

int	ft_case_two_pre_nbr(long nb, t_flags *check_flags)
{
	int	size;

	size = 0;
	if (nb == 0 && (check_flags->fmw == 0 || check_flags->fmw == 1)
		&& (check_flags->space == 1 || check_flags->plus == 0))
	{
		ft_initialize_struct(check_flags);
		return (size += write(1, " ", 1));
	}
	if (check_flags->less == 0)
		size += ft_prewidth_nbr(nb, check_flags);
	else
		size += ft_flag_less_nbr(nb, check_flags);
	ft_initialize_struct(check_flags);
	return (size);
}

int	ft_case_three_pre_nbr(long nb, t_flags *check_flags)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	ft_count_sign(check_flags);
	if (ft_count_nbr(nb, 0) >= check_flags->pre)
		i = check_flags->fmw - ft_count_nbr(nb, 0) - check_flags->byte;
	else if (ft_count_nbr(nb, 0) < check_flags->pre)
		i = check_flags->fmw - check_flags->pre - check_flags->byte;
	while (i-- > 0)
		size += write(1, " ", 1);
	size += ft_check_sign(check_flags);
	i = check_flags->pre - ft_count_nbr(nb, 0);
	while (i-- > 0)
		size += write(1, "0", 1);
	size += ft_putnbr(nb, 0, check_flags);
	ft_initialize_struct(check_flags);
	return (size);
}

int	ft_case_three2_pre_nbr(long nb, t_flags *check_flags)
{
	int	size;
	int	i;

	size = 0;
	size += ft_check_sign(check_flags);
	i = check_flags->pre - ft_count_nbr(nb, 0);
	while (i-- > 0)
		size += write(1, "0", 1);
	size += ft_putnbr(nb, 0, check_flags);
	if (ft_count_nbr(nb, 0) >= check_flags->pre)
		i = check_flags->fmw - ft_count_nbr(nb, 0) - check_flags->byte;
	else if (ft_count_nbr(nb, 0) < check_flags->pre)
		i = check_flags->fmw - check_flags->pre - check_flags->byte;
	while (i-- > 0)
		size += write(1, " ", 1);
	ft_initialize_struct(check_flags);
	return (size);
}

int	ft_case_four_pre_nbr(long nb, t_flags *check_flags)
{
	int	size;
	int	i;

	size = 0;
	size += ft_check_sign(check_flags);
	i = check_flags->pre - ft_count_nbr(nb, 0);
	while (i-- > 0)
		size += write(1, "0", 1);
	size += ft_putnbr(nb, 0, check_flags);
	ft_initialize_struct(check_flags);
	return (size);
}
