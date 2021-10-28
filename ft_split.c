/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarkas <nfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 03:38:06 by nfarkas           #+#    #+#             */
/*   Updated: 2021/10/15 03:38:10 by nfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	word;
	int		trigger;

	word = 0;
	trigger = 1;
	while (*s)
	{
		if (*s != c && trigger)
		{
			trigger = 0;
			word++;
		}
		else if (*s == c)
			trigger = 1;
		s++;
	}
	return (word);
}

static void	word_dup(char **words, char const *s, char c, size_t arr_words)
{
	char	*ptr_c;

	while (*s && *s == c)
		s++;
	while (arr_words--)
	{
		ptr_c = ft_strchr(s, c);
		if (ptr_c != NULL)
		{
			*words = ft_substr(s, 0, ptr_c - s);
			while (*ptr_c && *ptr_c == c)
				ptr_c++;
			s = ptr_c;
		}
		else
			*words = ft_substr(s, 0, ft_strlen(s) + 1);
		words++;
	}
	*words = NULL;
}

char	**ft_split(char const *s, char c)
{
	size_t	index;
	char	**words;

	if (s == NULL)
		return (NULL);
	index = count_words(s, c);
	words = malloc(sizeof(char **) * (index + 1));
	if (words == NULL)
		return (NULL);
	word_dup(words, s, c, index);
	return (words);
}
