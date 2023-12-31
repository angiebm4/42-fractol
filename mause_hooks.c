/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mause_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:45:37 by abarrio-          #+#    #+#             */
/*   Updated: 2023/12/10 19:47:40 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom_out(t_data *data, int x, int y)
{
	double	aux_x;
	double	aux_y;
	
	if (data->iter <= 50)
		data->iter = 50;
	else
		data->iter -= 2;
	printf("x ----> %d\n", x);
	printf("y ----> %d\n", y);
	data->coor_x = scale(x, -2, 2);
	data->coor_y = scale(y, 2, -2);
	data->zoom *= 1.1;
	aux_x = scale(x, -2, 2) - data->c.real;
	aux_y = scale(y, 2, -2) - data->c.imgy;
	data->zoom *= 1.1;
	data->coor_x = aux_x * 0.7 / 3;
	data->coor_y = aux_y * 0.7 / 3;
	data->zoom *= 1.1;
	fractal_render(data);
}

static void	zoom_in(t_data *data, int x, int y)
{
	double	aux_x;
	double	aux_y;
	
	data->iter += 2;
	printf("x ----> %d\n", x);
	printf("y ----> %d\n", y);
	aux_x = scale(x, -2, 2) - data->c.real;
	aux_y = scale(y, 2, -2) - data->c.imgy;
	data->zoom *= 0.9;
	data->coor_x = aux_x * 0.7 / 3;
	data->coor_y = aux_y * 0.7 / 3;
	
	fractal_render(data);
}

int	mouse_hook(int keycode, int x, int y, t_data *data)
{
	printf("raton %d\n", keycode);
	x = x + 0;
	y = y + y;
	if (keycode == 4) //scroll up
		zoom_out(data, x, y);
	if (keycode == 5) //scroll down
		zoom_in(data, x, y);
	return (0);
}
