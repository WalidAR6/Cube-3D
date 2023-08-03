/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_val.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:48:21 by waraissi          #+#    #+#             */
/*   Updated: 2023/08/03 13:49:41 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

char	*get_linef(void)
{
	int	fd;
	char	*line;
	char	*join;

	join = NULL;
	fd = open("textures/map.cub", O_RDONLY);
	if (fd < 0)
		exit (1);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		join = ft_strjoin(join, line);
	}
	free(line);
	return (join);
}

void	init_player(char **map,t_player *vars)
{
	get_player_pos(map, vars);
	vars->view_angle = 50;
}

void	init_dda(t_win *vars)
{
	vars->dda_params->px = 0;	
	vars->dda_params->py = 0;
	vars->dda_params->dx = 0;
	vars->dda_params->dy = 0;
	vars->dda_params->x_inc = 0;
	vars->dda_params->y_inc = 0;
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
	vars->mlx_win = mlx_new_window(vars->mlx, MAP_WIDTH, MAP_HEIGHT, "Cube3D");
	vars->line = get_linef();
	vars->map = ft_split(vars->line, '\n');
	vars->forw_back = 0;
	vars->left_right = 0;
	vars->r_left_right = 0;
	vars->m_step = 5;
	vars->dis = 0;
	vars->data = malloc(sizeof(t_data));
	vars->player = malloc(sizeof(t_player));
	vars->dda_params = malloc(sizeof(t_dda));
	vars->r_cast = malloc(sizeof(t_ray_cast));
	if (!vars->player || !vars->data || !vars->dda_params || !vars->r_cast)
		exit (1);
	init_player(vars->map, vars->player);
	init_dda(vars);
	init_r_cast(vars);
}
