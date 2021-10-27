/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarkas <nfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:39:33 by nfarkas           #+#    #+#             */
/*   Updated: 2021/10/13 18:39:33 by nfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define	MAX 9223372036854775807

static int	ft_isspace(char z)
{
	while (z == ' ' || z == '\n' || z == '\t'
		|| z == '\v' || z == '\f' || z == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					s;
	unsigned long long	res;

	i = 0;
	s = 1;
	res = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	if ((res > MAX || (res == MAX && str[i] - '0' > 7)) && s == 1)
		return (-1);
	if ((res > MAX || (res == MAX && str[i] - '0' > 7)) && s == -1)
		return (0);
	return (res * s);
}
