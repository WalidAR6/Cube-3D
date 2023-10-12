/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_component.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharib <aharib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:03:41 by waraissi          #+#    #+#             */
/*   Updated: 2023/10/11 22:14:40 by aharib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	game_component(t_win *vars)
{
	paint_celling(vars);
	paint_floor(vars);
}
