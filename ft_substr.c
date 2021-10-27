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

//char	*ft_substr(char const *s, unsigned int start, size_t len)
//{
//	char	*new_str;
//	size_t	i;
//	size_t	j;
//
//	new_str = (char *)malloc(sizeof(char) * (len + 1));
//	if (!s || !(new_str))
//		return (0);
//	i = start;
//	j = 0;
//	while (i < ft_strlen(s) && j < len)
//		new_str[j++] = s[i++];
//	new_str[j] = '\0';
//	return (new_str);
//}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	char	*new_str;
	size_t	s_len;
	size_t	i;

	if (s == NULL)
		return (0);
	s_len = ft_strlen(s);
	if (s == NULL || s_len < start)
		return (ft_strdup(""));
	if (start + len < s_len)
		substr = (char *)malloc((len + 1) * sizeof(char));
	else
		substr = (char *)malloc((s_len - start + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	i = start;
	new_str = substr;
	while (i < (start + len) && *(s + i))
		*new_str++ = *(s + i++);
	*new_str = '\0';
	return (substr);
}