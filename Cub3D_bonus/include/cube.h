/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharib <aharib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:14:38 by waraissi          #+#    #+#             */
/*   Updated: 2023/10/13 23:00:13 by aharib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>

# include "get_next_line.h"
# include "libft.h"

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

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

typedef struct s_w_info
{
	t_data			img_data;
	char			*path;
	int				height;
	int				width;
	unsigned int	**pixels;
}					t_w_info;

typedef struct s_rgbt
{
	int				r;
	int				g;
	int				b;
	int				t;
}					t_rgbt;

typedef struct s_walls
{
	t_w_info		*east;
	t_w_info		*west;
	t_w_info		*north;
	t_w_info		*south;
}					t_walls;

typedef struct s_player
{
	double			x_player;
	double			y_player;
	double			view_angle;
}					t_player;

typedef struct s_ray_cast
{
	double			x_inc;
	double			y_inc;
	double			x_h;
	double			y_h;
	double			x_v;
	double			y_v;
}					t_ray_cast;

typedef struct s_m_map
{
	int				start_x;
	int				start_y;
	double			m_angle;
	int				r_rl;
	double			prev;
	int				flag;
	struct s_win	*data;
}					t_m_map;

typedef struct s_parse
{
	char		**p_line;
	char		**m_line;
	char		**ref;
	char		**value;
}				t_parse;

typedef struct s_win
{
	void			*mlx;
	void			*mlx_win;
	char			**map;
	int				forw_back;
	int				left_right;
	int				r_left_right;
	int				m_step;
	int				c_color;
	int				f_color;
	int				map_height;
	int				map_width;
	int				fov;
	double			dis;
	double			dis_p_plan;
	double			slice_lenght;
	double			angle;
	double			n_angle;
	double			r_angle;
	t_parse			*parse;
	t_ray_cast		*r_cast;
	t_data			*data;
	t_player		*player;
	t_m_map			*m_map;
	t_walls			*walls;
}					t_win;

void				start_game(t_win *vars, t_data *data);
void				init(t_win *vars);
void				get_player_pos(char **map, t_player *vars);
void				draw_square(t_win *vars, int color);
void				draw_cercle(t_win *vars, int color);
void				draw_map(t_win *vars, t_data *data);
void				draw_player(t_win *vars);
void				draw_line(t_win *vars, t_data *data);
void				move_down(t_win *vars);
void				move_up(t_win *vars);
void				move_right(t_win *vars);
void				move_left(t_win *vars);
void				rotate(t_win *vars, int flag);
void				pixel_put(t_data *data, int x, int y, int color);
int					key_hook(int keycode, t_win *vars);
int					key_release(int keycode, t_win *vars);
int					quit_game(t_win *vars);
void				move_player(t_win *vars);
void				drawing_all(t_win *vars);
int					hooks(t_win *vars);
void				print_map(t_win *vars);
void				start_ray_casting(t_win *vars);
void				dda_line(t_win *vars, double x, double y, int color);
void				first_horizontal_intersection(t_win *vars, double t,
						double i);
void				first_vertical_intersection(t_win *vars, double t,
						double i);
void				modify_angle(double *angle);
int					looking_direction(t_win *vars, double i);
int					looking_direction_2(t_win *vars, double i);
void				game_component(t_win *vars);
void				draw_walls(t_win *vars, double i, double angle, int h);
void				draw_mini_map(t_win *vars, t_m_map *m_map);
void				mouse_mouvement(t_win *vars);
int					start_mov(int x, int y, t_win *vars);
int					get_map_height(t_win *vars);
int					check_map_width(t_win *vars, double x, double y);
int					player_view_direction(char **map);
int					wall_leak(t_win *vars, double i, double j);
/****PARSING****/
char				**parsing(t_win *vars, int fd);
/*params*/
void				init_params(t_win *vars);
char				**params_line(int fd);
void				parse_params(char **p_line, t_win *vars);
int					check_length(char *param);
void				check_params(char *param);
void				check_duplicate(char **param);
/*maps*/
char				**map_line(int fd);
void				check_other_char(char **m_line);
void				check_surroundings(char **m_line);
void				clean_map(char **m_line);
/*value*/
void				check_param_value(char *param, char *value, int n,
						t_win *vars);
void				check_fc_value(char *value, t_win *vars, int n);
/*utils*/
int					check_empty_line(char *line);
void				check_digit(char *str);
int					ft_doublen(char **str);
int					white_spaces(char c);
void				error_msg(void);
void				ft_freedbl(char **str);
int					set_colors(int r, int g, int b);
/*textures*/
void				init_textures(t_win *vars);
unsigned int		**pixels_color(t_w_info *wall);
void				init_colors(t_win *vars);
void				paint_wall(t_win *vars, t_w_info *wall,
						int offx, double angle);
void				draw_celling(t_win *vars);
void				draw_floor(t_win *vars);

unsigned int		get_pixel(t_data *data, int x, int y);
void				paint_celling(t_win *vars);
void				paint_floor(t_win *vars);
void				count_commas(char *value);
int					is_horizental(t_win *vars, double h_i,
						double v_i, double n_angle);
int					check_map_width(t_win *vars, double x, double y);
int					surround(char c);
int					value_start(char *str);
int					check_tabulation(char **str);

#endif