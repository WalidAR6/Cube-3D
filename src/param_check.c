/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharib <aharib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:43:36 by aharib            #+#    #+#             */
/*   Updated: 2023/09/19 17:39:59 by aharib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

void	check_duplicate(char **param)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	while (param[i])
	{
		while (param[j])
		{
			if (ft_strcmp(param[i], param[j]) == 0)
			{
				write(2, "ERROR in duplicate !\n", 22);
				exit(1);
			}
			j++;
		}
		i++;
		j = i + 1;
	}
}

void	check_params(char *param, char *value)
{
	if ((param[0] == 'N' && param[1] == 'O' && param[2] == '\0')
		|| (param[0] == 'S' && param[1] == 'D' && param[2] == '\0')
		|| (param[0] == 'W' && param[1] == 'E' && param[2] == '\0')
		|| (param[0] == 'E' && param[1] == 'A' && param[2] == '\0'))
	{
		check_param_value(value, 2);
		return ;
	}
	else if ((param[0] == 'F' && param[1] == '\0') || (param[0] == 'C'
			&& param[1] == '\0'))
	{
		check_param_value(value, 1);
		return ;
	}
	else
	{
		write(2, "ERROR in directions or (F or c)!\n", 33);
		exit(1);
	}
}

void	check_length(char **param)
{
	if (ft_strlen(param[0]) == 2 || ft_strlen(param[0]) == 1)
		check_params(param[0], param[1]);
	else
	{
		write(2, "ERROR in params length !\n", 25);
		exit(1);
	}
}

void	parse_params(char **p_line)
{
	char	**tmp;
	char	**tmp1;
	int		i;

	i = 0;
	tmp = malloc(sizeof(char *) * 7);
	while (p_line[i])
	{
		tmp1 = ft_split(p_line[i], ' ');
		printf("-->[%s]\n", tmp1[0]);
		check_length(tmp1);
		tmp[i] = tmp1[0];
		i++;
	}
	tmp[i] = NULL;
	check_duplicate(tmp);
}

char	**params_line(int fd)
{
	char	*line;
	char	*tmp_line;
	char	**p_line;
	int		n;

	n = 0;
	line = ft_strdup("");
	tmp_line = NULL;
	while (1)
	{
		tmp_line = get_next_line(fd);
		if (tmp_line == NULL || n == 6)
			break ;
		if (check_empty_line(tmp_line) == 1)
		{
			line = ft_strjoin(line, tmp_line);
			n++;
		}
	}
	p_line = ft_split(line, '\n');
	return (p_line);
}
