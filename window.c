/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:40:02 by abarrio-          #+#    #+#             */
/*   Updated: 2023/12/04 15:50:23 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	create_image(t_mlx mlx)
{
	t_data	image;
	
	image.img = mlx_new_image(mlx.mlx, HEIGTH, WIDTH);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length,
								&image.endian);
}

int	end_program(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win1);
	// mlx_destroy_window(mlx->mlx, mlx->win2);
	exit(0);
}


int	key_hooks(int keycode, t_mlx *mlx)
{
	(void)mlx;
	printf("Tecla: %d\n", keycode);
	if (keycode == 53)
		end_program(mlx);
	return (0);
}
int	mouse_hook(int keycode, t_mlx *mlx)
{
	(void)mlx;
	if (keycode == 4) //scroll up
		printf("Raton: %d\n", keycode);
		//be_closer();
	if (keycode == 5) //scroll down
		printf("Raton: %d\n", keycode);
		// be_farder();
	return (0);
}
// int	change_color(int keycode, t_mlx *mlx)
// {
	
// }

void	create_window(void)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	if (mlx.mlx == NULL)
		exit(EXIT_FAILURE);
	mlx.win1 = mlx_new_window(mlx.mlx, HEIGTH, WIDTH, "UwU fractal abarrio- window 1");
	if (mlx.win1 == NULL)
		exit(EXIT_FAILURE);
	// mlx.win2 = mlx_new_window(mlx.mlx, HEIGTH, WIDTH, "UwU fractal abarrio- window 2");
	// if (mlx.win2 == NULL)
	// {
	// 	mlx_destroy_window(mlx.mlx, mlx.win1);
	// 	exit(EXIT_FAILURE);
	// }
	mlx_key_hook(mlx.win1, key_hooks, &mlx);
	// mlx_key_hook(mlx.win2, key_hooks, &mlx);
	mlx_hook(mlx.win1, 17, 0, end_program, &mlx);
	// mlx_hook(mlx.win2, 17, 0, end_program, &mlx);
	mlx_mouse_hook(mlx.win1, mouse_hook, &mlx);
	// mlx_loop_hook(mlx.mlx, change_color, &mlx);
	create_image(mlx);
	mlx_loop(mlx.mlx);
}
