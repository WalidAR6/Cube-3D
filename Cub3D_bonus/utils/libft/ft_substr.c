/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharib <aharib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:36:58 by waraissi          #+#    #+#             */
/*   Updated: 2023/10/13 04:05:21 by aharib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*p;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s) - start;
	p = malloc((len + 1) * sizeof(char));
	if (!p)
		return (0);
	while (!white_spaces(s[start]))
		start++;
	while (s[i] && i < len)
	{
		p[i++] = s[start++];
	}
	p[i] = '\0';
	return (p);
}
