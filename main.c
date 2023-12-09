/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:46:25 by abarrio-          #+#    #+#             */
/*   Updated: 2023/12/09 19:05:55 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	leaks(void)
{
	system("leaks -q fractol");
}
static void	create_image(t_data *data)
{
	data->fractal1->img = mlx_new_image(data->mlx, WIDTH, HEIGTH);
	if (data->fractal1->img == NULL)
		end_program(data);
	data->fractal1->pix_addr = mlx_get_data_addr(data->fractal1->img,
													&data->fractal1->bpp,
													&data->fractal1->line_len,
													&data->fractal1->endian);
}

static void	create_window(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		exit(EXIT_FAILURE);
	data->win1 = mlx_new_window(data->mlx, HEIGTH, WIDTH,
			"UwU fractal abarrio- window 1");
	if (data->win1 == NULL)
		exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	atexit(leaks);
	if ((argc == 2 && (!ft_strncmp(argv[1], "mandelbrot", 11)
				|| !ft_strncmp(argv[1], "ship", 5))) || (argc == 4
				&& !ft_strncmp(argv[1], "julia", 6)))
	{
		data = malloc(sizeof(t_data));
		if (!data)
			return (EXIT_FAILURE);
		init_stack(data, argv[1]);
		create_window(data);
		create_image(data);
		if (!ft_strncmp("julia", data->name, 5))
		{
			data->c.real = ft_atof(argv[2]);
			data->c.imgy = ft_atof(argv[3]);
		}
		fractal_render(data);
		hooking(data);
	}
	else
		return (valid_comands());
	return (0);
}
