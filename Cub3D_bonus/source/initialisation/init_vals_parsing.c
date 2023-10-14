/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vals_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharib <aharib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:24:28 by aharib            #+#    #+#             */
/*   Updated: 2023/10/13 22:46:12 by aharib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

void	init_params(t_win *vars)
{
	vars->parse = malloc(sizeof(t_parse));
	vars->f_color = -1;
	vars->c_color = -1;
	vars->walls = malloc(sizeof(t_walls));
	vars->walls->east = malloc(sizeof(t_w_info));
	vars->walls->west = malloc(sizeof(t_w_info));
	vars->walls->north = malloc(sizeof(t_w_info));
	vars->walls->south = malloc(sizeof(t_w_info));
	if (!vars->walls || !vars->walls->east || !vars->walls->west
		|| !vars->walls->north || !vars->walls->south)
		error_msg();
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
		|| !vars->walls->south->img_data.img || vars->walls->east->width > 64
		|| vars->walls->west->width > 64 || vars->walls->north->width > 64
		|| vars->walls->south->width > 64 || vars->walls->east->height > 64
		|| vars->walls->west->height > 64 || vars->walls->north->height > 64
		|| vars->walls->south->height > 64)
		error_msg();
	init_textures2(vars);
}
