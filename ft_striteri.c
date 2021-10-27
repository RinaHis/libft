/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:19:33 by nfarkas           #+#    #+#             */
/*   Updated: 2021/10/20 15:19:51 by nfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//static void ft_striteri_helper(char *s, unsigned int i, void (*f)(unsigned int, char *))
//{
//	if (*s)
//	{
//		f (i,s);
//		ft_striteri_helper(s + 1, i + 1, f);
//	}
//}
//
//void ft_striteri(char *s, void(*f)(unsigned int, char  *))
//{
//	ft_striteri_helper(s, o, f);
//}

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}