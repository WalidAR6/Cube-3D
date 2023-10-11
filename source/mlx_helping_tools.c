/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_helping_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharib <aharib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:32:50 by waraissi          #+#    #+#             */
/*   Updated: 2023/10/12 00:10:07 by aharib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

int	player_view_direction(char **map)
{
	int	i;
	int	j;

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

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
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
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W'
				|| map[i][j] == 'E')
			{
				vars->x_player = j * 50 + 25;
				vars->y_player = i * 50 + 25;
				break ;
			}
			j++;
		}
		i++;
	}
}
