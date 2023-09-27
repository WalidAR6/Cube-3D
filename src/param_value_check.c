/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_value_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharib <aharib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:46:57 by aharib            #+#    #+#             */
/*   Updated: 2023/09/26 19:04:25 by aharib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

void	check_fc_value(char *value)
{
	char	**tmp;
	int		i;

	printf("value = %s\n", value);
	tmp = ft_split(value, ',');
	i = 0;
	if (ft_doublen(tmp) != 3)
	{
		printf("[%d]\n", ft_doublen(tmp));
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

void	check_direc_value(char *value)
{
	int	fd;

	fd = open(value, O_RDONLY);
	if (fd == -1)
	{
		write(2, "ERROR in direction value file !\n", 32);
		exit(1);		
	}
	else if (value[ft_strlen(value) - 1] != 'm'
		|| value[ft_strlen(value) - 2] != 'p'
		|| value[ft_strlen(value) - 3] != 'x'
		|| value[ft_strlen(value) - 4] != '.')
	{
		close (fd);
		write(2, "ERROR in direction value file !(makisalich b xpm)\n", 50);
		exit(1);		
		
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
