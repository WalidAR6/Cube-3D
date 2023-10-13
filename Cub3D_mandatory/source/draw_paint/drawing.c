/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharib <aharib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 10:52:04 by waraissi          #+#    #+#             */
/*   Updated: 2023/10/13 03:11:07 by aharib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

void	draw_ea_we(t_win *vars, double i, double angle)
{
	int		offx;

	if ((angle >= 90 && angle <= 270))
	{
		offx = (int)(vars->r_cast->y_v) % vars->walls->west->width;
		paint_wall(vars, vars->walls->west, offx, i);
	}
	else if (angle < 90 || angle > 270)
	{
		offx = (int)(vars->r_cast->y_v) % vars->walls->east->width;
		paint_wall(vars, vars->walls->east, offx, i);
	}
}

void	draw_no_so(t_win *vars, double i, double angle)
{
	int		offx;

	if (angle >= 0 && angle <= 180)
	{
		offx = (int)(vars->r_cast->x_h) % vars->walls->south->width;
		paint_wall(vars, vars->walls->south, offx, i);
	}
	else if (angle > 180 && angle <= 360)
	{
		offx = (int)(vars->r_cast->x_h) % vars->walls->north->width;
		paint_wall(vars, vars->walls->north, offx, i);
	}
}

void	draw_walls(t_win *vars, double i, double angle, int h)
{
	vars->slice_lenght = 50 / vars->dis * vars->dis_p_plan;
	if (h == 0)
		draw_ea_we(vars, i, angle);
	else
		draw_no_so(vars, i, angle);
}
