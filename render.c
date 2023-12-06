/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:56:25 by abarrio-          #+#    #+#             */
/*   Updated: 2023/12/06 12:02:08 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_put(t_fractal *img, int x, int y, int color)
{
	int offset;

	offset = (img->line_len * y) + (x * (img->bpp / 8));
	*((unsigned int *)(offset + img->pix_addr)) = color; 
}

void	handel_pixel(int x, int y, t_data *data)
{
	t_complex	z;
	t_complex	c;
	int i = 0;
	double	tmp_real;
	
	(void)data;
	z.real = 0.0;
	z.imgy = 0.0;
	c.real = scale(x, -2, 2);
	c.imgy	= scale(y, 2, -2);
	while (i < ITERATIONS)
	{
		double h = (z.real * z.real) + (z.imgy * z.imgy);
		h = h * h;
		if (h > 2.0)
		{
			my_pixel_put(data->fractal1, x, y, GREEN);
			return ;
		}
		tmp_real = (z.real * z.real) - (z.imgy * z.imgy);
		z.imgy = 2 * z.real * z.imgy;
		z.real = tmp_real;
		z.real += c.real;
		z.imgy += c.imgy;
		// printf("iteration n -> %d real %f imaginary %f\n", i, z.real, z.imgy);
		i++;
	}
	my_pixel_put(data->fractal1, x, y, BLACK);
}

void	fractal_render(t_data	*data)
{
	int	x;
	int	y;
	
	y = 0;
	while(y < HEIGTH)
	{
		x = 0;
		while (x < WIDTH)
		{
			handel_pixel(x, y, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win1, data->fractal1->img, 0, 0);
}

