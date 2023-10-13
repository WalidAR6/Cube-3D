/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharib <aharib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:01:49 by aharib            #+#    #+#             */
/*   Updated: 2023/10/13 03:11:07 by aharib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

int	check_surr1(char c)
{
	if (c != 'N'
		&& c != 'S' && c != 'E'
		&& c != 'W' && c != '1'
		&& c != '0')
		return (0);
	return (1);
}
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
					|| i == ft_doublen(m_line) - 1 || !check_surr1(m_line[i + 1][j])
					|| !check_surr1(m_line[i - 1][j]) || !check_surr1(m_line[i][j + 1])
					|| !check_surr1(m_line[i][j - 1]))
					error_msg();
			}
			j++;
		}
		i++;
	}
}

int	check_tabulation(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\t')
			return (0);
		i++;
	}
	return (1);
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
			if (!white_spaces(m_line[i][j]))
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
	int		n;

	n = 0;
	line = ft_strdup("");
	tmp_line = NULL;
	while (1)
	{
		tmp_line = get_next_line(fd);
		if (tmp_line == NULL)
			break ;
		if((n == 1 && check_empty_line(tmp_line) == 0) || !check_tabulation(tmp_line))
			error_msg();
		if(strchr(tmp_line, '1'))
			n = 1;
		line = ft_strjoin(line, tmp_line);
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
