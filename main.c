/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:46:25 by abarrio-          #+#    #+#             */
/*   Updated: 2023/12/07 16:51:01 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	leaks(void)
{
	system("leaks -q fractol");
}

int	main(int argc, char *argv[])
{
	t_data	*data;
	
	data = malloc (sizeof (t_data));
	if (!data)
		return (EXIT_FAILURE);
	atexit(leaks);
	if ((argc == 2 && !ft_strncmp("mandelbrot", argv[1], 10))
		|| (argc == 4 && !ft_strncmp("julia", argv[1], 5)))
	{
		init_stack(data, argv[1]);
		create_window(data);
		create_image(data);
		if (!ft_strncmp("julia", data->name, 5))
			data->c.real = ft_atof(argv[2]);
			data->c.imgy = ft_atof(argv[3]);
		fractal_render(data);
		hooking(data);
	}
	else
		return (valid_comands()); 
	return (0);
}
