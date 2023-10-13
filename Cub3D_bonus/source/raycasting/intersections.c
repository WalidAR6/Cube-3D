/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharib <aharib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:03:49 by waraissi          #+#    #+#             */
/*   Updated: 2023/10/13 03:11:07 by aharib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

void	modify_angle(double *angle)
{
	if (*angle > 360)
		*angle = *angle - 360.0;
	else if (*angle < 0)
		*angle = 360.0 - fabs(*angle);
}

int	looking_direction(t_win *vars, double i)
{
	double	angle;

	angle = vars->player->view_angle + i;
	modify_angle(&angle);
	if (angle >= 0 && angle <= 180)
		return (-1);
	return (1);
}

int	looking_direction_2(t_win *vars, double i)
{
	double	angle;

	angle = vars->player->view_angle + i;
	modify_angle(&angle);
	if (angle >= 90 && angle <= 270)
		return (1);
	return (-1);
}

void	first_horizontal_intersection(t_win *vars, double t, double i)
{
	if (looking_direction(vars, i) == -1)
	{
		vars->r_cast->y_inc = 50;
		vars->r_cast->x_inc = vars->r_cast->y_inc / t;
		vars->r_cast->y_h = floor(vars->player->y_player / 50) * 50 + 50;
	}
	else
	{
		vars->r_cast->y_inc = -50;
		vars->r_cast->x_inc = vars->r_cast->y_inc / t;
		vars->r_cast->y_h = floor(vars->player->y_player / 50) * 50 - 0.0001;
	}
	vars->r_cast->x_h = vars->player->x_player + (vars->r_cast->y_h
			- vars->player->y_player) / t;
}

void	first_vertical_intersection(t_win *vars, double t, double i)
{
	if (looking_direction_2(vars, i) == -1)
	{
		vars->r_cast->x_inc = 50;
		vars->r_cast->y_inc = vars->r_cast->x_inc * t;
		vars->r_cast->x_v = floor(vars->player->x_player / 50) * 50 + 50;
	}
	else
	{
		vars->r_cast->x_inc = -50;
		vars->r_cast->y_inc = vars->r_cast->x_inc * t;
		vars->r_cast->x_v = floor(vars->player->x_player / 50) * 50 - 0.0001;
	}
	vars->r_cast->y_v = vars->player->y_player + (vars->r_cast->x_v
			- vars->player->x_player) * t;
}
