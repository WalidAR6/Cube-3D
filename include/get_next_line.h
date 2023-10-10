/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharib <aharib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:35:47 by waraissi          #+#    #+#             */
/*   Updated: 2023/10/10 20:55:36 by aharib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "cube.h"
# include "libft.h"

int		is_newline(char *str);
int		get_index(char	*str);
char	*before_newline(char *str);
char	*after_newline(char *str);
char	*get_next_line(int fd);

#endif