/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharib <aharib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 02:23:10 by aharib            #+#    #+#             */
/*   Updated: 2023/10/09 00:54:43 by aharib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

t_rgbt	color_extractor(t_data *img, int x, int y)
{
	t_rgbt	color;

	color.t = (unsigned int)img->addr[(y * img->line_length + x
				* (img->bits_per_pixel / 8)) + 3];
	color.r = (unsigned int)img->addr[(y * img->line_length + x
				* (img->bits_per_pixel / 8)) + 2];
	color.g = (unsigned int)img->addr[(y * img->line_length + x
				* (img->bits_per_pixel / 8)) + 1];
	color.b = (unsigned int)img->addr[(y * img->line_length + x
				* (img->bits_per_pixel / 8))];
	return (color);
}

unsigned int	**pixels_color(t_win *vars)
{
	unsigned int	**pixels;
	t_rgbt 			color;
	int				i;
	int				j;

	i = 0;
	pixels = malloc(sizeof(unsigned int *) * 64);
	while (i < 64)
	{
		pixels[i] = malloc(sizeof(unsigned int) * 64);
		j = 0;
		while (j < 64)
		{
			color = color_extractor(&vars->walls->east.img_data,
					i, j);
			pixels[i][j] = set_colors(color.r, color.g, color.b);
			j++;
		}
		i++;
	}
	return (pixels);
}

void	init_colors(t_win *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	vars->walls->east.pixels = pixels_color(vars);
	vars->walls->west.pixels = pixels_color(vars);
	vars->walls->north.pixels = pixels_color(vars);
	vars->walls->south.pixels = pixels_color(vars);
	while (i > 64)
	{
		j = 0;
		while (j > 64)
		{
			printf("%s\n", ft_itoa(vars->walls->east.pixels[i][j]));
			j++;
		}
		i++;
	}
}

void	init_textures2(t_win *vars)
{
	vars->walls->east.img_data.addr = mlx_get_data_addr(
			vars->walls->east.img_data.img,
			&vars->walls->east.img_data.bits_per_pixel,
			&vars->walls->east.img_data.line_length,
			&vars->walls->east.img_data.endian);
	vars->walls->west.img_data.addr = mlx_get_data_addr(
			vars->walls->west.img_data.img,
			&vars->walls->west.img_data.bits_per_pixel,
			&vars->walls->west.img_data.line_length,
			&vars->walls->west.img_data.endian);
	vars->walls->north.img_data.addr = mlx_get_data_addr(
			vars->walls->north.img_data.img,
			&vars->walls->north.img_data.bits_per_pixel,
			&vars->walls->north.img_data.line_length,
			&vars->walls->north.img_data.endian);
	vars->walls->south.img_data.addr = mlx_get_data_addr(
			vars->walls->south.img_data.img,
			&vars->walls->south.img_data.bits_per_pixel,
			&vars->walls->south.img_data.line_length,
			&vars->walls->south.img_data.endian);
	if (vars->walls->east.img_data.addr == NULL
		|| vars->walls->west.img_data.addr == NULL
		|| vars->walls->north.img_data.addr == NULL
		|| vars->walls->south.img_data.addr == NULL)
		error_msg();
}

void	init_textures(t_win *vars)
{
	vars->walls->east.img_data.img = mlx_xpm_file_to_image(vars->mlx,
			vars->walls->east.path, &vars->walls->east.size,
			&vars->walls->east.size);
	vars->walls->west.img_data.img = mlx_xpm_file_to_image(vars->mlx,
			vars->walls->west.path, &vars->walls->west.size,
			&vars->walls->west.size);
	vars->walls->north.img_data.img = mlx_xpm_file_to_image(vars->mlx,
			vars->walls->north.path, &vars->walls->north.size,
			&vars->walls->north.size);
	vars->walls->south.img_data.img = mlx_xpm_file_to_image(vars->mlx,
			vars->walls->south.path, &vars->walls->south.size,
			&vars->walls->south.size); 
	// if (!vars->walls->east.img_data.img || !vars->walls->west.img_data.img
	// 	|| !vars->walls->north.img_data.img || !vars->walls->south.img_data.img)
	// 	error_msg();
	// init_textures2(vars);
}
