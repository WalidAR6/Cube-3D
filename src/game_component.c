/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_component.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharib <aharib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:03:41 by waraissi          #+#    #+#             */
/*   Updated: 2023/10/10 10:08:49 by aharib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

void	paint_wall(t_win *vars, double offx, double start_pos, double end_pos, double slice_lenght, t_w_info *wall, double angle)
{
	int	y;
	double	offy;
	double	distanceFromTop;
	double	scale;

	y = start_pos;
	scale = (double)wall->height / slice_lenght;
	while (y < end_pos)
	{
		distanceFromTop = y + (slice_lenght / 2) - (MAP_HEIGHT / 2);
		offy = distanceFromTop * ((double)wall->height / slice_lenght);
		my_mlx_pixel_put(vars->data, angle, y, wall->pixels[(int)offx][(int)offy]);
		y++;
	}
}

void	draw_walls(t_win *vars, double i, double angle, int h, int v)
{
	double	slice_lenght;
	double	start_pos;
	double	end_pos;
	double 	offx;
	double	tmp_slice_lenght;

	slice_lenght = 50 / vars->dis * vars->dis_p_plan;
	tmp_slice_lenght = slice_lenght;
	if (slice_lenght > MAP_HEIGHT)
		slice_lenght = MAP_HEIGHT;
	start_pos = (MAP_HEIGHT / 2) - (tmp_slice_lenght / 2);
	if (start_pos < 0)
		start_pos = 0;
	end_pos = (MAP_HEIGHT / 2) + (tmp_slice_lenght / 2);
	if (end_pos > MAP_HEIGHT)
		end_pos = MAP_HEIGHT;
	if (angle >= 0 && angle <= 180)
	{
		if(h == 1)
		{
			offx = (int)(vars->r_cast->x_h) * (vars->walls->south->width / 50) % vars->walls->south->width;
			paint_wall(vars, offx, start_pos, end_pos, tmp_slice_lenght, vars->walls->south, i);
		}
	}
	if (angle > 180 && angle <= 360)
	{
		if(h == 1)
		{
			offx = (int)(vars->r_cast->x_h) * (vars->walls->north->width / 50) % vars->walls->north->width;
			paint_wall(vars, offx, start_pos, end_pos, tmp_slice_lenght, vars->walls->north, i);
		}
	}
	if (angle >= 90 && angle <= 270)
	{
		if (v)
		{
			offx = (int)(vars->r_cast->y_v) * (vars->walls->west->width / 50) % vars->walls->west->width;
			paint_wall(vars, offx, start_pos, end_pos, tmp_slice_lenght, vars->walls->west, i);
		}
	}
	if (angle < 90 || angle > 270)
	{
		if (v)
		{
			offx = (int)(vars->r_cast->y_v) * (vars->walls->east->width / 50) % vars->walls->east->width;
			paint_wall(vars, offx, start_pos, end_pos, tmp_slice_lenght, vars->walls->east, i);
		}
	}
	
}

void	draw_celling(t_win *vars)
{
	double	i;
	double	j;

	i = 0;
	while (i < MAP_HEIGHT / 2)
	{
		j = 0;
		while (j < MAP_WIDTH)
		{
			my_mlx_pixel_put(vars->data, j, i, vars->c_color);
			j++;
		}
		i++;
	}
	
}

void	draw_floor(t_win *vars)
{
	double	i;
	double	j;

	i = MAP_HEIGHT / 2;
	while (i < MAP_HEIGHT)
	{
		j = 0;
		while (j < MAP_WIDTH)
		{
			my_mlx_pixel_put(vars->data, j, i, vars->f_color);
			j++;
		}
		i++;
	}
}

void	game_component(t_win *vars)
{
	draw_celling(vars);
	draw_floor(vars);
}
