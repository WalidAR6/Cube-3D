/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_val.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharib <aharib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:48:21 by waraissi          #+#    #+#             */
/*   Updated: 2023/10/13 03:11:07 by aharib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

void	init_player(char **map, t_player *vars)
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

void	init(t_win *vars)
{
	vars->mlx = mlx_init();
	vars->mlx_win = mlx_new_window(vars->mlx, MAP_WIDTH, MAP_HEIGHT, "Cub3D");
	vars->forw_back = 0;
	vars->left_right = 0;
	vars->r_left_right = 0;
	vars->m_step = 3;
	vars->dis = 0;
	vars->slice_lenght = 0;
	vars->angle = 0;
	vars->n_angle = 0;
	vars->r_angle = 0;
	vars->dis_p_plan = (MAP_WIDTH / 2) / tan(30 * PI / 180);
	vars->data = malloc(sizeof(t_data));
	vars->player = malloc(sizeof(t_player));
	vars->r_cast = malloc(sizeof(t_ray_cast));
	if (!vars->mlx_win || !vars->player || !vars->data || !vars->r_cast || !vars->walls)
		error_msg();
	init_player(vars->map, vars->player);
	init_r_cast(vars);
	init_textures(vars);
}
