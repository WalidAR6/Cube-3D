/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:28:14 by waraissi          #+#    #+#             */
/*   Updated: 2023/08/02 19:19:16 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

int		key_hook(int keycode, t_win *vars)
{
	if (keycode == KEY_DOWN || keycode == ARROW_DOWN)
		vars->forw_back = -1;
	if (keycode == KEY_UP || keycode == ARROW_UP)	
		vars->forw_back = 1;
	if (keycode == KEY_RIGHT)
		vars->left_right = 1;
	if (keycode == KEY_LEFT)
		vars->left_right = -1;
	if (keycode == ARROW_LEFT)
		vars->r_left_right = -1;
	if (keycode == ARROW_RIGHT)
		vars->r_left_right = 1;
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		exit(0);
	}
	return (0);
}

int		key_release(int keycode, t_win *vars)
{
	if (keycode == KEY_DOWN || keycode == ARROW_DOWN)
		vars->forw_back = 0;
	if (keycode == KEY_UP || keycode == ARROW_UP)	
		vars->forw_back = 0;
	if (keycode == KEY_RIGHT)
		vars->left_right = 0;
	if (keycode == KEY_LEFT)
		vars->left_right = 0;
	if (keycode == ARROW_LEFT)
		vars->r_left_right = 0;
	if (keycode == ARROW_RIGHT)
		vars->r_left_right = 0;
	return (0);
}

int		quit_game(int keycode, t_win *vars)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(vars->mlx, vars->data->img);
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		exit(0);
	}
	return (0);
}

void	move_player(t_win *vars)
{
	if (vars->forw_back == -1)
		move_down(vars);
	if (vars->forw_back == 1)
		move_up(vars);
	if (vars->left_right == -1)
		move_left(vars);
	if (vars->left_right == 1)
		move_right(vars);
	if (vars->r_left_right == -1)
		rotate(vars, -1);
	if (vars->r_left_right == 1)
		rotate(vars, 1);
}

int		hooks(t_win *vars)
{
	mlx_destroy_image(vars->mlx, vars->data->img);
	vars->data->img = mlx_new_image(vars->mlx, MAP_WIDTH, MAP_HEIGHT);
	vars->data->addr = mlx_get_data_addr(vars->data->img,
											&vars->data->bits_per_pixel,
											&vars->data->line_length,
											&vars->data->endian);
	drawing_all(vars);
	move_player(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->data->img, 0, 0);
	return (0);
}
