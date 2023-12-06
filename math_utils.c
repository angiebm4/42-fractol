/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:39:41 by abarrio-          #+#    #+#             */
/*   Updated: 2023/12/05 10:42:38 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scale(double uns_num, double new_min, double new_max)
{
	double old_min;
	double old_max;

	old_min = 0;
	old_max = WIDTH - 1;
	return ((new_max - new_min) * (uns_num - old_min) / (old_max - old_min) 
			+ new_min);
}
