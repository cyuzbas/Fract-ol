/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cyuzbas <cyuzbas@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/15 12:12:59 by cyuzbas       #+#    #+#                 */
/*   Updated: 2022/05/03 18:18:20 by cyuzbas       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <unistd.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "keys.h"

# define WIDTH 800
# define HEIGHT 800

enum e_type
{
	JULIA		= 1,
	MANDELBROT	= 2,
	BONUS		= 3
};

typedef enum e_events
{
	RED_X		= 17,
	PRESS_KEY	= 02,
	PRESS_MOUSE	= 04,
	MOVE_MOUSE	= 06
}			t_events;

typedef enum s_color
{
	BLACK		= 0x000000,
	GRAY		= 0x808080,
	ROSE		= 0xFF6961,
	RED			= 0x050000,
	GREEN		= 0xCFF0CC,
	BLUE		= 0xADD8E6,
	YELLOW		= 0xFFFF00,
	SUNNY		= 0xFFFACD,
	MELON		= 0xFFDAC1,
	PINK		= 0xEECBDB,
	NAVY		= 0xA7C7E7,
	LILA		= 0xCCCCFF,
	MINT		= 0xB5EAD7,
	BEIGE		= 0xF3E1CE
}			t_color;

typedef struct s_fractol
{
	void		*mlx;
	void		*win;

	void		*img;
	char		*address;
	int			bits_per_pixel;
	int			line_len;
	int			endian;

	int			fractol_name;
	int			mlx_start;
	int			has_args;
	double		ca_arg;
	double		cb_arg;

	int			iter;
	int			iter_increase;
	int			iter_min;
	int			iter_max;

	int			color;
	int			color_max;

	double		view;
	double		zoom;
	double		x;
	double		y;
}				t_fractol;

int		ft_close(t_fractol *fractol);
void	protect(void *vars);
char	*ft_whitespaces(char *s);
int		ft_isvalid(char *str);
void	check_type(t_fractol *vars, int argc, char **argv);
void	init_fail(void);
int		ft_keypress(int keycode, t_fractol *vars);
void	ft_move(int keycode, t_fractol *vars);
void	ft_change(int keycode, t_fractol *vars);
void	ft_color(int keycode, t_fractol *vars);
void	ft_iteration(int keycode, t_fractol *vars);
int		ft_mouse(int mouse_input, int x, int y, t_fractol *vars);
void	zoom_in(int x, int y, t_fractol *img);
void	zoom_out(int x, int y, t_fractol *img);
void	draw_fractol(t_fractol *vars, int x, int y);
void	my_pixel_put(t_fractol *fractol, int x, int y, unsigned int color);
int		fractol_set_count(t_fractol *vars, double a, double b);
void	mandelbrot_settings(t_fractol *vars);
int		mandelbrot(t_fractol *vars, double ca, double cb);
void	julia_settings(t_fractol *vars);
int		julia(t_fractol *vars, double ca, double cb);
void	bonus_settings(t_fractol *vars);
int		bonus(t_fractol *vars, double ca, double cb);

#endif