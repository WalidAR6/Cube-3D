/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharib <aharib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 21:43:45 by aharib            #+#    #+#             */
/*   Updated: 2023/10/12 21:47:26 by aharib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

int	get_map_height(t_win *vars)
{
	char	**tmp;
	int		count;

	count = 0;
	tmp = vars->map;
	while (*tmp)
	{
		count++;
		tmp++;
	}
	return (count - 1);
}

int	check_map_width(t_win *vars, double x, double y)
{
	int	grid;

	grid = y / 50;
	if (x / 50 > (int)ft_strlen(vars->map[grid]))
		return (0);
	return (1);
}

int	is_horizental(t_win *vars, double h_i, double v_i, double n_angle)
{
	if (h_i < v_i)
	{
		vars->dis = cos(n_angle * PI / 180) * h_i;
		return (1);
	}
	else
	{
		vars->dis = cos(n_angle * PI / 180) * v_i;
		return (0);
	}
	return (0);
}

int	wall_leak(t_win *vars, double i, double j)
{
	if (vars->map[(int)vars->player->y_player / 50][(int)j / 50] == '1'
		&& vars->map[(int)i / 50][(int)vars->player->x_player / 50] == '1')
		return (1);
	return (0);
}

void	error_msg(void)
{
	write(2, "\033[31m", 5);
	write(2, "ERROR !!!\n", 10);
	write(2, "\033[0m", 4);
	exit(1);
}
