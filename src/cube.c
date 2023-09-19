/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharib <aharib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:14:04 by waraissi          #+#    #+#             */
/*   Updated: 2023/09/19 17:39:10 by aharib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

int	main(int ac, char **av)
{
	int		fd;
	t_win	vars;
	char 	**p_line;
	// t_data	data;

	if (ac == 2)
	{
		if (av[1][ft_strlen(av[1]) - 1] != 'b'
			|| av[1][ft_strlen(av[1]) - 2] != 'u'
			|| av[1][ft_strlen(av[1]) - 3] != 'c'
			|| av[1][ft_strlen(av[1]) - 4] != '.')
		{
			write(1, "ERROR in map file !\n", 21);
			exit (1);
		}
		fd = open (av[1], O_RDONLY);
		p_line = params_line(fd);
		parse_params(p_line);
		int i = 0;
		while (p_line[i])
		{
			printf("[%s]\n", p_line[i]);
			i++;
		}
		exit (1);
		init(&vars);
		start_game(&vars, vars.data);
		mlx_loop(vars.mlx);
		return (0);
	}
}