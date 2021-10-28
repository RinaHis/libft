/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarkas <nfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 03:08:10 by nfarkas           #+#    #+#             */
/*   Updated: 2021/10/15 03:08:11 by nfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	i = start;
	j = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!(new_str))
		return (0);
	while (i < ft_strlen(s) && j < len)
		new_str[j++] = s[i++];
	new_str[j] = '\0';
	return (new_str);
}
