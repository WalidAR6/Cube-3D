/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_val.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:48:21 by waraissi          #+#    #+#             */
/*   Updated: 2023/10/12 22:59:44 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	init_params(t_win *vars)
{
	vars->f_color = -1;
	vars->c_color = -1;
	vars->walls = malloc(sizeof(t_walls));
	vars->walls->east = malloc(sizeof(t_w_info));
	vars->walls->west = malloc(sizeof(t_w_info));
	vars->walls->north = malloc(sizeof(t_w_info));
	vars->walls->south = malloc(sizeof(t_w_info));
	if (!vars->walls || !vars->walls->east || !vars->walls->west
		|| !vars->walls->north || !vars->walls->south)
		exit(0);
}

void	init_textures2(t_win *vars)
{
	vars->walls->east->img_data.addr = 
		mlx_get_data_addr(vars->walls->east->img_data.img,
			&vars->walls->east->img_data.bits_per_pixel,
			&vars->walls->east->img_data.line_length,
			&vars->walls->east->img_data.endian);
	vars->walls->west->img_data.addr = 
		mlx_get_data_addr(vars->walls->west->img_data.img,
			&vars->walls->west->img_data.bits_per_pixel,
			&vars->walls->west->img_data.line_length,
			&vars->walls->west->img_data.endian);
	vars->walls->north->img_data.addr = 
		mlx_get_data_addr(vars->walls->north->img_data.img,
			&vars->walls->north->img_data.bits_per_pixel,
			&vars->walls->north->img_data.line_length,
			&vars->walls->north->img_data.endian);
	vars->walls->south->img_data.addr = 
		mlx_get_data_addr(vars->walls->south->img_data.img,
			&vars->walls->south->img_data.bits_per_pixel,
			&vars->walls->south->img_data.line_length,
			&vars->walls->south->img_data.endian);
	if (!vars->walls->east->img_data.addr || !vars->walls->west->img_data.addr
		|| !vars->walls->north->img_data.addr
		|| !vars->walls->south->img_data.addr)
		error_msg();
}

void	init_textures(t_win *vars)
{
	vars->walls->east->img_data.img = mlx_xpm_file_to_image(vars->mlx,
			vars->walls->east->path,
			&vars->walls->east->width,
			&vars->walls->east->height);
	vars->walls->west->img_data.img = mlx_xpm_file_to_image(vars->mlx,
			vars->walls->west->path,
			&vars->walls->west->width,
			&vars->walls->west->height);
	vars->walls->north->img_data.img = mlx_xpm_file_to_image(vars->mlx,
			vars->walls->north->path,
			&vars->walls->north->width,
			&vars->walls->north->height);
	vars->walls->south->img_data.img = mlx_xpm_file_to_image(vars->mlx,
			vars->walls->south->path,
			&vars->walls->south->width,
			&vars->walls->south->height);
	if (!vars->walls->east->img_data.img || !vars->walls->west->img_data.img
		|| !vars->walls->north->img_data.img
		|| !vars->walls->south->img_data.img)
		error_msg();
	init_textures2(vars);
}

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
	if (!vars->player || !vars->data || !vars->r_cast || !vars->m_map
		|| !vars->walls)
		return ;
	init_player(vars->map, vars->player);
	init_r_cast(vars);
	init_m_map(vars, vars->m_map);
	init_textures(vars);
}
