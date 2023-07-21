/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:14:38 by waraissi          #+#    #+#             */
/*   Updated: 2023/07/21 11:41:10 by waraissi         ###   ########.fr       */
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

# define true 1
# define false 0

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
	int			forw_back;
	int			left_right;
	int			r_left_right;
	t_data		*data;
	t_player	*player;
}				t_win;

void	start_game(t_win *vars, t_data *data);
void	init(t_win *vars, t_data *data);
void	get_player_pos(char **map, t_player *vars);
void	draw_square(t_data *data, int x, int y, int color);
void	draw_cercle(t_data *data, int y, int x, int color);
void	draw_map(t_win *vars, t_data *data);
void	draw_player(t_win *vars, t_data *data);
void	draw_line(t_win *vars, t_data *data);
void	move_down(t_win	*vars);
void	move_up(t_win	*vars);
void	move_right(t_win *vars);
void	move_left(t_win	*vars);
void	rotate(t_win *vars, int flag);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		key_hook(int keycode, t_win *vars);
int		key_release(int keycode, t_win *vars);
int		quit_game(int keycode, t_win *vars);
void	move_player(t_win *vars);
int		hooks(t_win *vars);
void	print_map(t_win *vars);

#endif