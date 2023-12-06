/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uwu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:46:16 by abarrio-          #+#    #+#             */
/*   Updated: 2023/12/05 07:58:25 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	t_complex	z;
	t_complex	c;
	int i = 0;
	double	tmp_real;
	
	z.real = 0;
	z.imgy = 0;

	c.real = 0.25;
	c.imgy	= 0.4;
	while (i < 42)
	{
		//z = z^2 + c
		// i^2 = -1
		// x^2 - y^2  +  2xyi
		tmp_real = (z.real * z.real) - (z.imgy * z.imgy);
		z.imgy = 2 * z.real * z.imgy;
		z.real = tmp_real;
		z.real += c.real;
		z.imgy += c.imgy;
		printf("iteration n -> %d real %f imaginary %f\n", i, z.real, z.imgy);
		i++;
	}
	return(0);
}
