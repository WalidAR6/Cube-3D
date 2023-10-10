/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharib <aharib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:03:49 by aharib            #+#    #+#             */
/*   Updated: 2023/10/10 19:48:11 by aharib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	str_elmnts(int n)
{
	int	cnt;

	cnt = 1;
	if (n < 0)
	{
		n *= -1;
		cnt++;
	}
	while (n / 10 > 0)
	{
		n = n / 10;
		cnt++;
	}
	return (cnt);
}

char	*itoa_conditions(int nbr, int i, int result, char *itoa_str)
{
	if (nbr < 0)
	{
		itoa_str[0] = '-';
		nbr *= -1;
		while (i - 1)
		{
			result = nbr % 10;
			itoa_str[i - 1] = result + '0';
			nbr = nbr / 10;
			i--;
		}
		return (itoa_str);
	}
	else if (nbr == 0)
	{
		itoa_str[0] = '0';
	}
	while (i)
	{
		result = nbr % 10;
		itoa_str[i - 1] = result + '0';
		nbr = nbr / 10;
		i--;
	}
	return (itoa_str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		ne;
	int		res;

	res = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	ne = str_elmnts(n);
	str = (char *)malloc(sizeof(char) * (ne + 1));
	if (!str)
		return (NULL);
	str[ne] = '\0';
	return (itoa_conditions(n, ne, res, str));
}