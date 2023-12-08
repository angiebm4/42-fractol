/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:46:28 by abarrio-          #+#    #+#             */
/*   Updated: 2023/12/07 16:25:22 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "color.h"
# include "libft/ft_printf.h"
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <math.h>

// window measures
# define WIDTH 500
# define HEIGTH 500

typedef struct	s_fractal
{
	void		*img;
	char		*pix_addr;
	int 		bpp; 			// bytes per pixel
	int			line_len;
	int			endian;
}				t_fractal;

typedef struct	s_complex
{
	double		real;
	double		imgy;
}				t_complex;

typedef struct	s_data
{
	char 		*name; 			// fractal name
	void		*mlx;
	void 		*win1;          // window 1
	int 		color;          // color options
	int 		saturation;		// color options
	double 		in;           	// no tienen sentido estos nombres
	double 		out;          	// no tienen sentido estos nombres
	int 		iter;           // quality and time render
	double 		move_x;       	// move options
	double 		move_y;       	// move options
	t_fractal 	*fractal1;		// image
	t_complex 	c;         		// complex nb
	t_complex 	z;         		// complex nb
}				t_data;

void		create_image(t_data *data);
void		create_window(t_data *data);

// math utils
double		scale(double uns_num, double new_min, double new_max);

// fractol utils
void		init_stack(t_data *data, char *str);
void		hooking(t_data *data);
int			valid_comands(void);
int			end_program(t_data *data);

// render
void		fractal_render(t_data *data);
void		paint_pixel(int x, int y, t_data *data);
void		my_pixel_put(t_fractal *img, int x, int y, int color);
void		julia_render(t_data *data, double real, double imaginary);

// hooks
int			key_hooks(int keycode, t_data *data);
int			mouse_hook(int keycode, int x, int y, t_data *data);

#endif