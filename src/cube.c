/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:14:04 by waraissi          #+#    #+#             */
/*   Updated: 2023/07/21 13:04:38 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

int	main(int ac, char **av)
{
	(void)av;
	(void)ac;
	t_win	vars;
	t_data	data;

	init(&vars, &data);
	start_game(&vars, &data);
	mlx_loop(vars.mlx);
	return (0);
}
