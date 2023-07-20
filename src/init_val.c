/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_val.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:48:21 by waraissi          #+#    #+#             */
/*   Updated: 2023/07/20 14:46:04 by waraissi         ###   ########.fr       */
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
	vars->view_angle = 90;
}

void	init(t_win *vars, t_data *data)
{
	vars->mlx = mlx_init();
	vars->mlx_win = mlx_new_window(vars->mlx, MAP_WIDTH, MAP_HEIGHT, "Cube3D");
	vars->line = get_linef();
	vars->map = ft_split(vars->line, '\n');
	vars->data = data;
	vars->forw_back = 0;
	vars->left_right = 0;
	vars->r_left_right = 0;
	vars->player = malloc(sizeof(t_player *));
	if (!vars->player)
		exit (1);
	init_player(vars->map, vars->player);
}
