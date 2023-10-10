/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_component.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharib <aharib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:03:41 by waraissi          #+#    #+#             */
/*   Updated: 2023/10/10 20:32:51 by aharib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

unsigned int	get_pixel(t_data *data, int x, int y)
{
	char	*texture;
	
	texture = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int *)texture);
}

void	paint_wall(t_win *vars, int offx, double start_pos, double end_pos, double slice_lenght, t_w_info *wall, double angle)
{
	int	y;
	int	offy;
	int	distanceFromTop;
	double	scale;

	y = start_pos;
	scale = (double)wall->height / slice_lenght;
	while (y < end_pos)
	{
		distanceFromTop = y + (slice_lenght / 2) - (MAP_HEIGHT / 2);
		offy = distanceFromTop * scale;
		pixel_put(vars->data, angle, y, get_pixel(&wall->img_data, offx, offy));
		y++;
	}
}

void	game_component(t_win *vars)
{
	draw_celling(vars);
	draw_floor(vars);
}
