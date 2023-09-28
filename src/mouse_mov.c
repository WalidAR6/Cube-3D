/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_mov.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:52:18 by waraissi          #+#    #+#             */
/*   Updated: 2023/09/28 12:11:08 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

int start_mov(int x, int y, t_win *vars)
{
    if (vars->m_map->flag == 0)
    {
        vars->m_map->prev = x;
        vars->m_map->flag++;
        return (0);
    }
    vars->m_map->m_angle = (x - vars->m_map->prev) / 20;
    if (x < 0 || x > MAP_WIDTH || y < 0 || y > MAP_HEIGHT)
        vars->m_map->m_angle  = 0;
    vars->m_map->r_rl = 1;
    vars->m_map->prev = x;
    return (0);
}
