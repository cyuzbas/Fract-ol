/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atof.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cyuzbas <cyuzbas@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 13:58:10 by cyuzbas       #+#    #+#                 */
/*   Updated: 2022/05/03 17:22:10 by cyuzbas       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v' \
	|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

static int	check_space(const char *str)
{
	int	spaces;

	spaces = 0;
	while (ft_isspace(str[spaces]))
		spaces++;
	return (spaces);
}

static int	check_precision(const char *str)
{
	if (*str == '.')
		return (1);
	else
		return (0);
}

double	ft_atof(const char *str)
{
	int			i;
	int			sign;
	int			power;
	double		num;

	i = check_space(str);
	sign = 1;
	num = 0;
	power = 1;
	if (str[i] == '-' && ft_isdigit(str[i + 1]))
	{
		sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
		num = num * 10 + (str[i++] - '0');
	i += check_precision(&str[i]);
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + (str[i] - '0');
		power *= 10;
		i++;
	}
	return (sign * (num / power));
}
