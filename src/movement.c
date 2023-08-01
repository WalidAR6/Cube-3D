/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 10:54:48 by waraissi          #+#    #+#             */
/*   Updated: 2023/07/31 19:37:44 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

void	move_down(t_win	*vars)
{
	double	i;
	double	j;
	double	m_y;
	double	m_x;

	m_x = 5 * cos(vars->player->view_angle * PI / 180);
	m_y = 5 * sin(vars->player->view_angle * PI / 180);
	i = vars->player->y_player - m_y;
	j = vars->player->x_player - m_x;
	if (vars->map[(int)i / 50][(int)j / 50] != '1' && vars->map[(int)i / 50][(int)j / 50] != ' ')
	{
		vars->player->x_player -= m_x;
		vars->player->y_player -= m_y;
	}
}
void	move_up(t_win	*vars)
{
	double i;
	double j;
	double	m_y;
	double	m_x;

	m_x = 5 * cos(vars->player->view_angle * PI / 180);
	m_y = 5 * sin(vars->player->view_angle * PI / 180);
	i = vars->player->y_player + m_y;
	j = vars->player->x_player + m_x;
	if (vars->map[(int)i / 50][(int)j / 50] != '1' && vars->map[(int)i / 50][(int)j / 50] != ' ')
	{
		vars->player->x_player += m_x;
		vars->player->y_player += m_y;
	}
}

void	move_right(t_win *vars)
{
	double i;
	double j;
	double	m_y;
	double	m_x;

	m_x = 5 * cos((90 - vars->player->view_angle) * PI / 180);
	m_y = 5 * sin((90 - vars->player->view_angle) * PI / 180);
	i = vars->player->y_player + m_y;
	j = vars->player->x_player - m_x;
	if (vars->map[(int)i / 50][(int)j / 50] != '1' && vars->map[(int)i / 50][(int)j / 50] != ' ')
	{
		vars->player->x_player -= m_x;
		vars->player->y_player += m_y;
	}

}

void	move_left(t_win	*vars)
{	
	double i;
	double j;
	double	m_y;
	double	m_x;

	m_x = 5 * cos((90 - vars->player->view_angle) * PI / 180);
	m_y = 5 * sin((90 - vars->player->view_angle) * PI / 180);
	i = vars->player->y_player - m_y;
	j = vars->player->x_player + m_x;
	if (vars->map[(int)i / 50][(int)j / 50] != '1' && vars->map[(int)i / 50][(int)j / 50] != ' ')
	{
		vars->player->x_player += m_x;
		vars->player->y_player -= m_y;
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
