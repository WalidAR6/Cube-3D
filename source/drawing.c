/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharib <aharib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 10:52:04 by waraissi          #+#    #+#             */
/*   Updated: 2023/10/10 20:38:04 by aharib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	draw_walls(t_win *vars, double i, double angle, int h)
{
	double	slice_lenght;
	double	start_pos;
	double	end_pos;
	int 	offx;
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

	if (h == 0)
	{
		if ((angle >= 90 && angle <= 270))
		{
			offx = (int)(vars->r_cast->y_v) * (vars->walls->west->width / 50) % vars->walls->west->width;
			paint_wall(vars, offx, start_pos, end_pos, tmp_slice_lenght, vars->walls->west, i);
		}
		if (angle < 90 || angle > 270)
		{
			offx = (int)(vars->r_cast->y_v) * (vars->walls->east->width / 50) % vars->walls->east->width;
			paint_wall(vars, offx, start_pos, end_pos, tmp_slice_lenght, vars->walls->east, i);
		}
	}
	else
	{
		if (angle >= 0 && angle <= 180)
		{
				offx = (int)(vars->r_cast->x_h) * (vars->walls->south->width / 50) % vars->walls->south->width;
				paint_wall(vars, offx, start_pos, end_pos, tmp_slice_lenght, vars->walls->south, i);
		}
		if (angle > 180 && angle <= 360)
		{
				offx = (int)(vars->r_cast->x_h) * (vars->walls->north->width / 50) % vars->walls->north->width;
				paint_wall(vars, offx, start_pos, end_pos, tmp_slice_lenght, vars->walls->north, i);
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
			pixel_put(vars->data, j, i, vars->c_color);
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
			pixel_put(vars->data, j, i, vars->f_color);
			j++;
		}
		i++;
	}
}

void	draw_square(t_win *vars, int color)
{
	double	i;
	double	j;

	i = 0;
	while (i < 7)
	{
		j = 0;
		while (j < 7)
		{
			pixel_put(vars->data, i + vars->m_map->start_x + (((12 * MAP_WIDTH)
							/ 100) / 2) - 3, j + vars->m_map->start_y + (((12
								* MAP_WIDTH) / 100) / 2) - 3, color);
			j++;
		}
		i++;
	}
}

void	draw_line(t_win *vars, t_data *data)
{
	int		i;
	double	angle;

	angle = vars->player->view_angle;
	angle -= 90;
	modify_angle(&angle);
	i = 0;
	while (i < 15)
	{
		pixel_put(data,
			vars->m_map->start_x + (((12 * MAP_WIDTH) / 100) / 2) + i
			* cos(angle * PI / 180),
			vars->m_map->start_y + (((12 * MAP_WIDTH) / 100) / 2) + i
			* sin(angle * PI / 180),
			PLAYER_COLOR);
		i++;
	}
}
