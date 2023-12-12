/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:46:28 by abarrio-          #+#    #+#             */
/*   Updated: 2023/12/12 11:23:57 by abarrio-         ###   ########.fr       */
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

typedef struct s_fractal
{
	void		*img;
	char		*pix_addr;
	int			bpp;
	int			line_len;
	int			endian;
}				t_fractal;

typedef struct s_complex
{
	double		real;
	double		imgy;
}				t_complex;

typedef struct s_data
{
	char		*name;
	void		*mlx;
	void		*win1;
	int			color;
	int			saturation;
	double		scale_x;
	double		scale_y;
	int			iter;
	double		move_x;
	double		move_y;
	int			uwu_mode;
	int			error;
	t_fractal	*fractal1;
	t_complex	c;
	t_complex	z;
}				t_data;

// math utils
double			scale(double uns_num, double new_min, double new_max);
double			ft_atof_strict(char *str, t_data *data);

// fractol utils
void			init_stack(t_data *data, char *str);
void			hooking(t_data *data);
int				valid_comands(void);
int				end_program(t_data *data);

// render
void			fractal_render(t_data *data);

// hooks
int				key_hooks(int keycode, t_data *data);
int				mouse_hook(int keycode, int x, int y, t_data *data);
int				uwu_mode(t_data *data);

#endif