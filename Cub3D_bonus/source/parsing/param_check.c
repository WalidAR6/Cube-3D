/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharib <aharib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:43:36 by aharib            #+#    #+#             */
/*   Updated: 2023/10/13 22:29:07 by aharib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

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

void	check_params(char *ref)
{
	int	i;

	i = 0;
	while (!white_spaces(ref[i]))
		i++;
	if ((ref[i] == 'N' && ref[i + 1] == 'O' && !white_spaces(ref[i + 2]))
		|| (ref[i] == 'S' && ref[i + 1] == 'O' && !white_spaces(ref[i + 2]))
		|| (ref[i] == 'W' && ref[i + 1] == 'E' && !white_spaces(ref[i + 2]))
		|| (ref[i] == 'E' && ref[i + 1] == 'A' && !white_spaces(ref[i + 2])))
		return ;
	else if ((ref[i] == 'F' && !white_spaces(ref[i + 1])) || (ref[i] == 'C'
			&& !white_spaces(ref[i + 1])))
		return ;
	else
		error_msg();
}

int	check_length(char *param)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (!white_spaces(param[i]))
		i++;
	while (param[i] != '\0' && white_spaces(param[i]))
	{
		i++;
		len++;
	}
	if (len == 1 || len == 2)
	{
		check_params(param);
		return (len);
	}
	else
		error_msg();
	return (0);
}

void	parse_params(char **p_line, t_win *vars)
{
	int		i;
	int		j;
	int		len;

	i = -1;
	j = 0;
	if (!p_line || !p_line[0])
		error_msg();
	vars->parse->value = malloc(sizeof(char *) * 7);
	vars->parse->ref = malloc(sizeof(char *) * 7);
	if (!vars->parse->ref || !vars->parse->value)
		error_msg();
	while (p_line[++i])
	{
		len = check_length(p_line[i]);
		vars->parse->ref[i] = ft_substr(p_line[i], 0, len);
		vars->parse->value[i] = ft_substr(p_line[i],
				len + value_start(p_line[i]), ft_strlen(p_line[i]));
		check_param_value(vars->parse->ref[i],
			vars->parse->value[i], len, vars);
	}
	vars->parse->ref[i] = NULL;
	vars->parse->value[i] = NULL;
	check_duplicate(vars->parse->ref);
}

char	**params_line(int fd)
{
	char	*line;
	char	*tmp_line;
	char	**p_line;
	int		n;

	n = 0;
	line = NULL;
	tmp_line = NULL;
	while (1)
	{
		if (n < 6)
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
