/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 01:55:48 by lsantana          #+#    #+#             */
/*   Updated: 2022/09/13 04:35:10 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * \
	(data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_fractal(t_frac *frac)
{
	int	x;
	int	y;
	int	n;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			frac->calc.center_x = frac->calc.max_x - frac->calc.min_x;
			frac->calc.center_y = frac->calc.max_y - frac->calc.min_y;
			frac->calc.c_x = frac->calc.min_x + x * \
			frac->calc.center_x / WINDOW_WIDTH;
			frac->calc.c_y = frac->calc.min_y + y * \
			frac->calc.center_y / WINDOW_HEIGHT;
			if (frac->mlx.set == MANDELBROT)
				n = mandelbrot(&frac->calc);
			if (frac->mlx.set == JULIA)
				n = julia(&frac->calc);
			to_color(frac, n, x, y);
			x++;
		}
		y++;
	}
}
