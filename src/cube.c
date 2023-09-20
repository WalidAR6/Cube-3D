/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharib <aharib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:14:04 by waraissi          #+#    #+#             */
/*   Updated: 2023/09/20 00:23:06 by aharib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

char	**map_line(int fd)
{
	char	*line;
	char	*tmp_line;
	char 	**m_line;

	line = ft_strdup("");
	tmp_line = NULL;
	while (1)
	{
		tmp_line = get_next_line(fd);
		if (tmp_line == NULL)
			break ;
		if (check_empty_line(tmp_line) == 1)
			line = ft_strjoin(line, tmp_line);
	}
	m_line = ft_split(line, '\n');
	return (m_line);
}

int	main(int ac, char **av)
{
	int		fd;
	t_win	vars;
	char 	**p_line;
	char 	**m_line;
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
		m_line = map_line(fd);
		int i = 0;
		while (m_line[i])
		{
			printf("[%s]\n", m_line[i]);
			i++;
		}
		exit (1);
		init(&vars);
		start_game(&vars, vars.data);
		mlx_loop(vars.mlx);
		return (0);
	}
}