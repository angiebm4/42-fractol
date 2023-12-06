/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:20:15 by abarrio-          #+#    #+#             */
/*   Updated: 2023/12/05 12:34:05 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hooks(int keycode, t_data *data)
{
	(void)data;
	printf("Tecla: %d\n", keycode);
	if (keycode == 53)
		end_program(data);
	return (0);
}

int	mouse_hook(int keycode, t_data *data)
{
	(void)data;
	if (keycode == 4) //scroll up
		printf("Raton: %d\n", keycode);
		//zoom_in();
	if (keycode == 5) //scroll down
		printf("Raton: %d\n", keycode);
		// zoom_out();
	return (0);
}

