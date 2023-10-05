// /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 10:52:04 by waraissi          #+#    #+#             */
/*   Updated: 2023/08/01 14:28:42 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"
#include <stdio.h>

void	draw_square(t_win *vars, int color)
{
	double i;
	double j;
	
	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			my_mlx_pixel_put(vars->data, i + vars->m_map->start_x + (((12 * MAP_WIDTH) / 100) / 2),
								j + vars->m_map->start_y + (((23 * MAP_HEIGHT) / 100) / 2), color);
			j++;
		}
		i++;
	}
}

void	draw_line(t_win *vars, t_data *data)
{
	int i;
	double angle;

	angle = vars->player->view_angle;
	angle -= 90;
	modify_angle(&angle);
	i = 0;
	while (i < 22)
	{
		my_mlx_pixel_put(data,
			vars->m_map->start_x + (((12 * MAP_WIDTH) / 100) / 2) + 5 + i * cos(angle * PI / 180),
			vars->m_map->start_y + (((23 * MAP_HEIGHT) / 100) / 2) + 5 + i * sin(angle * PI / 180),
			PLAYER_COLOR);
		i++;
	}
}
