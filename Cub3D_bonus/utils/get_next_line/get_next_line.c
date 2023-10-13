/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharib <aharib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:34:50 by waraissi          #+#    #+#             */
/*   Updated: 2023/10/10 19:48:11 by aharib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"

int	get_index(char	*str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*before_newline(char *str)
{
	int		i;
	char	*p;

	i = 0;
	if (!str[i])
		return (NULL);
	p = malloc(sizeof(char) * get_index(str) + 1);
	if (!p)
		return (NULL);
	while (str[i] && str[i] != '\n')
	{
		p[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		p[i++] = '\n';
	p[i] = 0;
	return (p);
}

char	*after_newline(char *str)
{
	int		i;
	size_t	j;
	char	*s;

	i = 0;
	j = get_index(str);
	if (j == ft_strlen(str))
		return (free(str), NULL);
	s = malloc(ft_strlen(str) - j + 1);
	if (!s)
		return (NULL);
	while (str[j])
		s[i++] = str[j++];
	s[i] = '\0';
	return (free(str), str = NULL, s);
}

int	is_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buffer;
	char		*line;
	ssize_t		i;

	i = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!backup)
		backup = ft_strdup("");
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (i && is_newline(backup) == 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
			return (free(backup), free(buffer), backup = NULL, NULL);
		buffer[i] = '\0';
		backup = ft_strjoin_gnl(backup, buffer);
	}
	line = before_newline(backup);
	backup = after_newline(backup);
	return (free(buffer), line);
}
