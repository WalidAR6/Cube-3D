/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharib <aharib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:44:24 by aharib            #+#    #+#             */
/*   Updated: 2023/10/12 00:12:33 by aharib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

char	**parsing(t_win *vars, int fd, char **p_line, char **m_line)
{
	p_line = params_line(fd);
	parse_params(p_line, vars);
	m_line = map_line(fd);
	check_other_char(m_line);
	check_surroundings(m_line);
	clean_map(m_line);
	return (m_line);
}

void	ft_freedbl(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	error_msg(void)
{
	write(2, "\033[31m", 5);
	write(2, "ERROR !!!\n", 10);
	write(2, "\033[0m", 4);
	exit(1);
}

int	ft_doublen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (white_spaces(line[i]))
			return (1);
		i++;
	}
	return (0);
}

void	check_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && white_spaces(str[i]))
			error_msg();
		else
			i++;
	}
}

int	white_spaces(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (0);
	return (1);
}

unsigned int	get_pixel(t_data *data, int x, int y)
{
	char	*texture;

	texture = data->addr + (y * data->line_length + x * (data->bits_per_pixel
				/ 8));
	return (*(unsigned int *)texture);
}

int	set_colors(int r, int g, int b)
{
	int	color;

	color = 0;
	color += r << 16;
	color += g << 8;
	color += b;
	return (color);
}

void	count_commas(char *value)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (value[i])
	{
		if (value[i] == ',')
			n++;
		i++;
	}
	if (n != 2)
		error_msg();
}
