/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 22:15:35 by lsantana          #+#    #+#             */
/*   Updated: 2022/09/13 20:02:02 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnumber(char *nbr)
{
	int	len;

	len = ft_strlen(nbr);
	if (nbr[len - 1] == '.')
		return (0);
	while (*nbr)
	{
		if (ft_isalpha(*nbr))
			return (0);
		nbr++;
	}
	if (*nbr == '+' || *nbr == '-')
		nbr++;
	if (*nbr == '.')
		return (0);
	while (ft_isdigit(*nbr))
		nbr++;
	if (!(*nbr))
		return (1);
	nbr++;
	while (ft_isdigit(*nbr))
		nbr++;
	if (*nbr)
		return (0);
	return (1);
}
