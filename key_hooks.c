/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:20:15 by abarrio-          #+#    #+#             */
/*   Updated: 2023/12/10 21:03:27 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	move(t_data *data, int keycode)
{
	if (keycode == 13 || keycode == 126)
	{
		data->move_y += 0.5 * data->scale_x;
		fractal_render(data);
	}
	else if (keycode == 0 || keycode == 123)
	{
		data->move_x -= 0.5 * data->scale_x;
		fractal_render(data);
	}
	else if (keycode == 1 || keycode == 125)
	{
		data->move_y -= 0.5 * data->scale_x;
		fractal_render(data);
	}
	else if (keycode == 2 || keycode == 124)
	{
		data->move_x += 0.5 * data->scale_x;
		fractal_render(data);
	}
}

int	uwu_mode(t_data *data)
{
	if (data->uwu_mode == 1)
	{
		data->color += 5000;
		fractal_render(data);
		return (0);
	}
	else
		return (1);
}

static void	color_options(t_data *data, int keycode)
{
	if (keycode == 18)
	{
		data->saturation += 50;
		fractal_render(data);
	}
	else if (keycode == 19)
	{
		data->saturation -= 50;
		fractal_render(data);
	}
	else if (keycode == 20)
	{
		data->color += 5000;
		fractal_render(data);
	}
	else if (keycode == 21)
	{
		data->color -= 5000;
		fractal_render(data);
	}
	else if (keycode == 23)
	{
		data->color = WHITE;
		fractal_render(data);
	}
}

int	key_hooks(int keycode, t_data *data)
{
	if (keycode == 53)
		end_program(data);
	color_options(data, keycode);
	move(data, keycode);
	if (keycode == 22)
	{
		data->uwu_mode = !data->uwu_mode;
		fractal_render(data);
	}
	return (0);
}
