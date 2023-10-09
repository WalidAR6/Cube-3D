/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharib <aharib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:43:36 by aharib            #+#    #+#             */
/*   Updated: 2023/10/08 23:43:34 by aharib           ###   ########.fr       */
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
	if ((param[0] == 'N' && param[1] == 'O' && param[2] == ' ')
		|| (param[0] == 'S' && param[1] == 'O' && param[2] == ' ')
		|| (param[0] == 'W' && param[1] == 'E' && param[2] == ' ')
		|| (param[0] == 'E' && param[1] == 'A' && param[2] == ' '))
		return ;
	else if ((param[0] == 'F' && param[1] == ' ') || (param[0] == 'C'
			&& param[1] == ' '))
		return ;
	else
		error_msg();
}

int	check_length(char *param)
{
	int	i;

	i = 0;
	while (param[i] != '\0' && param[i] != ' ')
		i++;
	if (i == 1 || i == 2)
	{
		check_params(param);
		return (i);
	}
	else
		error_msg();
	return (0);
}

void	parse_params(char **p_line, t_win *vars)
{
	char	**ref;
	char	*value;
	int		i;
	int		j;
	int		len;

	(void)vars;
	i = -1;
	j = 0;
	value = NULL;
	ref = malloc(sizeof(char *) * 7);
	while (p_line[++i])
	{
		len = check_length(p_line[i]);
		ref[i] = ft_substr(p_line[i], 0, len);
		value = ft_substr(p_line[i], len + 1, ft_strlen(p_line[i]));
		check_param_value(ref[i], value, len, vars);
	}
	ref[i] = NULL;
	check_duplicate(ref);
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
