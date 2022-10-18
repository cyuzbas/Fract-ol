/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cyuzbas <cyuzbas@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 13:23:57 by cyuzbas       #+#    #+#                 */
/*   Updated: 2022/05/03 17:59:17 by cyuzbas       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_pixel_put(t_fractol *fractol, int x, int y, unsigned int color)
{
	char	*dst;
	int		offset;

	if (x < WIDTH && y < HEIGHT && x >= 0 && y >= 0)
	{
		offset = (y * fractol->line_len + x * (fractol->bits_per_pixel / 8));
		dst = fractol->address + offset;
		*(unsigned int *)dst = color;
	}
}

void	choose_fractol(t_fractol *vars)
{
	if (vars->fractol_name == JULIA)
		julia_settings(vars);
	if (vars->fractol_name == MANDELBROT)
		mandelbrot_settings(vars);
	if (vars->fractol_name == BONUS)
		bonus_settings(vars);
}

int	fractol_set_count(t_fractol *vars, double a, double b)
{
	int	count;

	count = 0;
	if (vars->fractol_name == JULIA)
		count = julia(vars, a, b);
	else if (vars->fractol_name == MANDELBROT)
		count = mandelbrot(vars, a, b);
	else if (vars->fractol_name == BONUS)
		count = bonus(vars, a, b);
	return (count);
}

void	draw_fractol(t_fractol *vars, int x, int y)
{
	double	a;
	double	b;
	int		count;

	if (vars->mlx_start)
		choose_fractol(vars);
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			a = (x - (WIDTH / 2)) / vars->view + vars->x;
			b = (y - (HEIGHT / 2)) / vars->view + vars->y;
			count = fractol_set_count(vars, a, b);
			if (count == vars->iter)
				my_pixel_put(vars, x, y, vars->color_max);
			else
				my_pixel_put(vars, x, y, vars->color * count);
			x++;
		}
		y++;
	}
	vars->mlx_start = 0;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}
