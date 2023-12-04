/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:46:28 by abarrio-          #+#    #+#             */
/*   Updated: 2023/12/04 15:17:16 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "libft/ft_printf.h"
# include "libft/libft.h"
# include "mlx/mlx.h"

# define WIDTH 1000
# define HEIGTH 1000

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win1;
	// void	*win2;
	int		color;
}				t_mlx;

// typedef struct	s_color
// {
// 	unsigned char	red;
// 	unsigned char	green;
// 	unsigned char	blue;
// }				t_color;

void	create_window(void);

#endif