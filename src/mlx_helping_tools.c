/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_helping_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:32:50 by waraissi          #+#    #+#             */
/*   Updated: 2023/08/04 21:58:48 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

void	print_map(t_win *vars)
{
	int i = 0;
	while (vars->map[i])
	{
		printf("%s\n",vars->map[i]);
		i++;
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	get_player_pos(char **map, t_player *vars)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 1;
		while (map[i][j])
		{
			if (map[i][j] == 'N')
			{
				vars->x_player = j * 50 + 25;
				vars->y_player = i * 50 + 25;
				break;
			}
			j++;
		}
		i++;
	}
}

void	dda_line(t_win *vars, double x, double y, int color)
{
	int		i;
	double		step;

	i = 0;
	vars->dda_params->px = vars->player->x_player;
	vars->dda_params->py = vars->player->y_player;
	vars->dda_params->dx = x - vars->player->x_player;
	vars->dda_params->dy = y - vars->player->y_player;
	if (fabs(vars->dda_params->dx) > fabs(vars->dda_params->dy))
		step = fabs(vars->dda_params->dx);
	else
		step = fabs(vars->dda_params->dy);
	vars->dda_params->x_inc = vars->dda_params->dx/step;
	vars->dda_params->y_inc = vars->dda_params->dy/step;
	while (i < step)
	{
		my_mlx_pixel_put(vars->data, vars->dda_params->px, vars->dda_params->py, color);
		vars->dda_params->px += vars->dda_params->x_inc;
		vars->dda_params->py += vars->dda_params->y_inc;
		i++;
	}
}

void	dda_wall(t_win *vars, double xs, double ys, double xe, double ye, int color)
{
	int		i;
	double	step;
	double	dx;
	double	dy;
	double	px;
	double	py;
	double	x_inc;
	double	y_inc;

	i = 0;
	px = xs;
	py = ys;
	dx = xe - xs;
	dy = ye - ys;
	if (fabs(dx) > fabs(dy))
		step = fabs(dx);
	else
		step = fabs(dy);
	x_inc = dx/step;
	y_inc = dy/step;
	while (i < step)
	{
		my_mlx_pixel_put(vars->data, px, py, color);
		px += x_inc;
		py += y_inc;
		i++;
	}
}
