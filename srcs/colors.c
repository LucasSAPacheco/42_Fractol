/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 20:43:08 by lsantana          #+#    #+#             */
/*   Updated: 2022/09/14 03:07:13 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	to_color(t_frac *frac, int n, int x, int y)
{
	if (n == 100)
		my_mlx_pixel_put(&frac->mlx, x, y, 0x000000);
	else
		my_mlx_pixel_put(&frac->mlx, x, y, choose_color(frac, n));
}

int	choose_color(t_frac *frac, int n)
{
	int		r;
	int		g;
	int		b;
	double	t;

	t = (double)n / 100;
	r = (int)(9 * (1 - t) * pow(t, 3) * 25);
	g = (int)(15 * pow(1 - t, 2) * pow(t, 2) * 249);
	b = (int)(8.5 * pow(1 - t, 3) * t * 126);
	return (r << 16 | g << 8 | b);
}
