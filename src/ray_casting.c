/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:17:00 by waraissi          #+#    #+#             */
/*   Updated: 2023/07/25 21:30:27 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

double	intersection_with_horizontal(t_win *vars, t_data *data)
{
	(void)vars;
	(void)data;
	return (0);
}

double	intersection_with_vertical(t_win *vars, t_data *data)
{
	(void)vars;
	(void)data;
	return (0);
}

void	start_ray_casting(t_win *vars, t_data *data)
{
	double	h_i;
	double	v_i;

	h_i = intersection_with_horizontal(vars, data);
	v_i = intersection_with_vertical(vars, data);
}
