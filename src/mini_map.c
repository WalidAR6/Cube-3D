/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 23:01:06 by waraissi          #+#    #+#             */
/*   Updated: 2023/10/04 10:43:34 by waraissi         ###   ########.fr       */
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
    
    y = vars->player->y_player - 120;
    i = m_map->start_x;
    while (i < MAP_WIDTH - 10)
    {
        j = m_map->start_y;
        x = vars->player->x_player + 120;
        while (j < MAP_HEIGHT - 10)
        {
            if (x < 0 || y < 0 || (int)y / 50 > get_map_height(vars) || !check_map_width(vars, x, y))
                my_mlx_pixel_put(vars->data, i, j, 0xFF0000);
            else if (vars->map[(int)y / 50][(int)x / 50] == '1' || vars->map[(int)y / 50][(int)x / 50] == ' ')            
                my_mlx_pixel_put(vars->data, i, j, PLAYER_COLOR);
            else
                my_mlx_pixel_put(vars->data, i, j, GROUND_COLOR);
            j++;
            x--;
        }
        y++;
        i++;
    }
}