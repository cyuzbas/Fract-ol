/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cyuzbas <cyuzbas@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 11:16:36 by cyuzbas       #+#    #+#                 */
/*   Updated: 2022/05/03 18:26:49 by cyuzbas       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_settings(t_fractol *vars)
{
	vars->iter = 50;
	vars->iter_increase = 25;
	vars->iter_min = 50;
	vars->iter_max = 500;
	vars->color = GREEN;
	vars->color_max = BLACK;
	vars->view = (WIDTH + HEIGHT) / 8;
	vars->zoom = 1.50;
	vars->x = 0;
	vars->y = 0;
}

int	mandelbrot(t_fractol *vars, double ca, double cb)
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
		b = 2 * a * b + cb;
		a = temp;
		count++;
	}
	return (count);
}
