/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_value_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharib <aharib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:46:57 by aharib            #+#    #+#             */
/*   Updated: 2023/09/20 01:46:11 by aharib           ###   ########.fr       */
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
	{
		write(2, "ERROR in FC value 9lal !\n", 25);
		exit(1);
	}
	while (tmp[i])
	{
		check_digit(tmp[i]);
		if ((ft_atoi(tmp[i]) < 0 || ft_atoi(tmp[i]) > 255))
		{
			write(2, "ERROR in FC value !\n", 21);
			exit(1);
		}
		i++;
	}
}

void	check_param_value(char *value, int n)
{
	if (n == 1)
		check_fc_value(value);
	//else if (n == 2)
		//hta nswl ach ndir hna hh
	else
		return ;
}
