/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharib <aharib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:44:24 by aharib            #+#    #+#             */
/*   Updated: 2023/10/13 23:02:19 by aharib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

char	**parsing(t_win *vars, int fd)
{
	vars->parse->p_line = params_line(fd);
	parse_params(vars->parse->p_line, vars);
	vars->parse->m_line = map_line(fd);
	if (!check_tabulation(vars->parse->m_line))
		error_msg();
	check_other_char(vars->parse->m_line);
	check_surroundings(vars->parse->m_line);
	clean_map(vars->parse->m_line);
	return (vars->parse->m_line);
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
