/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cyuzbas <cyuzbas@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/18 20:15:59 by cyuzbas       #+#    #+#                 */
/*   Updated: 2022/05/03 18:18:03 by cyuzbas       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_settings(t_fractol *vars)
{
	if (!vars->has_args)
	{
		vars->ca_arg = -0.75;
		vars->cb_arg = 0.11;
	}
	vars->iter = 100;
	vars->iter_increase = 100;
	vars->iter_min = 100;
	vars->iter_max = 1500;
	vars->color = GREEN;
	vars->color_max = BEIGE;
	vars->view = (WIDTH + HEIGHT) / 8;
	vars->zoom = 1.50;
	vars->x = 0;
	vars->y = 0;
}

int	julia(t_fractol *vars, double ca, double cb)
{
	double	temp;
	int		count;

	count = 0;
	while (pow(ca, 2) + pow(cb, 2) < 4 && count < vars->iter)
	{
		temp = pow(ca, 2) - pow(cb, 2) + vars->ca_arg;
		cb = 2 * ca * cb + vars->cb_arg;
		ca = temp;
		count++;
	}
	return (count);
}
