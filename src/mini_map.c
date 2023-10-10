/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharib <aharib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 23:01:06 by waraissi          #+#    #+#             */
/*   Updated: 2023/10/10 17:05:34 by aharib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

int     check_map_width(t_win *vars, double x, double y)
{
    int grid;

    grid = y / 50;
    if ( x / 50 > (int)ft_strlen(vars->map[grid]))
        return 0;
    return 1;
}

void    draw_mini_map(t_win *vars, t_m_map *m_map)
{
    int i;
    int j;
    double x;
    double y;
    
    y = vars->player->y_player - (((12 * MAP_WIDTH) / 100));
    i = m_map->start_x;
    while (i < (12 * MAP_WIDTH) / 100)
    {
        j = m_map->start_y;
        x = vars->player->x_player + (((12 * MAP_WIDTH) / 100));
        while (j < (12 * MAP_WIDTH) / 100)
        {
            if (x < 0 || y < 0 || (int)y / 50 > get_map_height(vars) || !check_map_width(vars, x, y))
                my_mlx_pixel_put(vars->data, i, j, 0x323232);
            else if (vars->map[(int)y / 50][(int)x / 50] == '1' || vars->map[(int)y / 50][(int)x / 50] == ' ')            
                my_mlx_pixel_put(vars->data, i, j, 4335);
            else
                my_mlx_pixel_put(vars->data, i, j, GROUND_COLOR);
            j++;
            x -= 2;
        }
        y += 2;
        i++;
    }
}