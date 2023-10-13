/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_mov.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharib <aharib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:52:18 by waraissi          #+#    #+#             */
/*   Updated: 2023/10/13 23:16:24 by aharib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

int	start_mov(int x, int y, t_win *vars)
{
	if (vars->m_map->flag == 0)
	{
		vars->m_map->prev = x;
		vars->m_map->flag++;
		return (0);
	}
	vars->m_map->m_angle = (x - vars->m_map->prev) / 5;
	if (x < 0 || x > vars->map_width || y < 0 || y > vars->map_height)
		vars->m_map->m_angle = 0;
	vars->m_map->r_rl = 1;
	vars->m_map->prev = x;
	return (0);
}
