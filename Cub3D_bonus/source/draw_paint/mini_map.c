/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharib <aharib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 23:01:06 by waraissi          #+#    #+#             */
/*   Updated: 2023/10/13 16:31:46 by aharib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

void	complete_drawing(t_win *vars, double y, int i, t_m_map *m_map)
{
	int		j;
	double	x;

	j = m_map->start_y;
	x = vars->player->x_player + (((12 * MAP_WIDTH) / 100));
	while (j < (12 * MAP_WIDTH) / 100)
	{
		if (x < 0 || y < 0 || (int)y / 50 > get_map_height(vars)
			|| !check_map_width(vars, x, y))
			pixel_put(vars->data, i, j, 0x323232);
		else if (vars->map[(int)y / 50][(int)x / 50] == '1'
				|| vars->map[(int)y / 50][(int)x / 50] == ' ')
			pixel_put(vars->data, i, j, 0x4e341d);
		else
			pixel_put(vars->data, i, j, GROUND_COLOR);
		j++;
		x -= 2;
	}
}

void	draw_mini_map(t_win *vars, t_m_map *m_map)
{
	int		i;
	double	y;

	y = vars->player->y_player - (((12 * MAP_WIDTH) / 100));
	i = m_map->start_x;
	while (i < (12 * MAP_WIDTH) / 100)
	{
		complete_drawing(vars, y, i, m_map);
		y += 2;
		i++;
	}
}
