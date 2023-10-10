/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_val.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharib <aharib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:48:21 by waraissi          #+#    #+#             */
/*   Updated: 2023/10/10 10:01:21 by aharib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

void	init_player(char **map,t_player *vars)
{
	get_player_pos(map, vars);
	vars->view_angle = player_view_direction(map);
}

void	init_r_cast(t_win *vars)
{
	vars->r_cast->x_inc = 0;
	vars->r_cast->y_inc = 0;
	vars->r_cast->x_h = 0;
	vars->r_cast->y_h = 0;
	vars->r_cast->x_v = 0;
	vars->r_cast->y_v = 0;
}

void	init_m_map(t_win *vars, t_m_map *m_map)
{
	m_map->start_x = 5;
	m_map->start_y = 5;
	m_map->m_angle = 0;
	m_map->r_rl = 0;
	m_map->prev = 0;
	m_map->flag = 0;
	m_map->data = vars;
}

void	init(t_win *vars)
{
	vars->mlx = mlx_init();
	vars->mlx_win = mlx_new_window(vars->mlx, MAP_WIDTH, MAP_HEIGHT, "Cub3D");
	vars->forw_back = 0;
	vars->left_right = 0;
	vars->r_left_right = 0;
	vars->m_step = 3;
	vars->dis = 0;
	vars->dis_p_plan = (MAP_WIDTH / 2) / tan(30 * PI / 180);
	vars->data = malloc(sizeof(t_data));
	vars->player = malloc(sizeof(t_player));
	vars->r_cast = malloc(sizeof(t_ray_cast));
	vars->m_map = malloc(sizeof(t_m_map));
	if (!vars->player || !vars->data || !vars->r_cast || !vars->m_map || !vars->walls)
		return;
	init_player(vars->map, vars->player);
	init_r_cast(vars);
	init_m_map(vars, vars->m_map);
	init_textures(vars);
	init_colors(vars);
}
