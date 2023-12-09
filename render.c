/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:56:25 by abarrio-          #+#    #+#             */
/*   Updated: 2023/12/09 19:05:12 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_put(t_fractal *img, int x, int y, int color)
{
	int	offset;

	offset = (img->line_len * y) + (x * (img->bpp / 8));
	*((unsigned int *)(offset + img->pix_addr)) = color;
}
static void	paint_pixel(int x, int y, t_data *data)
{
	int		i;
	double	tmp_r;
	int		aux_color;

	i = 0;
	aux_color = data->color;
	data->z.real = 0.0;
	data->z.imgy = 0.0;
	data->c.real = scale(x, data->out, data->in) + data->move_x;
	data->c.imgy = scale(y, data->in, data->out) + data->move_y;
	while ((data->z.real * data->z.real) + (data->z.imgy * data->z.imgy) <= 2
		* 2 && i < data->iter)
	{
		tmp_r = (data->z.real * data->z.real) - (data->z.imgy * data->z.imgy);
		data->z.imgy = 2 * data->z.real * data->z.imgy;
		data->z.real = tmp_r;
		data->z.real += data->c.real;
		data->z.imgy += data->c.imgy;
		data->color += data->saturation;
		i++;
	}
	if (i == data->iter)
		data->color = BLACK;
	my_pixel_put(data->fractal1, x, y, data->color);
	data->color = aux_color;
}

static void	paint_pixel_julia(int x, int y, t_data *data)
{
	int		i;
	double	tmp_r;
	int		aux_color;

	i = 0;
	aux_color = data->color;
	data->z.real = scale(x, data->out, data->in) + data->move_x;
	data->z.imgy = scale(y, data->in, data->out) + data->move_y;
	while ((data->z.real * data->z.real) + (data->z.imgy * data->z.imgy) <= 2
		* 2 && i < data->iter)
	{
		tmp_r = (data->z.real * data->z.real) - (data->z.imgy * data->z.imgy);
		data->z.imgy = 2 * data->z.real * data->z.imgy;
		data->z.real = tmp_r;
		data->z.real += data->c.real;
		data->z.imgy += data->c.imgy;
		data->color += data->saturation;
		i++;
	}
	if (i == data->iter)
		data->color = BLACK;
	my_pixel_put(data->fractal1, x, y, data->color);
	data->color = aux_color;
}

void	paint_pixel_ship(int x, int y, t_data *data)
{
	int		i;
	double	tmp_r;
	int		aux_color;

	i = 0;
	aux_color = data->color;
	data->z.real = 0.0;
	data->z.imgy = 0.0;
	data->c.real = scale(x, -data->out, data->in) + data->move_x;
	data->c.imgy = scale(y, -data->in, data->in) + data->move_y;
	while ((data->z.real * data->z.real) + (data->z.imgy * data->z.imgy) <= 2
		* 2 && i < data->iter)
	{
		tmp_r = (data->z.real * data->z.real) - (data->z.imgy * data->z.imgy);
		data->z.imgy = fabs(2 * data->z.real * data->z.imgy);
		data->z.real = tmp_r;
		data->z.real += data->c.real;
		data->z.imgy += data->c.imgy;
		data->color += data->saturation;
		i++;
	}
	if (i == data->iter)
		data->color = BLACK;
	my_pixel_put(data->fractal1, x, y, data->color);
	data->color = aux_color;
}

void	fractal_render(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGTH)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (!ft_strncmp(data->name, "mandelbrot", 10))
				paint_pixel(x, y, data);
			else if (!ft_strncmp(data->name, "julia", 5))
				paint_pixel_julia(x, y, data);
			else if (!ft_strncmp(data->name, "ship", 4))
				paint_pixel_ship(x, y, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win1, data->fractal1->img, 0, 0);
}
