/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mause_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:45:37 by abarrio-          #+#    #+#             */
/*   Updated: 2023/12/08 12:35:11 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom_out(t_data *data, int x, int y)
{
	if (data->iter <= 50)
		data->iter = 50;
	else
		data->iter -= 50;
	
	data->in *= 1.1;
	data->out *= 1.1;
	x += x;
	y += y;
	fractal_render(data);
}

static void	zoom_in(t_data *data, int x, int y)
{
	data->iter += 100;
	data->in *= 0.9;
	data->out *= 0.9;
	x += x;
	y += y;
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
