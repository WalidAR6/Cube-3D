/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_value_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:46:57 by aharib            #+#    #+#             */
/*   Updated: 2023/10/05 10:24:30 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

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

int	set_colors(int r, int g, int b)
{
	int color;
	
	color  = 0;
	color += r << 16;
	color += g << 8;
	color += b;
	return (color);
}

void	check_fc_value(char *value, t_win *vars, int n)
{
	char	**tmp;
	int		i;
	
	count_commas(value);
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
	if (n == 1)
		vars->f_color = set_colors(ft_atoi(tmp[0]), ft_atoi(tmp[1]), ft_atoi(tmp[2]));
	else
		vars->c_color = set_colors(ft_atoi(tmp[0]), ft_atoi(tmp[1]), ft_atoi(tmp[2]));
	printf("f : %d\n", vars->f_color);
	printf("c : %d\n", vars->c_color);
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

void	check_param_value(char *param, char *value, int n, t_win *vars)
{
	if (n == 1)
	{
		if (param[0] == 'F' && param[1] == '\0')
			check_fc_value(value, vars, 1);
		else if (param[0] == 'C' && param[1] == '\0')
			check_fc_value(value, vars, 2);
	}
	else if (n == 2)
		check_direc_value(value);
	else
		return ;
}
