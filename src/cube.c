/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharib <aharib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:14:04 by waraissi          #+#    #+#             */
/*   Updated: 2023/09/27 02:53:17 by aharib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

void	check_surroundings(char **m_line)
{
	int	i;
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
				if (j == 0 || j == ft_strlen(m_line[i]) - 1
					|| i == 0 || i == ft_doublen(m_line) - 1
					|| m_line[i + 1][j] == '&' || m_line[i - 1][j] == '&'
					|| m_line[i][j - 1] == '&' || m_line[i][j + 1] == '&')
				{
					write (1, "ERROR in map file (kayna chi t9ba)\n", 35);
					exit (1);
				}
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

	i = 0;
	n = 0;
	while (m_line[i])
	{
		j = 0;
		while (m_line[i][j])
		{
			if (m_line[i][j] == 'N' || m_line[i][j] == 'S'
				|| m_line[i][j] == 'E' || m_line[i][j] == 'W' )
				n++;				
			if ((m_line[i][j] != '0' && m_line[i][j] != '1'
				&& m_line[i][j] != 'N' && m_line[i][j] != 'S'
				&& m_line[i][j] != 'E' && m_line[i][j] != 'W')
				|| n > 1)
			{
					write (1, "ERROR in map file (found another char)\n", 40);
					exit (1);
			}
			else if (white_spaces(m_line[i][j]) == 0)
				m_line[i][j] = '&';
			j++;
		}
		i++;
	}
	if (n == 0)
	{
		write (1, "ERROR in map file (no player)\n", 30);
		exit (1);
	}
}

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
		if (tmp_line == NULL || check_empty_line(tmp_line) == 0)
			break ;
		// if (check_empty_line(tmp_line) == 1)
			line = ft_strjoin(line, tmp_line);
	}
	while (1)
	{
		tmp_line = get_next_line(fd);
		if (tmp_line == NULL)
			break ;
		if (check_empty_line(tmp_line) == 1)
		{
			write (1, "ERROR in map file (chkadir talf hna)\n", 40);
			exit (1);
		}
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
		check_other_char(m_line);
		check_surroundings(m_line);
		int i = 0;
		while (m_line[i])
		{
			printf("[%s]\n", m_line[i]);
			i++;
		}
		printf("\033[32mkhdama hh \033[0m\n");
		exit (1);
		init(&vars);
		start_game(&vars, vars.data);
		mlx_loop(vars.mlx);
		return (0);
	}
	else 
	{
		printf("\033[31mmakhdamach hh \033[0m\n");
	}
}