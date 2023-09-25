/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:17:00 by waraissi          #+#    #+#             */
/*   Updated: 2023/09/25 01:26:47 by waraissi         ###   ########.fr       */
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

double	intersection_with_horizontal(t_win *vars, double i, double angle)
{
	double t;

	t = tan(angle * PI / 180);
	first_horizontal_intersection(vars, t, i);
	while (true)
	{
		if (vars->r_cast->x_h < 0 || vars->r_cast->y_h < 0 || vars->r_cast->x_h / 50 > (int)ft_strlen(vars->map[0]) || vars->r_cast->y_h / 50 > 13)
			break;
		if (vars->map[(int)vars->r_cast->y_h / 50][(int)vars->r_cast->x_h / 50] == '1' || vars->map[(int)vars->r_cast->y_h / 50][(int)vars->r_cast->x_h / 50] == ' ' || !wall_coll_h(vars, angle))
			break;
		vars->r_cast->x_h = vars->r_cast->x_h + vars->r_cast->x_inc;
		vars->r_cast->y_h = vars->r_cast->y_h + vars->r_cast->y_inc;
	}
	return (sqrt(pow(vars->player->x_player - vars->r_cast->x_h, 2) + pow(vars->player->y_player - vars->r_cast->y_h, 2)));
}

double	intersection_with_vertical(t_win *vars, double i, double angle)
{
	double t;

	t = tan(angle * PI / 180);
	first_vertical_intersection(vars, t, i);
	while (true)
	{
		if (vars->r_cast->x_v < 0 || vars->r_cast->y_v < 0 || vars->r_cast->x_v / 50 > (int)ft_strlen(vars->map[0]) || vars->r_cast->y_v / 50 > 13)
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
	double	win_pix;
	double	h_i;
	double	v_i;
	double	i;
	double	n;
	double	angle;
	double	r_angle;
	
	i = 0;
	angle = (double)FOV / 2000;
	n = -30;
	win_pix = angle;
	while (i < FOV)
	{
		r_angle = vars->player->view_angle + n;
		modify_angle(&r_angle);
		h_i = intersection_with_horizontal(vars, n, r_angle);
		v_i = intersection_with_vertical(vars, n, r_angle);
		if (h_i < v_i)
		{
			vars->dis = cos((vars->player->view_angle - r_angle) * PI / 180) * h_i;
			// dda_line(vars, vars->r_cast->x_h, vars->r_cast->y_h, 0xFF0000);
		}
		else
		{
			vars->dis = cos((vars->player->view_angle - r_angle) * PI / 180) * v_i;
			// dda_line(vars, vars->r_cast->x_v, vars->r_cast->y_v, 0xFF0000);
		}
		draw_walls(vars, win_pix);
		i += angle;
		n += angle;
		win_pix += 1;
	}
}
