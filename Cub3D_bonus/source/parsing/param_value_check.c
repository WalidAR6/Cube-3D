/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_value_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharib <aharib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:46:57 by aharib            #+#    #+#             */
/*   Updated: 2023/10/13 03:03:06 by aharib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

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
		vars->f_color = set_colors(ft_atoi(tmp[0]), ft_atoi(tmp[1]),
				ft_atoi(tmp[2]));
	else
		vars->c_color = set_colors(ft_atoi(tmp[0]), ft_atoi(tmp[1]),
				ft_atoi(tmp[2]));
	ft_freedbl(tmp);
}

void	check_direc_value(char *ref, char *value, t_win *vars)
{
	int	fd;

	fd = open(value, O_RDONLY);
	if (fd == -1)
		error_msg();
	if (ref[0] == 'N' && ref[1] == 'O')
		vars->walls->north->path = ft_strdup(value);
	else if (ref[0] == 'S' && ref[1] == 'O')
		vars->walls->south->path = ft_strdup(value);
	else if (ref[0] == 'W' && ref[1] == 'E')
		vars->walls->west->path = ft_strdup(value);
	else if (ref[0] == 'E' && ref[1] == 'A')
		vars->walls->east->path = ft_strdup(value);
	close(fd);
}

void	check_param_value(char *ref, char *value, int n, t_win *vars)
{
	if (n == 1)
	{
		if (ref[0] == 'F' && ref[1] == '\0')
			check_fc_value(value, vars, 1);
		else if (ref[0] == 'C' && ref[1] == '\0')
			check_fc_value(value, vars, 2);
	}
	else if (n == 2)
		check_direc_value(ref, value, vars);
	else
		return ;
}
