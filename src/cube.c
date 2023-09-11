/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharib <aharib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:14:04 by waraissi          #+#    #+#             */
/*   Updated: 2023/09/11 18:20:26 by aharib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

int		check_empty_line(char *line)
{
	if (line[0] == '\n')
		return (0);
	return (1);
}

void	parse_params(char **p_line)
{
	char **tmp;
	int	i;

	i = 0;
	while (p_line[i])
	{
		tmp = ft_split(p_line[i], ' ');
		if (ft_strlen(tmp[0]) == 2 &&
			(ft_strcmp(tmp[0], "NO") && ft_strcmp(tmp[0], "SO")
			&& ft_strcmp(tmp[0], "EA") && ft_strcmp(tmp[0], "WE")))
		{
			write (1, "ERROR in map directions !\n", 26);
			exit (1);
		}
		i++;
	}
}

char	**params_line(int fd)
{
	char	*line;
	char	*tmp_line;
	char	**p_line;
	int 	n;
	
	n = 0;
	line = ft_strdup("");
	tmp_line = NULL;
	while (1)
	{
		tmp_line = get_next_line(fd);
		if (tmp_line == NULL || n == 6)
			break ;
		if (check_empty_line(tmp_line) == 1)
		{
			line = ft_strjoin(line, tmp_line);
			n++;
		}
		free(tmp_line);
	}
	p_line = ft_split(line, '\n');
	return (p_line);
}

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