/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 09:43:02 by waraissi          #+#    #+#             */
/*   Updated: 2023/07/20 19:10:34 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

void	print_map(t_win *vars)
{
	int i = 0;
	while (vars->map[i])
	{
		printf("%s\n",vars->map[i]);
		i++;
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_square(t_data *data, int x, int y, int color)
{
	int i;
	int j;
	
	i = 0;
	while (i < 50)
	{
		j = 0;
		while (j < 50)
		{
			my_mlx_pixel_put(data, i + y, j + x, color);
			j++;
		}
		i++;
	}
}

void	draw_square1(t_data *data, int y, int x, int color)
{
	double	x1;
	double	x2;
	double	angl;
	int		r;

	angl = 0;
	r = 0;
	while (r < 2)
	{
		angl = 0;
		while (angl < 360)
		{
			x1 = r * cos(angl * PI / 180);
			x2 = r * sin(angl * PI / 180);
			my_mlx_pixel_put(data, x1 + x, x2 + y, color);
			angl += 1;
		}
		r += 1;
	}
}

void	draw_map(t_win *vars, t_data *data)
{
	int i;
	int j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == '1')
				draw_square(data, i*50, j*50, WALL_COLOR);
			else
				draw_square(data, i*50, j*50, GROUND_COLOR);
			j++;
		}
		i++;
	}
}


void	draw_player(t_win *vars, t_data *data)
{
	int i;
	int j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'N')
				draw_square1(data, vars->player->y_player, vars->player->x_player, PLAYER_COLOR);
			j++;
		}
		i++;
	}
}

void	move_down(t_win	*vars)
{
	int i;
	int	j;
	
	i = vars->player->y_player;
	j = vars->player->x_player;
	vars->player->x_player -= 5 * sin(vars->player->view_angle * PI / 180);
	vars->player->y_player -= 5 * cos(vars->player->view_angle * PI / 180);
	if (vars->map[(int)vars->player->y_player/50][(int)vars->player->x_player/50] == '1')
	{
		vars->player->y_player = i;
		vars->player->x_player = j;
	}
}
void	move_up(t_win	*vars)
{
	int i;
	int	j;
	
	i = vars->player->y_player;
	j = vars->player->x_player;
	vars->player->x_player += 5 * sin(vars->player->view_angle * PI / 180);
	vars->player->y_player += 5 * cos(vars->player->view_angle * PI / 180);
	if (vars->map[(int)vars->player->y_player / 50][(int)vars->player->x_player / 50] == '1')
	{
		vars->player->y_player = i;
		vars->player->x_player = j;
	}
}

void	move_right(t_win *vars)
{
	double i;
	double j;
	double k;
	double h;
	
	i = vars->player->y_player;
	j = vars->player->x_player;
	k = j + sin((90 - vars->player->view_angle) * PI / 180);
	h = i + cos((90 - vars->player->view_angle) * PI / 180);
	if (vars->map[(int)h / 50][(int)k / 50] != '1')
	{
		vars->player->x_player -= 3 * (k - j);
		vars->player->y_player += 3 * (h - i);
	}

}

void	move_left(t_win	*vars)
{	
	double i;
	double j;
	double k;
	double h;
	
	i = vars->player->y_player;
	j = vars->player->x_player;
	k = j + sin((90 - vars->player->view_angle) * PI / 180);
	h = i + cos((90 - vars->player->view_angle) * PI / 180);
	if (vars->map[(int)h / 50][(int)k / 50] != '1')
	{
		vars->player->x_player += 3 * (k - j);
		vars->player->y_player -= 3 * (h - i);
	}
}

void	get_player_pos(char **map, t_player *vars)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 1;
		while (map[i][j])
		{
			if (map[i][j] == 'N')
			{
				vars->x_player = j*50 + 25;
				vars->y_player = i*50 + 25;
				break;
			}
			j++;
		}
		i++;
	}
}

void	rotate_left(t_win *vars)
{
	vars->player->view_angle += 3;
	if (vars->player->view_angle > 360)
		vars->player->view_angle = 0.0;
}

void	rotate_right(t_win *vars)
{
	vars->player->view_angle -= 3;
	if (vars->player->view_angle <= 0.0)
		vars->player->view_angle = 360;
}

void	draw_line(t_win *vars, t_data *data)
{
	int i;

	i = 0;
	while (i < 30)
	{
		my_mlx_pixel_put(data,
			vars->player->x_player + i * sin(vars->player->view_angle * PI / 180),
			vars->player->y_player + i * cos(vars->player->view_angle * PI / 180),
			PLAYER_COLOR);
		i++;
	}
}
int		key_hook(int keycode, t_win *vars)
{
	if (keycode == KEY_DOWN || keycode == ARROW_DOWN)
		vars->forw_back = -1;
	if (keycode == KEY_UP || keycode == ARROW_UP)	
		vars->forw_back = 1;
	if (keycode == KEY_RIGHT)
		vars->left_right = 1;
	if (keycode == KEY_LEFT)
		vars->left_right = -1;
	if (keycode == ARROW_LEFT)
		vars->r_left_right = -1;
	if (keycode == ARROW_RIGHT)
		vars->r_left_right = 1;
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		exit(0);
	}
	return (0);
}

int		key_release(int keycode, t_win *vars)
{
	if (keycode == KEY_DOWN || keycode == ARROW_DOWN)
		vars->forw_back = 0;
	if (keycode == KEY_UP || keycode == ARROW_UP)	
		vars->forw_back = 0;
	if (keycode == KEY_RIGHT)
		vars->left_right = 0;
	if (keycode == KEY_LEFT)
		vars->left_right = 0;
	if (keycode == ARROW_LEFT)
		vars->r_left_right = 0;
	if (keycode == ARROW_RIGHT)
		vars->r_left_right = 0;
	return (0);
}

int		quit_game(int keycode, t_win *vars)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(vars->mlx, vars->data->img);
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		exit(0);
	}
	return (0);
}

void	move_player(t_win *vars)
{
	if (vars->forw_back == -1)
		move_down(vars);
	if (vars->forw_back == 1)
		move_up(vars);
	if (vars->left_right == -1)
		move_left(vars);
	if (vars->left_right == 1)
		move_right(vars);
	if (vars->r_left_right == -1)
		rotate_left(vars);
	if (vars->r_left_right == 1)
		rotate_right(vars);
}

int		hooks(t_win *vars)
{
	mlx_destroy_image(vars->mlx, vars->data->img);
	vars->data->img = mlx_new_image(vars->mlx, ft_strlen(vars->map[0])*50, 11*50);
	vars->data->addr = mlx_get_data_addr(vars->data->img, &vars->data->bits_per_pixel, &vars->data->line_length,
										&vars->data->endian);
	move_player(vars);
	draw_map(vars, vars->data);
	draw_player(vars, vars->data);
	draw_line(vars, vars->data);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->data->img, 0, 0);
	return (0);
}

void	raycast(t_win *vars, t_data *data)
{
	data->img = mlx_new_image(vars->mlx, ft_strlen(vars->map[0])*50, 11*50);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length,
										&data->endian);
	draw_map(vars, vars->data);
	draw_player(vars, vars->data);
	draw_line(vars, vars->data);	
	mlx_hook(vars->mlx_win, 2, 0, key_hook, vars);
	mlx_hook(vars->mlx_win, 3, 0, key_release, vars);
	mlx_hook(vars->mlx_win, 17, 0, quit_game, vars);
	mlx_loop_hook(vars->mlx, hooks, vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, data->img, 0, 0);
}
