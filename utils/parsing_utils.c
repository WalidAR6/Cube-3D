/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharib <aharib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:44:24 by aharib            #+#    #+#             */
/*   Updated: 2023/09/27 02:08:49 by aharib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

int	ft_doublen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		check_empty_line(char *line)
{
	if (line[0] == '\n')
		return (0);
	return (1);
}


void	check_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			write(2, "ERROR in FC value (not a number) !\n", 35);
			exit(1);
		}
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