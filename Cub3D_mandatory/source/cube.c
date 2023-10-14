/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharib <aharib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:14:04 by waraissi          #+#    #+#             */
/*   Updated: 2023/10/13 23:10:38 by aharib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	map_argument_check(char *av)
{
	if (av[ft_strlen(av) - 1] != 'b'
		|| av[ft_strlen(av) - 2] != 'u'
		|| av[ft_strlen(av) - 3] != 'c'
		|| av[ft_strlen(av) - 4] != '.')
		error_msg();
}

int	main(int ac, char **av)
{
	int		fd;
	t_win	vars;

	if (ac == 2)
	{
		map_argument_check(av[1]);
		init_params(&vars);
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			error_msg();
		vars.map = parsing(&vars, fd);
		init(&vars);
		start_game(&vars, vars.data);
		mlx_loop(vars.mlx);
		close(fd);
		exit(0);
	}
	else
		error_msg();
	return (0);
}
