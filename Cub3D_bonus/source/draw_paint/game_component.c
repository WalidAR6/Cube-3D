/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_component.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharib <aharib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:03:41 by waraissi          #+#    #+#             */
/*   Updated: 2023/10/13 23:28:29 by aharib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

void	game_component(t_win *vars)
{
	paint_celling(vars);
	paint_floor(vars);
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
			pixel_put(vars->data, i + vars->m_map->start_x + (((12
							* vars->map_width) / 100) / 2) - 3, j
				+ vars->m_map->start_y + (((12 * vars->map_width) / 100)
					/ 2) - 3, color);
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
			vars->m_map->start_x + (((12 * vars->map_width) / 100) / 2)
			+ i * cos(angle * PI / 180),
			vars->m_map->start_y + (((12 * vars->map_width) / 100) / 2)
			+ i * sin(angle * PI / 180),
			0x0);
		i++;
	}
}
