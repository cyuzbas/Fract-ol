/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bonus.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cyuzbas <cyuzbas@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/18 20:15:44 by cyuzbas       #+#    #+#                 */
/*   Updated: 2022/05/03 18:18:10 by cyuzbas       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	bonus_settings(t_fractol *vars)
{
	vars->iter = 100;
	vars->iter_increase = 50;
	vars->iter_min = 100;
	vars->iter_max = 1000;
	vars->color = RED;
	vars->color_max = YELLOW;
	vars->view = (WIDTH + HEIGHT) / 8;
	vars->zoom = 1.50;
	vars->x = -0.25;
	vars->y = -0.50;
}

int	bonus(t_fractol *vars, double ca, double cb)
{
	double	temp;
	double	a;
	double	b;
	int		count;

	a = 0;
	b = 0;
	count = 0;
	while (pow(a, 2) + pow(b, 2) < 4 && count < vars->iter)
	{
		temp = pow(a, 2) - pow(b, 2) + ca;
		b = fabs(2 * a * b) + cb;
		a = temp;
		count++;
	}
	return (count);
}
