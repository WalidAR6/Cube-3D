/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 09:43:02 by waraissi          #+#    #+#             */
/*   Updated: 2023/07/18 19:17:56 by waraissi         ###   ########.fr       */
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
	while (r < 5)
	{
		angl = 0;
		while (angl < 360)
		{
			x1 = r * cos(angl * PI / 180);
			x2 = r * sin(angl * PI / 180);
			my_mlx_pixel_put(data, x1 + x, x2 + y, color);
			angl += .1;
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
	
	i = (vars->player->y_player + 5) / 50;
	j = vars->player->x_player / 50;

	if (vars->map[i][j] != '1')
	{
		vars->player->x_player -= 5 * sin(vars->player->view_angle * PI / 180);
		vars->player->y_player -= 5 * cos(vars->player->view_angle * PI / 180);
	}
}
void	move_up(t_win	*vars)
{
	int i;
	int	j;
	
	i = (vars->player->y_player - 7) / 50;
	j = vars->player->x_player / 50;

	if (vars->map[i][j] != '1')
	{
		vars->player->x_player += 5 * sin(vars->player->view_angle * PI / 180);
		vars->player->y_player += 5 * cos(vars->player->view_angle * PI / 180);
	}
}

void	move_right(t_win *vars)
{
	int i;
	int	j;
	
	i = vars->player->y_player / 50;
	j = (vars->player->x_player + 5) / 50;

	if (vars->map[i][j] != '1')
	{
		vars->player->x_player -= 5 * sin((90 - vars->player->view_angle) * PI / 180);
		vars->player->y_player += 5 * cos((90 - vars->player->view_angle) * PI / 180);
	}
}

void	move_left(t_win	*vars)
{
	int i;
	int	j;
	
	i = vars->player->y_player / 50;
	j = (vars->player->x_player - 7) / 50;

	if (vars->map[i][j] != '1')
	{
		vars->player->x_player += 5 * sin((90 - vars->player->view_angle) * PI / 180);
		vars->player->y_player -= 5 * cos((90 - vars->player->view_angle) * PI / 180);
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
	printf("pressed key [%d]\n",keycode);
	mlx_clear_window(vars->mlx, vars->mlx_win);
	if (keycode == KEY_DOWN || keycode == ARROW_DOWN)
		move_down(vars);
	if (keycode == KEY_UP || keycode == ARROW_UP)
		move_up(vars);
	if (keycode == KEY_RIGHT)
		move_right(vars);
	if (keycode == KEY_LEFT)
		move_left(vars);
	if (keycode == ARROW_LEFT)
		rotate_left(vars);
	if (keycode == ARROW_RIGHT)
		rotate_right(vars);
	draw_map(vars, vars->data);
	draw_player(vars, vars->data);
	draw_line(vars, vars->data);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->data->img, 0, 0);
	return (0);
}

int		key_release(int keycode, t_win *vars)
{
	(void)vars;

	
	printf("released key [%d]\n",keycode);
	return (0);
}

int		hooks(t_win *vars)
{
	mlx_hook(vars->mlx_win, 2, 0, key_hook, vars);
	mlx_hook(vars->mlx_win, 3, 0, key_release, vars);
	return (0);
}

void	raycast(t_win *vars, t_data *data)
{
	vars->mlx_win = mlx_new_window(vars->mlx, MAP_WIDTH, MAP_HEIGHT, "Cube3D");
	data->img = mlx_new_image(vars->mlx, ft_strlen(vars->map[0])*50, 11*50);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length,
										&data->endian);
	draw_map(vars, vars->data);
	draw_player(vars, vars->data);
	draw_line(vars, vars->data);
	puts("ok");
	mlx_loop_hook(vars->mlx, hooks, vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, data->img, 0, 0);
}
