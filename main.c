/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 21:22:54 by lsantana          #+#    #+#             */
/*   Updated: 2022/09/14 20:00:44 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_close(t_frac *s)
{
	mlx_destroy_image(s->mlx.mlx, s->mlx.img);
	mlx_destroy_window(s->mlx.mlx, s->mlx.win);
	mlx_destroy_display(s->mlx.mlx);
	free(s->mlx.mlx);
	exit (0);
}

int	key_pressed(int key_code, t_frac *s)
{
	if (key_code == ESC)
		ft_close(s);
	return (0);
}

void	reender(t_frac *s)
{
	mlx_clear_window(s->mlx.mlx, s->mlx.win);
	draw_fractal(s);
	mlx_put_image_to_window(s->mlx.mlx, s->mlx.win, s->mlx.img, 0, 0);
}

int	choose_fractal(int argc, char **argv, t_frac *frac)
{
	frac->mlx.set = 0;
	if (argc == 2 && argv[1][0] == 'M')
	{
		frac->mlx.set = 1;
	}
	else if (argc == 4 && argv[1][0] == 'J')
	{
		if (ft_isnumber(argv[2]) && ft_isnumber(argv[3]))
		{
			frac->mlx.set = 2;
		}
	}
	else
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_frac	frac;

	choose_fractal(argc, argv, &frac);
	check_errors(argc, argv, &frac);
	init_window(&frac.mlx);
	init_variables(&frac, argv);
	draw_fractal(&frac);
	mlx_put_image_to_window(frac.mlx.mlx, frac.mlx.win, frac.mlx.img, 0, 0);
	mlx_mouse_hook(frac.mlx.win, &zoom, &frac);
	mlx_hook(frac.mlx.win, 02, 1L << 0, &key_pressed, &frac);
	mlx_hook(frac.mlx.win, 17, 1L << 2, &ft_close, &frac);
	mlx_loop(frac.mlx.mlx);
	return (0);
}
