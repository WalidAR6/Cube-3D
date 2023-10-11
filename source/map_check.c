/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharib <aharib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:01:49 by aharib            #+#    #+#             */
/*   Updated: 2023/10/12 00:03:38 by aharib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

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
	}
	while (1)
	{
		tmp_line = get_next_line(fd);
		if (tmp_line == NULL)
			break ;
		if (check_empty_line(tmp_line) == 1)
			error_msg();
	}
	m_line = ft_split(line, '\n');
	return (m_line);
}

void	clean_map(char **m_line)
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
