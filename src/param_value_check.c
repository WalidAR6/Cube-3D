/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_value_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharib <aharib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:46:57 by aharib            #+#    #+#             */
/*   Updated: 2023/10/03 02:41:12 by aharib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

void	check_fc_value(char *value)
{
	char	**tmp;
	int		i;

	tmp = ft_split(value, ',');
	i = 0;
	if (ft_doublen(tmp) != 3)
		error_msg();
	while (tmp[i])
	{
		check_digit(tmp[i]);
		if ((ft_atoi(tmp[i]) < 0 || ft_atoi(tmp[i]) > 255))
			error_msg();
		i++;
	}
	ft_freedbl(tmp);
}

void	check_direc_value(char *value)
{
	int	fd;

	fd = open(value, O_RDONLY);
	if (fd == -1)
		error_msg();
	else if (value[ft_strlen(value) - 1] != 'm'
		|| value[ft_strlen(value) - 2] != 'p'
		|| value[ft_strlen(value) - 3] != 'x'
		|| value[ft_strlen(value) - 4] != '.')
	{
		close (fd);
		error_msg();
	}
	close (fd);
}

void	check_param_value(char *value, int n)
{
	if (n == 1)
		check_fc_value(value);
	else if (n == 2)
		check_direc_value(value);
	else
		return ;
}
