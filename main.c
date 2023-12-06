/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:46:25 by abarrio-          #+#    #+#             */
/*   Updated: 2023/12/05 17:06:38 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	leaks(void)
{
	system("leaks -q fractol");
}

int	end_program(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win1);
	mlx_destroy_window(data->mlx, data->win2);
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
	write(1, "\033[0m", 5);
	
	return(EXIT_FAILURE);
}

int	main(int argc, char *str[])
{
	t_data	data;
	
	atexit(leaks);
	if ((argc == 2 && !ft_strncmp("mandelbrot", str[1], 10))
		|| (argc == 4 && !ft_strncmp("julia", str[1], 5)))
	{
		create_window(&data);
		create_image(&data);
		fractal_render(&data);
		mlx_key_hook(data.win1, key_hooks, &data);
		mlx_key_hook(data.win2, key_hooks, &data);
		mlx_hook(data.win1, 17, 0, end_program, &data);
		mlx_hook(data.win2, 17, 0, end_program, &data);
		mlx_mouse_hook(data.win1, mouse_hook, &data);
		mlx_mouse_hook(data.win2, mouse_hook, &data);
		mlx_loop(data.mlx);
	}
	else
		return (valid_comands()); 
	return (0);
}
