/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_mov.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:52:18 by waraissi          #+#    #+#             */
/*   Updated: 2023/09/25 21:59:37 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

int start_mov(int x, int y, t_win *vars)
{
    (void)y;
    if (vars->m_map->flag == 0)
    {
        vars->m_map->prev = x;
        vars->m_map->flag++;
    }
    else
    {
        vars->m_map->m_angle = (x - vars->m_map->prev) / 20;
        if (x < 0)
            vars->m_map->m_angle -= 1;
        if (x > MAP_WIDTH)
            vars->m_map->m_angle += 1;
        vars->m_map->r_l = 1;
        vars->m_map->r_r = 1;
        vars->m_map->prev = x;
    }
    return (0);
}
