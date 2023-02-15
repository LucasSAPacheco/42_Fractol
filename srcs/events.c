/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 22:05:24 by lsantana          #+#    #+#             */
/*   Updated: 2022/09/13 21:53:33 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	init_window(t_data *f)
{
	f->mlx = mlx_init();
	if (f->mlx == NULL)
		exit (1);
	f->win = mlx_new_window(f->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Fractol!");
	f->img = mlx_new_image(f->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	f->addr = mlx_get_data_addr(f->img, &f->bits_per_pixel, &f->line_lenght, \
	&f->endian);
}

void	init_variables(t_frac *frac, char **argv)
{
	frac->calc.min_x = -1.5;
	frac->calc.min_y = -1.5;
	frac->calc.max_x = 1.5;
	frac->calc.max_y = 1.5;
	if (frac->mlx.set == 2)
	{
		frac->calc.max_k = ft_atof(argv[2]);
		frac->calc.min_k = ft_atof(argv[3]);
	}
}

int	zoom(int key, int x, int y, t_frac *frac)
{
	if (key == 5 && y)
	{	
		frac->calc.min_x *= 1.05;
		frac->calc.max_x *= 1.05;
		frac->calc.min_y *= 1.05;
		frac->calc.max_y *= 1.05;
	}
	if (key == 4 && x)
	{	
		frac->calc.min_x *= 0.95;
		frac->calc.max_x *= 0.95;
		frac->calc.min_y *= 0.95;
		frac->calc.max_y *= 0.95;
	}
	reender(frac);
	return (0);
}
