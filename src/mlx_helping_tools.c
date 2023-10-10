/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_helping_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharib <aharib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:32:50 by waraissi          #+#    #+#             */
/*   Updated: 2023/10/10 08:05:02 by aharib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

int		player_view_direction(char **map)
{
	int i;
	int j;
	
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N')
				return (270);			
			else if (map[i][j] == 'E')
				return (0);			
			else if (map[i][j] == 'W')
				return (180);			
			else if (map[i][j] == 'S')
				return (90);		
			j++;
		}
		i++;
	}
	return (0);
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
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W' || map[i][j] == 'E')
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

// void	paint_wall(t_win *vars, double offx, double offy, double start_pos, double slice_lenght, t_w_info *wall, double x)
// {	
// 	double	i;
// 	double	step;
// 	double	dx;
// 	double	dy;
// 	double	px;
// 	double	py;
// 	double	x_inc;
// 	double	y_inc;
// 	int		y;

// 	y = start_pos;
// 	i = 0;
// 	px = x;
// 	py = start_pos;
// 	dx = 0;
// 	dy = slice_lenght;
// 	if (fabs(dx) > fabs(dy))
// 		step = fabs(dx);
// 	else
// 		step = fabs(dy);
// 	x_inc = dx/step;
// 	y_inc = dy/step;
// 	double scale = 50 / slice_lenght;
// 	printf("offx = %f, offy = %f\n", offx, offy);
// 	while (i < step)
// 	{
// 		my_mlx_pixel_put(vars->data, px, py, wall->pixels[(int)offx][(int)offy]);
// 		px += x_inc;
// 		py += y_inc;
// 		i++;
// 		offy += scale;
// 	}
// }