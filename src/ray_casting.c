/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:17:00 by waraissi          #+#    #+#             */
/*   Updated: 2023/08/02 19:38:01 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

int	wall_coll_v(t_win *vars, double angle)
{
	t_ray_cast *cast;

	cast = vars->r_cast;
	if ((angle >= 270 && angle <= 360) || (angle >= 90 && angle < 180))
	{
		if (vars->map[(int)(cast->y_v + 1) / 50][(int)(cast->x_v + 1) / 50] == '1'
			&& vars->map[(int)(cast->y_v - 1) / 50][(int)(cast->x_v - 1) / 50] == '1')
			return (0);
	}
	else if ((angle >= 180 && angle < 270) || (angle >= 0 && angle < 90))
	{
		if (vars->map[(int)(cast->y_v - 1) / 50][(int)(cast->x_v + 1) / 50] == '1'
			&& vars->map[(int)(cast->y_v + 1) / 50][(int)(cast->x_v - 1) / 50] == '1')
			return (0);
	}
	return (1);
}

int	wall_coll_h(t_win *vars, double angle)
{
	t_ray_cast *cast;

	cast = vars->r_cast;
	if ((angle >= 270 && angle <= 360) || (angle >= 90 && angle < 180))
	{
		if (vars->map[(int)(cast->y_h + 1) / 50][(int)(cast->x_h + 1) / 50] == '1'
			&& vars->map[(int)(cast->y_h - 1) / 50][(int)(cast->x_h - 1) / 50] == '1')
			return (0);
	}
	else if ((angle >= 180 && angle < 270) || (angle >= 0 && angle < 90))
	{
		if (vars->map[(int)(cast->y_h - 1) / 50][(int)(cast->x_h + 1) / 50] == '1'
			&& vars->map[(int)(cast->y_h + 1) / 50][(int)(cast->x_h - 1) / 50] == '1')
			return (0);	
	}
	return (1);
}

double	intersection_with_horizontal(t_win *vars, double i)
{
	double t;
	double angle;

	angle = vars->player->view_angle + i;
	modify_angle(&angle);
	t = tan(angle * PI / 180);
	first_horizontal_intersection(vars, t, i);
	while (true)
	{
		if (vars->r_cast->x_h < 0 || vars->r_cast->y_h < 0 || vars->r_cast->x_h / 50 > ft_strlen(vars->map[0]) || vars->r_cast->y_h / 50 > 13)
			break;
		if (vars->map[(int)vars->r_cast->y_h / 50][(int)vars->r_cast->x_h / 50] == '1' || vars->map[(int)vars->r_cast->y_h / 50][(int)vars->r_cast->x_h / 50] == ' ' || !wall_coll_h(vars, angle))
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
	modify_angle(&angle);
	t = tan(angle * PI / 180);
	first_vertical_intersection(vars, t, i);
	while (true)
	{
		if (vars->r_cast->x_v < 0 || vars->r_cast->y_v < 0 || vars->r_cast->x_v / 50 > ft_strlen(vars->map[0]) || vars->r_cast->y_v / 50 > 13)
			break;
		if (vars->map[(int)vars->r_cast->y_v / 50][(int)vars->r_cast->x_v / 50] == '1' || vars->map[(int)vars->r_cast->y_v / 50][(int)vars->r_cast->x_v / 50] == ' ' || !wall_coll_v(vars, angle))
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
	angle = 0.04;
	n = -30;
	while (i < FOV)
	{
		h_i = intersection_with_horizontal(vars, n);
		v_i = intersection_with_vertical(vars, n);
		if (h_i < v_i)
			vars->dis = h_i;
		else
			vars->dis = v_i;
		i += angle;
		n += angle;
	}
}
