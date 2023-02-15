/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 01:24:46 by lsantana          #+#    #+#             */
/*   Updated: 2022/09/13 04:29:25 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	mandelbrot(t_calc *calc)
{
	int	i;

	i = 0;
	calc->z_y = calc->c_y;
	calc->z_x = calc->c_x;
	while (i < 100)
	{
		calc->temp_y = calc->z_y * calc->z_y;
		calc->temp_x = calc->z_x * calc->z_x;
		calc->z_y = 2 * calc->z_y * calc->z_x + calc->c_y;
		calc->z_x = calc->temp_x - calc->temp_y + calc->c_x;
		if (calc->temp_y + calc->temp_x > 4)
			break ;
		i++;
	}
	return (i);
}

int	julia(t_calc *calc)
{
	int	i;

	i = 0;
	calc->z_y = calc->c_y;
	calc->z_x = calc->c_x;
	while (i < 100)
	{
		calc->temp_y = calc->z_y * calc->z_y;
		calc->temp_x = calc->z_x * calc->z_x;
		calc->z_y = 2 * calc->z_y * calc->z_x + calc->min_k;
		calc->z_x = calc->temp_x - calc->temp_y + calc->max_k;
		if (calc->temp_y + calc->temp_x > 4)
			break ;
		i++;
	}
	return (i);
}
