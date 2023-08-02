/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_component.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:03:41 by waraissi          #+#    #+#             */
/*   Updated: 2023/08/02 19:21:59 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

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
			my_mlx_pixel_put(vars->data, j, i, 0xB3E7F4);
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
			my_mlx_pixel_put(vars->data, j, i, 0xa9a9a9);
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
