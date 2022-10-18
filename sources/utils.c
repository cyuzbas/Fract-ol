/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cyuzbas <cyuzbas@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/02 16:20:42 by cyuzbas       #+#    #+#                 */
/*   Updated: 2022/05/03 17:35:04 by cyuzbas       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	protect(void *vars)
{
	if (vars == NULL)
		exit(EXIT_FAILURE);
}

int	ft_close(t_fractol *vars)
{
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(EXIT_SUCCESS);
}

int	ft_isvalid(char *str)
{
	int	i;
	int	dot;

	i = 0;
	dot = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' \
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] == '.')
			dot++;
		if (!ft_isdigit(str[i]) && str[i] != '.')
			return (0);
		i++;
	}
	if (dot > 1)
		return (0);
	return (1);
}

void	init_fail(void)
{
	ft_putendl_fd("Invalid input!", 1);
	ft_putendl_fd("Usage: ./fractol <set_name>", 1);
	ft_putendl_fd("Julia, Mandelbrot OR Bonus", 1);
	ft_putendl_fd("Julia should take two floats as parameter", 1);
	exit (EXIT_FAILURE);
}
