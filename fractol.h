/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 21:21:46 by lsantana          #+#    #+#             */
/*   Updated: 2022/09/14 05:16:13 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 600

# define ESC 65307
# define SCROLL_UP 4
# define SCROLL_DOWN 5

# define MANDELBROT 1
# define JULIA 2

# include "./mylibs/ft_printf.h"
# include "errors.h"
# include <stdlib.h>
# include <string.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>
# include <math.h>

typedef struct s_data {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
	int		set;
}	t_data;

typedef struct s_calc {
	double	center_x;
	double	max_x;
	double	min_x;
	double	center_y;
	double	max_y;
	double	min_y;
	double	z_y;
	double	z_x;
	double	temp_y;
	double	temp_x;
	double	c_y;
	double	c_x;
	double	x;
	double	y;
	double	max_k;
	double	min_k;
}	t_calc;

typedef struct s_frac {
	t_data	mlx;
	t_calc	calc;
}	t_frac;

void		init_window(t_data *f);
void		init_image(t_data *f);
void		draw_fractal(t_frac *frac);
int			mandelbrot(t_calc *calc);
int			julia(t_calc *calc);
void		init_variables(t_frac *frac, char **argv);
int			zoom(int key, int x, int y, t_frac *frac);
void		reender(t_frac *s);
int			choose_fractal(int argc, char **argv, t_frac *frac);
void		to_color(t_frac *frac, int n, int x, int y);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			choose_color(t_frac *frac, int n);
void		check_errors(int argc, char **argv, t_frac *frac);

#endif