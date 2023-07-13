/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:17:59 by waraissi          #+#    #+#             */
/*   Updated: 2023/07/13 19:13:07 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "cube.h"

char	**ft_split(char *s, char c);
int		ft_atoi(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *str);
size_t	ft_strlcpy(char *dst, char *src, size_t n);
size_t	ft_strlen(char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif