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

void	draw_square(t_data *data, double x, double y, int color)
{
	double i;
	double j;
	
	i = 0;
	while (i < 50 - 1)
	{
		j = 0;
		while (j < 50 - 1)
		{
			my_mlx_pixel_put(data, i + y, j + x, color);
			j++;
		}
		i++;
	}
}

void	draw_cercle(t_win *vars, int color)
{
	double	x1;
	double	y1;
	double	angl;

	angl = 0;
	while (angl < 360)
	{
		x1 = REDIUS * cos(angl * PI / 180);
		y1 = REDIUS * sin(angl * PI / 180);
		dda_line(vars, x1 + vars->player->x_player, y1 + vars->player->y_player, color);
		angl += 0.1;
	}
}

void	draw_map(t_win *vars, t_data *data)
{
	double i;
	double j;

	i = 0;
	while (vars->map[(int)i])
	{
		j = 0;
		while (vars->map[(int)i][(int)j])
		{
			if (vars->map[(int)i][(int)j] == '1' || vars->map[(int)i][(int)j] == ' ')
				draw_square(data, i * 50, j * 50, WALL_COLOR);
			else
				draw_square(data, i * 50, j * 50, GROUND_COLOR);
			j++;
		}
		i++;
	}
}


void	draw_player(t_win *vars)
{
	int i;
	int j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'N')
				draw_cercle(vars, PLAYER_COLOR);
			j++;
		}
		i++;
	}
}

void	draw_line(t_win *vars, t_data *data)
{
	int i;

	i = 0;
	while (i < 22)
	{
		my_mlx_pixel_put(data,
			vars->player->x_player + i * cos(vars->player->view_angle * PI / 180),
			vars->player->y_player + i * sin(vars->player->view_angle * PI / 180),
			PLAYER_COLOR);
		i++;
	}
}
