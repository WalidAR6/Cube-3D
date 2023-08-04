/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:14:38 by waraissi          #+#    #+#             */
/*   Updated: 2023/08/04 18:44:58 by waraissi         ###   ########.fr       */
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

# define MAP_WIDTH 2000
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

# define REDIUS 5
# define FOV 60

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

typedef struct s_dda
{
	double	px;
	double	py;
	double	dx;
	double	dy;
	double	x_inc;
	double	y_inc;
}				t_dda;

typedef struct s_ray_cast
{
	double	x_inc;
	double	y_inc;
	double	x_h;
	double	y_h;
	double	x_v;
	double	y_v;
}				t_ray_cast;

typedef struct s_win
{
	void		*mlx;
	void		*mlx_win;
	char		**map;
	char		*line;
	int			forw_back;
	int			left_right;
	int			r_left_right;
	int			m_step;
	double		dis;
	double		dis_p_plan;
	t_ray_cast	*r_cast;
	t_dda		*dda_params;
	t_data		*data;
	t_player	*player;
}				t_win;

void	start_game(t_win *vars, t_data *data);
void	init(t_win *vars);
void	get_player_pos(char **map, t_player *vars);
void	draw_square(t_data *data, int x, int y, int color);
void	draw_cercle(t_win *vars, int color);
void	draw_map(t_win *vars, t_data *data);
void	draw_player(t_win *vars);
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
void	drawing_all(t_win *vars);
int		hooks(t_win *vars);
void	print_map(t_win *vars);
void	start_ray_casting(t_win *vars);
void	dda_line(t_win *vars, double x, double y, int color);
void	first_horizontal_intersection(t_win *vars, double t, double i);
void	first_vertical_intersection(t_win *vars, double t, double i);
void	modify_angle(double *angle);
int		looking_direction(t_win *vars, double i);
int		looking_direction_2(t_win *vars, double i);
void	game_component(t_win *vars);
void	draw_walls(t_win *vars, int i);
void	dda_wall(t_win *vars, double xs, double ys, double xe, double ye, int color);

#endif