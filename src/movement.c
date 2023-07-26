/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 10:54:48 by waraissi          #+#    #+#             */
/*   Updated: 2023/07/26 15:47:22 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

void	move_down(t_win	*vars)
{
	double i;
	double	j;

	i = vars->player->y_player - 5 * sin(vars->player->view_angle * PI / 180);
	j = vars->player->x_player - 5 * cos(vars->player->view_angle * PI / 180);
	if (vars->map[(int)i / 50][(int)j / 50] != '1')
	{
		vars->player->x_player -= 5 * cos(vars->player->view_angle * PI / 180);
		vars->player->y_player -= 5 * sin(vars->player->view_angle * PI / 180);
	}
}
void	move_up(t_win	*vars)
{
	double i;
	double j;

	i = vars->player->y_player + 5 * sin(vars->player->view_angle * PI / 180);
	j = vars->player->x_player + 5 * cos(vars->player->view_angle * PI / 180);
	if (vars->map[(int)i / 50][(int)j / 50] != '1')
	{
		vars->player->x_player += 5 * cos(vars->player->view_angle * PI / 180);
		vars->player->y_player += 5 * sin(vars->player->view_angle * PI / 180);
	}
}

void	move_right(t_win *vars)
{
	double i;
	double j;

	i = vars->player->y_player + 5 * sin((90 - vars->player->view_angle) * PI / 180);
	j = vars->player->x_player - 5 * cos((90 - vars->player->view_angle) * PI / 180);
	if (vars->map[(int)i / 50][(int)j / 50] != '1')
	{
		vars->player->x_player -= 5 * cos((90 - vars->player->view_angle) * PI / 180);
		vars->player->y_player += 5 * sin((90 - vars->player->view_angle) * PI / 180);
	}

}

void	move_left(t_win	*vars)
{	
	double i;
	double j;

	i = vars->player->y_player - 5 * sin((90 - vars->player->view_angle) * PI / 180);
	j = vars->player->x_player + 5 * cos((90 - vars->player->view_angle) * PI / 180);
	if (vars->map[(int)i / 50][(int)j / 50] != '1')
	{
		vars->player->x_player += 5 * cos((90 - vars->player->view_angle) * PI / 180);
		vars->player->y_player -= 5 * sin((90 - vars->player->view_angle) * PI / 180);
	}
}
void	rotate(t_win *vars, int flag)
{
	if (flag == -1)
	{
		vars->player->view_angle -= 2;
		if (vars->player->view_angle <= 0.0)
			vars->player->view_angle = 360;	
	}
	else
	{
		vars->player->view_angle += 2;
		if (vars->player->view_angle > 360)
			vars->player->view_angle = 0.0;
	}
}
