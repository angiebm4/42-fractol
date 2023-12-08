/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:40:02 by abarrio-          #+#    #+#             */
/*   Updated: 2023/12/07 16:25:06 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	create_image(t_data *data)
{

	data->fractal1->img = mlx_new_image(data->mlx, WIDTH, HEIGTH);
	if (data->fractal1->img == NULL)
		end_program(data);
	data->fractal1->pix_addr = mlx_get_data_addr(data->fractal1->img,
												&data->fractal1->bpp,
												&data->fractal1->line_len,
												&data->fractal1->endian);
}

void	create_window(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		exit(EXIT_FAILURE);
	data->win1 = mlx_new_window(data->mlx, HEIGTH, WIDTH,
								"UwU fractal abarrio- window 1");
	if (data->win1 == NULL)
		exit(EXIT_FAILURE);
}
