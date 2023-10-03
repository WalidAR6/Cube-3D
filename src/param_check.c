/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharib <aharib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:43:36 by aharib            #+#    #+#             */
/*   Updated: 2023/10/03 03:01:00 by aharib           ###   ########.fr       */
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
				error_msg();
			j++;
		}
		i++;
		j = i + 1;
	}
}

void	check_params(char *param)
{
	if ((param[0] == 'N' && param[1] == 'O' && param[2] == '\0')
		|| (param[0] == 'S' && param[1] == 'O' && param[2] == '\0')
		|| (param[0] == 'W' && param[1] == 'E' && param[2] == '\0')
		|| (param[0] == 'E' && param[1] == 'A' && param[2] == '\0'))
		return ;
	else if ((param[0] == 'F' && param[1] == '\0') || (param[0] == 'C'
			&& param[1] == '\0'))
		return ;
	else
		error_msg();
}

int	check_length(char *param)
{
	if (ft_strlen(param) == 2)
	{
		check_params(param);
		return (2);
	}
	else if (ft_strlen(param) == 1)
	{
		check_params(param);
		return (1);
	}
	else
		error_msg();
	return (0);
}

void	parse_params(char **p_line)
{
	char	**tmp;
	char	**tmp1;
	int		i;
	int		j;
	int		len;

	i = -1;
	j = 1;
	tmp = malloc(sizeof(char *) * 7);
	while (p_line[++i])
	{
		tmp1 = ft_split(p_line[i], ' ');
		len = check_length(tmp1[0]);
		if (tmp1[2] != NULL)
		{
			while (tmp1[++j])
			{
				tmp1[1] = ft_strjoin(tmp1[1], tmp1[j]);
				free(tmp1[j]);
			}
			j = 1;
		}
		check_param_value(tmp1[1], len);
		free(tmp1[1]);
		tmp[i] = tmp1[0];
		free(tmp1);
	}
	tmp[i] = NULL;
	check_duplicate(tmp);
	ft_freedbl(tmp);
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
		free(tmp_line);
	}
	p_line = ft_split(line, '\n');
	free(line);
	return (p_line);
}
