/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 23:01:06 by waraissi          #+#    #+#             */
/*   Updated: 2023/09/28 16:36:48 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

void    draw_mini_map(t_win *vars, t_m_map *m_map)
{
    int i;
    int j;
    int x;
    int y;
    
    y = vars->player->y_player - 120;
    i = m_map->start_x;
    while (i < MAP_WIDTH - 10)
    {
        j = m_map->start_y;
        x = vars->player->x_player + 120;
        while (j < MAP_HEIGHT - 10)
        {
            if (x < 0 || y < 0 || x / 50 > (int)ft_strlen(vars->map[0]) || y / 50 > 13)
                my_mlx_pixel_put(vars->data, i, j, GROUND_COLOR);
            else if (vars->map[y / 50][x / 50] == '1' || vars->map[y / 50][x / 50] == ' ')            
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