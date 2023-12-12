/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:45:37 by abarrio-          #+#    #+#             */
/*   Updated: 2023/12/12 11:40:11 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom_out(t_data *data, int x, int y)
{
	int	aux_x;
	int	aux_y;

	aux_x = x;
	aux_y = y;
	if (data->iter <= 50)
		data->iter = 50;
	else
		data->iter -= 2;
	data->scale_x *= 1.1;
	data->scale_y *= 1.1;
	if (!ft_strncmp(data->name, "ship", 4))
	{
		data->move_x += scale(aux_x, -data->scale_x, data->scale_y) * 0.1995;
		data->move_y += scale(aux_y, -data->scale_x, data->scale_y) * 0.1995;
	}
	else
	{
		data->move_x += scale(aux_x, -data->scale_x, data->scale_y) * 0.1995;
		data->move_y += scale(aux_y, data->scale_x, -data->scale_y) * 0.1995;
	}
	fractal_render(data);
}

static void	zoom_in(t_data *data, int x, int y)
{
	int	aux_x;
	int	aux_y;

	aux_x = x;
	aux_y = y;
	data->iter += 2;
	data->scale_x *= 0.9;
	data->scale_y *= 0.9;
	if (!ft_strncmp(data->name, "ship", 4))
	{
		data->move_x += scale(aux_x, -data->scale_x, data->scale_y) * 0.1995;
		data->move_y += scale(aux_y, -data->scale_x, data->scale_y) * 0.1995;
	}
	else
	{
		data->move_x += scale(aux_x, -data->scale_x, data->scale_y) * 0.1995;
		data->move_y += scale(aux_y, data->scale_x, -data->scale_y) * 0.1995;
	}
	fractal_render(data);
}

int	mouse_hook(int keycode, int x, int y, t_data *data)
{
	if (keycode == 4)
		zoom_out(data, x, y);
	if (keycode == 5)
		zoom_in(data, x, y);
	return (0);
}
