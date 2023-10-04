/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharib <aharib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:14:04 by waraissi          #+#    #+#             */
/*   Updated: 2023/10/04 19:05:38 by aharib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

void	check_surroundings(char **m_line)
{
	int		i;
	size_t	j;

	i = 0;
	while (m_line[i])
	{
		j = 0;
		while (m_line[i][j])
		{
			if (m_line[i][j] == '0' || m_line[i][j] == 'N'
				|| m_line[i][j] == 'S' || m_line[i][j] == 'E'
				|| m_line[i][j] == 'W')
			{
				if (j == 0 || j == ft_strlen(m_line[i]) - 1 || i == 0
					|| i == ft_doublen(m_line) - 1 || m_line[i + 1][j] == '&'
					|| m_line[i - 1][j] == '&' || m_line[i][j - 1] == '&'
					|| m_line[i][j + 1] == '&')
					error_msg();
			}
			j++;
		}
		i++;
	}
}

void	check_other_char(char **m_line)
{
	int	i;
	int	j;
	int	n;

	i = -1;
	n = 0;
	while (m_line[++i])
	{
		j = -1;
		while (m_line[i][++j])
		{
			if (m_line[i][j] == 'N' || m_line[i][j] == 'S'
				|| m_line[i][j] == 'E' || m_line[i][j] == 'W')
				n++;
			if (white_spaces(m_line[i][j]) == 0)
				m_line[i][j] = '&';
			else if ((m_line[i][j] != '0' && m_line[i][j] != '1'
						&& m_line[i][j] != 'N' && m_line[i][j] != 'S'
						&& m_line[i][j] != 'E' && m_line[i][j] != 'W') || n > 1)
				error_msg();
		}
	}
	if (n == 0)
		error_msg();
}

char	**map_line(int fd)
{
	char	*line;
	char	*tmp_line;
	char	**m_line;

	line = ft_strdup("");
	tmp_line = NULL;
	while (1)
	{
		tmp_line = get_next_line(fd);
		if (tmp_line == NULL || check_empty_line(tmp_line) == 0)
			break ;
		line = ft_strjoin(line, tmp_line);
		free(tmp_line);
	}
	while (1)
	{
		tmp_line = get_next_line(fd);
		if (tmp_line == NULL)
			break ;
		if (check_empty_line(tmp_line) == 1)
			error_msg();
		free(tmp_line);
	}
	m_line = ft_split(line, '\n');
	free(line);
	return (m_line);
}

void clean_map(char **m_line)
{
	int	i;
	int	j;

	i = 0;
	while (m_line[i])
	{
		j = 0;
		while (m_line[i][j])
		{
			if (m_line[i][j] == '&')
				m_line[i][j] = ' ';
			j++;
		}
		i++;
	}
}

void f()
{
	system("leaks Cub3D");
}

// unsigned long convertRGB(int r, int g, int b)
// {   
//     return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
// }

int	main(int ac, char **av)
{
	int		fd;
	t_win	vars;
	char	**p_line;
	char	**m_line;

	// atexit(f);
	if (ac == 2)
	{
		if (av[1][ft_strlen(av[1]) - 1] != 'b' || av[1][ft_strlen(av[1])
			- 2] != 'u' || av[1][ft_strlen(av[1]) - 3] != 'c'
			|| av[1][ft_strlen(av[1]) - 4] != '.')
			error_msg();
		vars.f_color = -1;
		vars.c_color = -1;
		fd = open(av[1], O_RDONLY);
		p_line = params_line(fd);
		parse_params(p_line, &vars);
		m_line = map_line(fd);
		check_other_char(m_line);
		check_surroundings(m_line);
		clean_map(m_line);
		vars.map = m_line;
		// printf("%lu\n", convertRGB(255, 255, 255));
		// exit (0);
		printf("\33[1;32mGOOD\33[0m\n");
		init(&vars);
		start_game(&vars, vars.data);
		mlx_loop(vars.mlx);
		close(fd);
		return (0);
	}
	else
		error_msg();
}
