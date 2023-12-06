/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:56:25 by abarrio-          #+#    #+#             */
/*   Updated: 2023/12/06 18:19:24 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_put(t_fractal *img, int x, int y, int color)
{
	int offset;

	offset = (img->line_len * y) + (x * (img->bpp / 8));
	*((unsigned int *)(offset + img->pix_addr)) = color; 
}
void	paint_pixel(int x, int y, t_data *data)
{
	t_complex	z;
	t_complex	c;
	int i = 0;
	double	tmp_real;
	int	color;
	
	color = data->color;
	z.real = 0.0;
	z.imgy = 0.0;
	c.real = scale(x, data->out, data->in) + data->move_x;
	c.imgy	= scale(y, data->in, data->out) + data->move_y;
	while ((z.real * z.real) + (z.imgy * z.imgy) <= 2*2 && i < data->iter)
	{
		tmp_real = (z.real * z.real) - (z.imgy * z.imgy);
		z.imgy = 2 * z.real * z.imgy;
		z.real = tmp_real;
		z.real += c.real;
		z.imgy += c.imgy;
		data->color += data->saturation;
		i++;
	}
	if (i == data->iter)
		data->color = BLACK;
	my_pixel_put(data->fractal1, x, y, data->color);
	data->color = color;
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
			paint_pixel(x, y, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win1, data->fractal1->img, 0, 0);
}

