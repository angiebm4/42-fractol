/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:20:15 by abarrio-          #+#    #+#             */
/*   Updated: 2023/12/07 10:48:28 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	move(t_data *data, int keycode)
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
}

static void	color_options(t_data *data, int keycode)
{
	if (keycode == 18)
	{
		data->saturation += 10;
		fractal_render(data);
	}
	else if (keycode == 19)
	{
		data->saturation -= 10;
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
	printf("tecla %d\n", keycode);
	if (keycode == 53)
		end_program(data);
	color_options(data, keycode);
	move(data, keycode);
	return (0);
}
