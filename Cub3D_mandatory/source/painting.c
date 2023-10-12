/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharib <aharib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 02:23:10 by aharib            #+#    #+#             */
/*   Updated: 2023/10/12 16:51:25 by aharib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	paint_wall(t_win *vars, t_w_info *wall, int offx, double angle)
{
	int		y;
	int		offy;
	int		distance_from_top;
	double	start_pos;
	double	end_pos;

	start_pos = (MAP_HEIGHT / 2) - (vars->slice_lenght / 2);
	if (start_pos < 0)
		start_pos = 0;
	end_pos = (MAP_HEIGHT / 2) + (vars->slice_lenght / 2);
	if (end_pos > MAP_HEIGHT)
		end_pos = MAP_HEIGHT;
	y = start_pos;
	while (y < end_pos)
	{
		distance_from_top = y + (vars->slice_lenght / 2) - (MAP_HEIGHT / 2);
		offy = distance_from_top * (double)wall->height / vars->slice_lenght;
		pixel_put(vars->data, angle, y, get_pixel(&wall->img_data, offx, offy));
		y++;
	}
}

void	paint_celling(t_win *vars)
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

void	paint_floor(t_win *vars)
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
