/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_val.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:48:21 by waraissi          #+#    #+#             */
/*   Updated: 2023/07/16 14:53:26 by waraissi         ###   ########.fr       */
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
	vars->view_angle = 0;
}

void	init(t_win *vars, t_data *data)
{
	vars->line = get_linef();
	vars->map = ft_split(vars->line, '\n');
	vars->data = data;
	vars->player = malloc(sizeof(t_player *));
	if (!vars)
		exit (1);
	init_player(vars->map, vars->player);
}
