/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mouse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cyuzbas <cyuzbas@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 13:13:48 by cyuzbas       #+#    #+#                 */
/*   Updated: 2022/05/03 18:16:46 by cyuzbas       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(int x, int y, t_fractol *vars)
{
	double	bz_x;
	double	az_x;
	double	bz_y;
	double	az_y;

	bz_x = ((x - (WIDTH / 2)) / vars->view + vars->x);
	az_x = ((x - (WIDTH / 2)) / (vars->view * vars->zoom) + vars->x);
	bz_y = ((y - (HEIGHT / 2)) / vars->view + vars->y);
	az_y = ((y - (HEIGHT / 2)) / (vars->view * vars->zoom) + vars->y);
	vars->view *= vars->zoom;
	vars->x += bz_x - az_x;
	vars->y += bz_y - az_y;
}

void	zoom_out(int x, int y, t_fractol *vars)
{
	double	bz_x;
	double	az_x;
	double	bz_y;
	double	az_y;

	bz_x = ((x - (WIDTH / 2)) / vars->view + vars->x);
	az_x = ((x - (WIDTH / 2)) / (vars->view * vars->zoom) + vars->x);
	bz_y = ((y - (HEIGHT / 2)) / vars->view + vars->y);
	az_y = ((y - (HEIGHT / 2)) / (vars->view * vars->zoom) + vars->y);
	vars->view /= vars->zoom;
	vars->x -= bz_x - az_x;
	vars->y -= bz_y - az_y;
}

int	ft_mouse(int mouse_input, int x, int y, t_fractol *vars)
{
	if (mouse_input == SCR_DOWN)
		zoom_in(x, y, vars);
	else if (mouse_input == SCR_UP)
		zoom_out(x, y, vars);
	mlx_clear_window(vars->mlx, vars->win);
	draw_fractol(vars, 0, 0);
	return (0);
}
