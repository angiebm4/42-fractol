/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:20:15 by abarrio-          #+#    #+#             */
/*   Updated: 2023/12/06 18:22:46 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	increase_saturation(t_data *data)
{
	data->saturation += 10;
	fractal_render(data);
}

static void	decrease_saturation(t_data *data)
{
	data->saturation -= 10;
	fractal_render(data);
}

static void change_color(t_data *data)
{
	data->color += 5000;
	fractal_render(data);
}

static void change_color1(t_data *data)
{
	data->color -= 5000;
	fractal_render(data);
}

static void init_color(t_data *data)
{
	data->color = WHITE;
	fractal_render(data);
}
void	move(t_data *data, int keycode)
{
	if (keycode == 13 || keycode == 126) //flecha pa arriba
	{
		data->move_y += 0.05;
		fractal_render(data);
	}
	else if (keycode == 0 || keycode == 123) //flecha pa izquierda
	{
		data->move_x -= 0.05;		
		fractal_render(data);
	}
	else if (keycode == 1 || keycode == 125) //flecha pa abajo
	{
		data->move_y -= 0.05;
		fractal_render(data);
	}
	else if (keycode == 2 || keycode == 124) //flecha pa arriba
	{
		data->move_x += 0.05;
		fractal_render(data);
	}
	return ;
}

int	key_hooks(int keycode, t_data *data)
{
	printf("tecla %d\n", keycode);
	if (keycode == 53)
		end_program(data);
	if (keycode == 18)
		increase_saturation(data);
	if (keycode == 19)
		decrease_saturation(data);
	if (keycode == 20)
		change_color(data);
	if (keycode == 21)
		change_color1(data);
	if (keycode == 23)
		init_color(data);
	move(data, keycode);
	return (0);
}

void	zoom_in(t_data *data)
{
	data->iter += 200;
	data->in *= 1.1;
	data->out *= 1.1;
	fractal_render(data);
}

void	zoom_out(t_data *data)
{
	data->iter -= 50;
	data->in *= 0.9;
	data->out *= 0.9;
	fractal_render(data);
}

int	mouse_hook(int keycode, int x, int y, t_data *data)
{
	printf("raton %d\n", keycode);
	x = x + 0;
	y = y + y;
	if (keycode == 4) //scroll up
		zoom_in(data);
	if (keycode == 5) //scroll down
		zoom_out(data);
	return (0);
}

