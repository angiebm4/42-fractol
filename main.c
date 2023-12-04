/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:46:25 by abarrio-          #+#    #+#             */
/*   Updated: 2023/12/04 12:40:14 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	leaks(void)
{
	system("leaks -q fractol");
}

int	main(int argc, char *str[])
{
	atexit(leaks);
	if (argc < 2 || argc > 4)
		return (write(2, "error\n", 6));
	if (argc == 2 && ft_strncmp("mandelbrot", str[1], 10))
		return (write(2, "error\n", 6));
	// printf("%d\n", ft_strncmp("mandelbrot", str[1], 10));
	create_window();
}