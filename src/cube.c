/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:14:04 by waraissi          #+#    #+#             */
/*   Updated: 2023/09/26 22:47:19 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

int	main(int ac, char **av)
{
	(void)av;
	(void)ac;
	t_win	vars;

	init(&vars);
	start_game(&vars, vars.data);
	mlx_loop(vars.mlx);
	return (0);
}
