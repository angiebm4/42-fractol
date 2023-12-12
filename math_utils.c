/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:39:41 by abarrio-          #+#    #+#             */
/*   Updated: 2023/12/12 11:39:57 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scale(double uns_num, double new_min, double new_max)
{
	double	old_min;
	double	old_max;

	old_min = 0;
	old_max = WIDTH - 1;
	return ((new_max - new_min) * (uns_num - old_min) / (old_max - old_min)
		+ new_min);
}

static double	ft_atof2_strict(char *str, double nb)
{
	double	dec;
	double	aux;

	dec = 10;
	while (*str >= '0' && *str <= '9')
	{
		nb = ((*str - '0') + (nb * 10));
		str++;
	}
	if (*str == '.')
	{
		dec = 10;
		str++;
		while (*str >= '0' && *str <= '9')
		{
			aux = ((*str - '0'));
			nb = nb + (aux / dec);
			dec *= 10;
			str++;
		}
	}
	return (nb);
}

double	ft_atof_strict(char *str, t_data *data)
{
	double	nb;
	int		sing;

	nb = 0;
	sing = 0;
	while ((*str <= 13 && *str >= 9) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sing = 1;
		str++;
	}
	nb = ft_atof2_strict(str, nb);
	if (*str < '0' || *str > '9')
		data->error = 1;
	if (sing == 1)
		nb = nb * -1;
	return (nb);
}
