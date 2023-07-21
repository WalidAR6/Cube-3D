/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 10:52:04 by waraissi          #+#    #+#             */
/*   Updated: 2023/07/21 11:46:46 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

void	draw_square(t_data *data, int x, int y, int color)
{
	int i;
	int j;
	
	i = 0;
	while (i < 50)
	{
		j = 0;
		while (j < 50)
		{
			my_mlx_pixel_put(data, i + y, j + x, color);
			j++;
		}
		i++;
	}
}

void	draw_cercle(t_data *data, int y, int x, int color)
{
	double	x1;
	double	y1;
	double	angl;
	int		l;

	angl = 0;
	while (angl < 360)
	{
		x1 = REDIUS * cos(angl * PI / 180);
		y1 = REDIUS * sin(angl * PI / 180);
		l = 0;
		while (l < 4)
		{
			my_mlx_pixel_put(data, (l * x1 / REDIUS) + x,
						(l * y1 / REDIUS) + y, color);
			l++;
		}
		angl += 1;
	}
}

void	draw_map(t_win *vars, t_data *data)
{
	int i;
	int j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == '1')
				draw_square(data, i * 50, j * 50, WALL_COLOR);
			else
				draw_square(data, i * 50, j * 50, GROUND_COLOR);
			j++;
		}
		i++;
	}
}


void	draw_player(t_win *vars, t_data *data)
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
				draw_cercle(data, vars->player->y_player,
						vars->player->x_player, PLAYER_COLOR);
			j++;
		}
		i++;
	}
}

void	draw_line(t_win *vars, t_data *data)
{
	int i;

	i = 0;
	while (i < 15)
	{
		my_mlx_pixel_put(data,
			vars->player->x_player + i * sin(vars->player->view_angle * PI / 180),
			vars->player->y_player + i * cos(vars->player->view_angle * PI / 180),
			PLAYER_COLOR);
		i++;
	}
}
