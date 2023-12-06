/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:46:28 by abarrio-          #+#    #+#             */
/*   Updated: 2023/12/05 17:05:33 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "libft/ft_printf.h"
# include "libft/libft.h"
# include "mlx/mlx.h"
# include "color.h"

# define WIDTH 1000
# define HEIGTH 1000
# define ITERATIONS 50  // quality and time render

typedef struct	s_fractal
{
	void	*img;
	char	*pix_addr;
	int		bpp; //bytes per pixel
	int		line_len;
	int		endian;
}				t_fractal;

typedef struct	s_data 
{
	char		*name;
	void		*mlx;
	void		*win1;
	void		*win2;
	//image
	t_fractal	*fractal1;
	//
}				t_data;

typedef struct	s_complex
{
	double	real;
	double	imgy;
}				t_complex;

void			create_image(t_data *data);
void			create_window(t_data *data);
void			handel_pixel(int x, int y, t_data *fractal);
int				end_program(t_data *data);
void			fractal_render(t_data	*data);

// math utils
double			scale(double uns_num, double new_min, double new_max);

// hooks
int				key_hooks(int keycode, t_data *data);
int				mouse_hook(int keycode, t_data *data);

#endif