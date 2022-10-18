/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cyuzbas <cyuzbas@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/15 12:11:09 by cyuzbas       #+#    #+#                 */
/*   Updated: 2022/05/03 16:43:12 by cyuzbas       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init(t_fractol *vars, char *ca, char *cb)
{
	protect(vars->mlx = mlx_init());
	protect(vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "FRACT'OL"));
	protect(vars->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT));
	protect(vars->address = mlx_get_data_addr(vars->img, \
			&vars->bits_per_pixel, &vars->line_len, &vars->endian));
	vars->mlx_start = 1;
	vars->has_args = 0;
	if (vars->fractol_name == JULIA && ca && cb)
	{
		vars->has_args = 1;
		vars->ca_arg = ft_atof(ca);
		vars->cb_arg = ft_atof(cb);
	}
	draw_fractol(vars, 0, 0);
}

void	check_type(t_fractol *vars, int argc, char **argv)
{
	if (argc < 2)
		init_fail();
	if (ft_strcmp(argv[1], "Julia") == 0 && (argc == 4) \
		&& ft_isvalid(argv[2]) && ft_isvalid(argv[3]))
		vars->fractol_name = JULIA;
	else if (ft_strcmp(argv[1], "Mandelbrot") == 0 && argc == 2)
		vars->fractol_name = MANDELBROT;
	else if (ft_strcmp(argv[1], "Bonus") == 0 && argc == 2)
		vars->fractol_name = BONUS;
	else
		init_fail();
}

int	main(int argc, char **argv)
{
	t_fractol	vars;

	check_type(&vars, argc, argv);
	ft_init(&vars, argv[2], argv[3]);
	mlx_hook(vars.win, PRESS_KEY, 0, ft_keypress, &vars);
	mlx_hook(vars.win, PRESS_MOUSE, 0, ft_mouse, &vars);
	mlx_hook(vars.win, RED_X, 0, ft_close, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
