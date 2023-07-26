/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:17:00 by waraissi          #+#    #+#             */
/*   Updated: 2023/07/26 15:45:35 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

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

double	intersection_with_horizontal(t_win *vars)
{
	double t;

	t = tan(vars->player->view_angle * PI / 180);
	if (looking_direction(vars) == -1)
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
		if (vars->map[(int)vars->r_cast->y_h / 50][(int)vars->r_cast->x_h / 50] == '1')
			break;
		vars->r_cast->x_h = vars->r_cast->x_h + vars->r_cast->x_inc;
		vars->r_cast->y_h = vars->r_cast->y_h + vars->r_cast->y_inc;
	}
	return (sqrt(pow(vars->player->x_player - vars->r_cast->x_h, 2) + pow(vars->player->y_player - vars->r_cast->y_h, 2)));
}

double	intersection_with_vertical(t_win *vars)
{
	double t;

	t = tan(vars->player->view_angle * PI / 180);
	if (looking_direction_2(vars) == -1)
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
	vars->r_cast->y_v = vars->player->y_player + (vars->r_cast->x_v - vars->player->x_player) * tan(vars->player->view_angle * PI / 180);
	while (true)
	{
		if (vars->r_cast->x_v < 0 || vars->r_cast->y_v < 0 || vars->r_cast->x_v / 50 > ft_strlen(vars->map[0]) || vars->r_cast->y_v / 50 > 13)
			break;
		if (vars->map[(int)vars->r_cast->y_v / 50][(int)vars->r_cast->x_v / 50] == '1')
			break;
		vars->r_cast->x_v = vars->r_cast->x_v + vars->r_cast->x_inc;
		vars->r_cast->y_v = vars->r_cast->y_v + vars->r_cast->y_inc;
	}
	return (sqrt(pow(vars->player->x_player - vars->r_cast->x_v, 2) + pow(vars->player->y_player - vars->r_cast->y_v, 2)));
}

void	start_ray_casting(t_win *vars, t_data *data)
{
	(void)data;
	double	h_i;
	double	v_i;

	h_i = intersection_with_horizontal(vars);
	v_i = intersection_with_vertical(vars);
	if (h_i < v_i)
		dda_line(data, vars, vars->r_cast->x_h, vars->r_cast->y_h);
	else
		dda_line(data, vars, vars->r_cast->x_v, vars->r_cast->y_v);
		
	printf("h_i = %f ,v_i = %f\n", h_i, v_i);
}
