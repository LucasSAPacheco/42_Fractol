/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:01:08 by lsantana          #+#    #+#             */
/*   Updated: 2022/09/14 02:58:20 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	check_errors(int argc, char **argv, t_frac *frac)
{
	if (argc == 1)
	{
		ft_printf("Error: %s\n", ERROR1);
		ft_printf("%s\n%s\n%s\n%s\n", ERRORM, ERRORJ, EX1, EX2);
		exit(0);
	}
	else if ((argc > 4 || argc < 4) && argv[1][0] == 'J')
	{
		ft_printf("Error: %s\n", ERRORJ1);
		ft_printf("%s\n", EX2);
		exit(0);
	}
	else if (frac->mlx.set != 1 && frac->mlx.set != 2)
	{
		ft_printf("Error: %s\n", ERROR1);
		ft_printf("%s\n%s\n%s\n%s\n", ERRORM, ERRORJ, EX1, EX2);
		exit(0);
	}
}
