/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 09:43:02 by waraissi          #+#    #+#             */
/*   Updated: 2023/07/21 11:38:14 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

void	raycast(t_win *vars, t_data *data)
{
	data->img = mlx_new_image(vars->mlx, ft_strlen(vars->map[0]) * 50, 11 * 50);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
										&data->line_length,
										&data->endian);
	draw_map(vars, vars->data);
	draw_player(vars, vars->data);
	draw_line(vars, vars->data);
	mlx_hook(vars->mlx_win, 2, 0, key_hook, vars);
	mlx_hook(vars->mlx_win, 3, 0, key_release, vars);
	mlx_hook(vars->mlx_win, 17, 0, quit_game, vars);
	mlx_loop_hook(vars->mlx, hooks, vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, data->img, 0, 0);
}
