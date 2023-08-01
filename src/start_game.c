/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 09:43:02 by waraissi          #+#    #+#             */
/*   Updated: 2023/08/01 14:43:30 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

void	drawing_all(t_win *vars)
{
	draw_map(vars, vars->data);
	// draw_line(vars, vars->data);
	start_ray_casting(vars);
	draw_player(vars);
}

void	mlx_hooks(t_win *vars)
{
	mlx_hook(vars->mlx_win, 2, 0, key_hook, vars);
	mlx_hook(vars->mlx_win, 3, 0, key_release, vars);
	mlx_hook(vars->mlx_win, 17, 0, quit_game, vars);
}

void	start_game(t_win *vars, t_data *data)	
{
	data->img = mlx_new_image(vars->mlx, ft_strlen(vars->map[0]) * 50, 14 * 50);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
										&data->line_length,
										&data->endian);
	mlx_hooks(vars);
	mlx_loop_hook(vars->mlx, hooks, vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, data->img, 0, 0);
}
