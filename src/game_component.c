/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_component.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharib <aharib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:03:41 by waraissi          #+#    #+#             */
/*   Updated: 2023/10/09 16:29:44 by aharib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

void	draw_walls(t_win *vars, double i, double angle, int h, int v)
{
	double	slice_lenght;
	double	start_pos;

	slice_lenght = 50 / vars->dis * vars->dis_p_plan;
	if (slice_lenght > MAP_HEIGHT)
		slice_lenght = MAP_HEIGHT;
	start_pos = (MAP_HEIGHT / 2) - (slice_lenght / 2);
	if (angle >= 0 && angle <= 180)
	{
		if(h == 1)
			dda_wall(vars, i, start_pos, start_pos + slice_lenght, 0x0066B2);
	}
	if (angle > 180 && angle <= 360)
	{
		if(h == 1)
			dda_wall(vars, i, start_pos, start_pos + slice_lenght, 0xDC052D);
	}
	if (angle >= 90 && angle <= 270)
	{
		if (v)
			dda_wall(vars, i, start_pos, start_pos + slice_lenght, 0xFFFFFF);
	}
	if (angle < 90 || angle > 270)
	{
		if (v)
			dda_wall(vars, i, start_pos, start_pos + slice_lenght, 0x000000);
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
