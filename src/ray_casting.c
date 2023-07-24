/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:17:00 by waraissi          #+#    #+#             */
/*   Updated: 2023/07/24 19:00:41 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

// void	find_wall_x(t_win *vars, double Xa)
// {
// 	while (true)
// 	{
		
// 	}
// }

int	looking_direction(t_win *vars)
{
	if (vars->player->view_angle >= 0 && vars->player->view_angle <= 180)
		return (-1);
	return (1);
}

int	looking_direction_2(t_win *vars)
{
	if (vars->player->view_angle >= 90 && vars->player->view_angle <= 270)
		return (1);
	return (-1);
}

void	DDA(t_data *data, t_win *vars, int x, int y)
{
	double dx;
	double dy;
	double xinc;
	double yinc;
	double xp;
	double yp;
	int		i;
	int		step;
	
	i = 0;
	xp = vars->player->x_player;
	yp = vars->player->y_player;
	dx = x - vars->player->x_player;
	dy = y - vars->player->y_player;
	if (fabs(dx) > fabs(dy))
		step = fabs(dx);
	else
		step = fabs(dy);
	xinc = dx/step;
	yinc = dy/step;
	while (i < step)
	{
		my_mlx_pixel_put(data, xp, yp, 0xFF0000);
		xp += xinc;
		yp += yinc;
		i++;
	}
}

void	intersection_with_horizontal(t_win *vars, t_data *data)
{
	(void)data;
	double x;
	double y;
	double xa;
	double ya;
	double t;
	
	t = tan(vars->player->view_angle * PI / 180);
	if (looking_direction(vars) == -1)
	{
		ya = 50;
		xa = ya / t;
		y = floor(vars->player->y_player / 50) * 50 + 50;
	}
	else
	{
		ya = -50;
		xa = ya / t;
		y = floor(vars->player->y_player / 50) * 50 - 1;
	}
	x = vars->player->x_player + (y - vars->player->y_player) / t;
	while (vars->map[(int)y / 50][(int)x / 50] != '1')
	{
		x = x + xa;
		y = y + ya;
	}
	DDA(data, vars, x, y);
}

void	intersection_with_vertical(t_win *vars, t_data *data)
{
	(void)data;
	double x;
	double y;
	double xa;
	double ya;
	double t;

	t = tan(vars->player->view_angle * PI / 180);
	if (looking_direction_2(vars) == -1)
	{
		xa = 50;
		ya = xa * t;
		x = floor(vars->player->x_player / 50) * 50 + 50;
	}
	else
	{
		xa = -50;
		ya = xa * t;
		x = floor(vars->player->x_player / 50) * 50 - 1;
	}
	y = vars->player->y_player + (x - vars->player->x_player) * tan(vars->player->view_angle * PI / 180);
	// while (vars->map[(int)y / 50][(int)x / 50] != '1')
	// {
	// 	x = x + xa;
	// 	y = y + ya;
	// }
	// DDA(data, vars, x, y);
}

void	start_ray_casting(t_win *vars, t_data *data)
{
	intersection_with_horizontal(vars, data);
	intersection_with_vertical(vars, data);
}
