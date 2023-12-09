/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:01:57 by abarrio-          #+#    #+#             */
/*   Updated: 2023/12/09 18:24:46 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	end_program(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win1);
	exit(0);
}

int	valid_comands(void)
{
	write(1, "\x1B[38;2;255;128;0m", 18);
	write(1, "BRO, U CANT DO THAT\n", 20);
	write(1, "PLEASE DONT BE STUPID AND PUT:\n", 32);
	write(1, "\x1b[34m", 6);
	write(1, "\t./fractol mandelbrot\n", 23);
	write(1, "\t./fractol julia <real> <imaginary>\n", 37);
	write(1, "\t./ship\n", 8);
	write(1, "\033[0m", 5);
	return (EXIT_FAILURE);
}

int	uwu_mode(t_data *data) // eso es una basura
{
	if (data->uwu_mode == 1)
	{
		data->color += 100;
		fractal_render(data);
		printf("%d\n", data->color);
		return (0);
	}
	else
		return (1);
}

int ft_zoom(int x, int y, void *data)
{
	
}

void	hooking(t_data *data)
{
	mlx_mouse_hook(data->win1, mouse_hook, data);
	mlx_key_hook(data->win1, key_hooks, data);
	mlx_hook(data->win1, 17, 0, end_program, data);
	mlx_loop_hook(data->mlx, uwu_mode, data);
	mlx_hook(data->win1, 6, 1L << 6, ft_zoom, data);
	mlx_loop(data->mlx);
}

void	init_stack(t_data *data, char *str)
{
	ft_bzero(data, sizeof(t_data));
	data->name = str;
	data->color = WHITE;
	data->saturation = 0;
	data->in = 2.0;
	data->out = -2.0;
	data->iter = 200;
	data->move_x = 0.0;
	data->move_y = 0.0;
	data->uwu_mode = 0;
	if (!ft_strncmp(str, "ship", 4))
	{
		data->in = 1.0;
		data->out = 2.5;
	}
	data->fractal1 = malloc(sizeof(t_fractal));
	if (data->fractal1 == NULL)
		end_program(data);
}
