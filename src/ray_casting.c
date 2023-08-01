/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:17:00 by waraissi          #+#    #+#             */
/*   Updated: 2023/08/01 20:40:42 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

int	looking_direction(t_win *vars, double i)
{
	double angle;

	angle = vars->player->view_angle + i;
	if (angle >= 360)
		angle = angle - 360;
	else if (angle < 0)
		angle = 360 - fabs(angle);
	if ((angle) >= 0 && (angle) <= 180)
		return (-1);
	return (1);
}

int	looking_direction_2(t_win *vars, double i)
{
	double angle;

	angle = vars->player->view_angle + i;
	if (angle >= 360)
		angle = angle - 360;
		
	if ((angle) >= 90 && (angle) <= 270)
		return (1);
	return (-1);
}

double	intersection_with_horizontal(t_win *vars, double i)
{
	double t;
	double angle;

	angle = vars->player->view_angle + i;
	if (angle >= 360)
		angle = angle - 360;
	else if (angle < 0)
		angle = 360 - fabs(angle);
	t = tan(angle * PI / 180);
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
		vars->r_cast->y_h = floor(vars->player->y_player / 50) * 50 - 1;
	}
	vars->r_cast->x_h = vars->player->x_player + (vars->r_cast->y_h - vars->player->y_player) / t;
	while (true)
	{
		if (vars->r_cast->x_h < 0 || vars->r_cast->y_h < 0 || vars->r_cast->x_h / 50 > ft_strlen(vars->map[0]) || vars->r_cast->y_h / 50 > 13)
			break;
		if (vars->map[(int)vars->r_cast->y_h / 50][(int)vars->r_cast->x_h / 50] == '1' || vars->map[(int)vars->r_cast->y_h / 50][(int)vars->r_cast->x_h / 50] == ' ')
			break;
		vars->r_cast->x_h = vars->r_cast->x_h + vars->r_cast->x_inc;
		vars->r_cast->y_h = vars->r_cast->y_h + vars->r_cast->y_inc;
	}
	return (sqrt(pow(vars->player->x_player - vars->r_cast->x_h, 2) + pow(vars->player->y_player - vars->r_cast->y_h, 2)));
}

double	intersection_with_vertical(t_win *vars, double i)
{
	double t;
	double angle;

	angle = vars->player->view_angle + i;
	if (angle >= 360)
		angle = angle - 360;
	else if (angle < 0)
		angle = 360 - fabs(angle);
	t = tan(angle * PI / 180);
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
		vars->r_cast->x_v = floor(vars->player->x_player / 50) * 50 - 1;
	}
	vars->r_cast->y_v = vars->player->y_player + (vars->r_cast->x_v - vars->player->x_player) * t;
	while (true)
	{
		if (vars->r_cast->x_v < 0 || vars->r_cast->y_v < 0 || vars->r_cast->x_v / 50 > ft_strlen(vars->map[0]) || vars->r_cast->y_v / 50 > 13)
			break;
		if (vars->map[(int)vars->r_cast->y_v / 50][(int)vars->r_cast->x_v / 50] == '1' || vars->map[(int)vars->r_cast->y_v / 50][(int)vars->r_cast->x_v / 50] == ' ')
			break;
		vars->r_cast->x_v = vars->r_cast->x_v + vars->r_cast->x_inc;
		vars->r_cast->y_v = vars->r_cast->y_v + vars->r_cast->y_inc;
	}
	return (sqrt(pow(vars->player->x_player - vars->r_cast->x_v, 2) + pow(vars->player->y_player - vars->r_cast->y_v, 2)));
}

void	start_ray_casting(t_win *vars)
{
	double	h_i;
	double	v_i;
	double	i;
	double	n;
	double	angle;
	
	i = 0;
	angle = 0.05;
	n = -30;
	while (i < FOV)
	{
		h_i = intersection_with_horizontal(vars, n);
		v_i = intersection_with_vertical(vars, n);
		if (h_i < v_i)
		{
			vars->dis = h_i;
			dda_line(vars, vars->r_cast->x_h, vars->r_cast->y_h, 0xFF0000);
		}
		else if (h_i > v_i)
		{
			vars->dis = v_i;
			dda_line(vars, vars->r_cast->x_v, vars->r_cast->y_v, 0xFF0000);
		}
		
		i += angle;
		n += angle;
	}
}
