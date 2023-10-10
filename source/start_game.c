/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharib <aharib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 09:43:02 by waraissi          #+#    #+#             */
/*   Updated: 2023/10/10 19:48:11 by aharib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	drawing_all(t_win *vars)
{
	// draw_player(vars);
	// draw_map(vars, vars->data);
	game_component(vars);
	start_ray_casting(vars);
	draw_mini_map(vars, vars->m_map); //this three lines should be in bonus part
	draw_square(vars, PLAYER_COLOR);
	draw_line(vars, vars->data);
}

void	mlx_hooks(t_win *vars)
{
	// mlx_hook(vars->mlx_win, 6, 0, start_mov, vars); //this also in bonus part
	mlx_hook(vars->mlx_win, 2, 0, key_hook, vars);
	mlx_hook(vars->mlx_win, 3, 0, key_release, vars);
	mlx_hook(vars->mlx_win, 17, 0, quit_game, vars);
}

void	start_game(t_win *vars, t_data *data)	
{
	data->img = mlx_new_image(vars->mlx, MAP_WIDTH, MAP_HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
										&data->line_length,
										&data->endian);
	mlx_hooks(vars);
	mlx_loop_hook(vars->mlx, hooks, vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, data->img, 0, 0);
}
