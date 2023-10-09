/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharib <aharib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:17:00 by waraissi          #+#    #+#             */
/*   Updated: 2023/10/09 16:26:54 by aharib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

int get_map_height(t_win *vars)
{
	char **tmp;
	int count;
	
	count = 0;
	tmp = vars->map;
	while (*tmp)
	{
		count++;
		tmp++;
	}
	return (count - 1);
}

int	wall_coll_v(t_win *vars, double angle)
{
	t_ray_cast *cast;
	double yv;
	double xv;
	
	cast = vars->r_cast;
	yv = cast->y_v;
	xv = cast->x_v;
	if ((angle >= 270 && angle <= 360) || (angle >= 90 && angle < 180))
	{
		if (vars->map[(int)(yv + 1) / 50][(int)(xv + 1) / 50] == '1'
			&& vars->map[(int)(yv - 1) / 50][(int)(xv - 1) / 50] == '1')
			return (0);
	}
	else if ((angle >= 180 && angle < 270) || (angle >= 0 && angle < 90))
	{
		if (vars->map[(int)(yv - 1) / 50][(int)(xv + 1) / 50] == '1'
			&& vars->map[(int)(yv + 1) / 50][(int)(xv - 1) / 50] == '1')
			return (0);
	}
	return (1);
}

int	wall_coll_h(t_win *vars, double angle)
{
	t_ray_cast	*cast;
	double		yh;
	double		xh;
	
	cast = vars->r_cast;
	yh = cast->y_h;
	xh = cast->x_h;
	if ((angle >= 270 && angle <= 360) || (angle >= 90 && angle < 180))
	{
		if (vars->map[(int)(yh + 1) / 50][(int)(xh + 1) / 50] == '1'
			&& vars->map[(int)(yh - 1) / 50][(int)(xh - 1) / 50] == '1')
			return (0);
	}
	else if ((angle >= 180 && angle < 270) || (angle >= 0 && angle < 90))
	{
		if (vars->map[(int)(yh - 1) / 50][(int)(xh + 1) / 50] == '1'
			&& vars->map[(int)(yh + 1) / 50][(int)(xh - 1) / 50] == '1')
			return (0);	
	}
	return (1);
}

double	intersection_with_horizontal(t_win *vars, double i, double angle)
{
	double t;
	double		yh;
	double		xh;
	
	t = tan(angle * PI / 180);
	first_horizontal_intersection(vars, t, i);
	yh = vars->r_cast->y_h;
	xh = vars->r_cast->x_h;
	while (true)
	{
		if (vars->r_cast->x_h < 0 || vars->r_cast->y_h < 0
			|| vars->r_cast->y_h / 50 > get_map_height(vars)
			|| !check_map_width(vars, vars->r_cast->x_h, vars->r_cast->y_h))
			break;
		if (vars->map[(int)yh / 50][(int)xh / 50] == '1'
			|| vars->map[(int)yh / 50][(int)xh / 50] == ' '
			|| !wall_coll_h(vars, angle))
			break;
		vars->r_cast->x_h = vars->r_cast->x_h + vars->r_cast->x_inc;
		vars->r_cast->y_h = vars->r_cast->y_h + vars->r_cast->y_inc;
		yh = vars->r_cast->y_h;
		xh = vars->r_cast->x_h;
	}
	return (sqrt(pow(vars->player->x_player - vars->r_cast->x_h, 2)
			+ pow(vars->player->y_player - vars->r_cast->y_h, 2)));
}

double	intersection_with_vertical(t_win *vars, double i, double angle)
{
	double t;
	double yv;
	double xv;
	
	t = tan(angle * PI / 180);
	first_vertical_intersection(vars, t, i);
	yv = vars->r_cast->y_v;
	xv = vars->r_cast->x_v;
	while (true)
	{
		if (vars->r_cast->x_v < 0 || vars->r_cast->y_v < 0
			|| vars->r_cast->y_v / 50 > get_map_height(vars)
			|| !check_map_width(vars, vars->r_cast->x_v, vars->r_cast->y_v))
			break;
		if (vars->map[(int)yv / 50][(int)xv / 50] == '1'
			|| vars->map[(int)yv / 50][(int)xv / 50] == ' '
			|| !wall_coll_v(vars, angle))
			break;
		vars->r_cast->x_v = vars->r_cast->x_v + vars->r_cast->x_inc;
		vars->r_cast->y_v = vars->r_cast->y_v + vars->r_cast->y_inc;
		yv = vars->r_cast->y_v;
		xv = vars->r_cast->x_v;
	}
	return (sqrt(pow(vars->player->x_player - vars->r_cast->x_v, 2)
			+ pow(vars->player->y_player - vars->r_cast->y_v, 2)));
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
	int h = 0;
	int v = 0;
		
	i = 0;
	angle = (double)FOV / MAP_WIDTH;
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
			h = 1;
			v = 0;
		}
		else
		{
			vars->dis = cos((vars->player->view_angle - r_angle) * PI / 180) * v_i;
			h = 0;
			v = 1;
		}
		draw_walls(vars, win_pix, r_angle, h, v);
		i += angle;
		n += angle;
		win_pix += 1;
	}
}
