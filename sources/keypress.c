/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keypress.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: cyuzbas <cyuzbas@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 13:34:09 by cyuzbas       #+#    #+#                 */
/*   Updated: 2022/05/03 18:22:01 by cyuzbas       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_move(int keycode, t_fractol *vars)
{
	double	bm_x;
	double	am_x;
	double	bm_y;
	double	am_y;
	int		shift;

	shift = 100;
	if (keycode == KEY_RIGHT || keycode == KEY_LEFT)
	{
		bm_x = ((shift - (WIDTH / 2)) / vars->view + vars->x);
		am_x = ((shift - (WIDTH / 2)) / (vars->view * vars->zoom) + vars->x);
		if (keycode == KEY_RIGHT)
			vars->x -= bm_x - am_x;
		else if (keycode == KEY_LEFT)
			vars->x += bm_x - am_x;
	}
	else if (keycode == KEY_DOWN || keycode == KEY_UP)
	{
		bm_y = ((shift - (HEIGHT / 2)) / vars->view + vars->y);
		am_y = ((shift - (HEIGHT / 2)) / (vars->view * vars->zoom) + vars->y);
		if (keycode == KEY_UP)
			vars->y += bm_y - am_y;
		else if (keycode == KEY_DOWN)
			vars->y -= bm_y - am_y;
	}
}

void	ft_change(int keycode, t_fractol *vars)
{
	if (keycode == KEY_J && vars->fractol_name != JULIA)
	{
		vars->fractol_name = JULIA;
		julia_settings(vars);
	}
	else if (keycode == KEY_M && vars->fractol_name != MANDELBROT)
	{
		vars->fractol_name = MANDELBROT;
		mandelbrot_settings(vars);
	}
	else if (keycode == KEY_B && vars->fractol_name != BONUS)
	{
		vars->fractol_name = BONUS;
		bonus_settings(vars);
	}
}

void	ft_color(int keycode, t_fractol *vars)
{
	if (keycode == NUM_1)
		vars->color = BLUE;
	else if (keycode == NUM_2)
		vars->color = PINK;
	else if (keycode == NUM_3)
		vars->color = SUNNY;
	else if (keycode == NUM_4)
		vars->color = ROSE;
	else if (keycode == NUM_5)
		vars->color = MELON;
	else if (keycode == NUM_6)
		vars->color = GRAY;
	else if (keycode == NUM_7)
		vars->color = LILA;
	else if (keycode == NUM_8)
		vars->color = NAVY;
	else if (keycode == NUM_9)
		vars->color = MINT;
}

void	ft_iteration(int keycode, t_fractol *vars)
{
	if (keycode == KEY_LESS && vars->iter <= vars->iter_min)
		ft_putendl_fd("Minimum Iteration Reached\n", 1);
	else if (keycode == KEY_LESS && vars->iter > vars->iter_min)
		vars->iter -= vars->iter_increase;
	else if (keycode == KEY_MORE && vars->iter >= vars->iter_max)
		ft_putendl_fd("Maximum Iteration Reached\n", 1);
	else if (keycode == KEY_MORE && vars->iter < vars->iter_max)
		vars->iter += vars->iter_increase;
}

int	ft_keypress(int keycode, t_fractol *vars)
{
	if (keycode == KEY_ESC)
		ft_close(vars);
	else if (keycode == KEY_R)
		vars->mlx_start = 1;
	else if (keycode == KEY_DOWN || keycode == KEY_UP || \
			keycode == KEY_RIGHT || keycode == KEY_LEFT)
		ft_move(keycode, vars);
	else if (keycode == KEY_PLUS)
		zoom_in(WIDTH / 2, HEIGHT / 2, vars);
	else if (keycode == KEY_MIN)
		zoom_out(WIDTH / 2, HEIGHT / 2, vars);
	else if (keycode == KEY_J || keycode == KEY_M || keycode == KEY_B)
		ft_change(keycode, vars);
	else if (keycode == KEY_LESS || keycode == KEY_MORE)
		ft_iteration(keycode, vars);
	ft_color(keycode, vars);
	mlx_clear_window(vars->mlx, vars->win);
	draw_fractol(vars, 0, 0);
	return (0);
}
