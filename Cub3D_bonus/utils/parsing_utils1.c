/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharib <aharib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 21:48:34 by aharib            #+#    #+#             */
/*   Updated: 2023/10/13 03:29:39 by aharib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

int	white_spaces(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (0);
	return (1);
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

int	surround(char c)
{
	if (c != 'N'
		&& c != 'S' && c != 'E'
		&& c != 'W' && c != '1'
		&& c != '0')
		return (0);
	return (1);
}
