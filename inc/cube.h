/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:14:38 by waraissi          #+#    #+#             */
/*   Updated: 2023/07/18 18:47:59 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>
# include<fcntl.h>
# include<mlx.h>
# include<math.h>
# include"libft.h"
# include"get_next_line.h"

# define WALL_COLOR 0x01529B
# define GROUND_COLOR 0xcccccc
# define PLAYER_COLOR 0x000000

# define MAP_WIDTH 1600
# define MAP_HEIGHT 900

# define KEY_UP 13
# define KEY_LEFT 0
# define KEY_RIGHT 2
# define KEY_DOWN 1
# define ARROW_UP 126
# define ARROW_DOWN 125
# define ARROW_RIGHT 124
# define ARROW_LEFT 123
# define KEY_ESC 53

# define PI 3.14159265359

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_player
{
	double		x_player;
	double		y_player;
	double		view_angle;
}				t_player;

typedef struct s_win
{
	void		*mlx;
	void		*mlx_win;
	char		**map;
	char		*line;
	int			*key_value;
	char		*key_tab;
	t_data		*data;
	t_player	*player;
}				t_win;

void	raycast(t_win *vars, t_data *data);
void	init(t_win *vars, t_data *data);
void	get_player_pos(char **map, t_player *vars);

#endif