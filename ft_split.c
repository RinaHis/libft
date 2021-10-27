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

//static int	count_words(const char *str, char c)
//{
//	int	i;
//	int	trigger;
//
//	i = 0;
//	trigger = 0;
//	while (*str)
//	{
//		if (*str != c && trigger == 0)
//		{
//			trigger = 1;
//			i++;
//		}
//		else if (*str == c)
//			trigger = 0;
//		str++;
//	}
//	return (i);
//}
//
//static char	*word_dup(const char *str, int start, int finish)
//{
//	char	*word;
//	int		i;
//
//	i = 0;
//	word = (char *)malloc((finish - start + 1) * sizeof(char));
//	if (!word)
//		return (word);
//	while (start < finish)
//		word[i++] = str[start++];
//	word[i] = '\0';
//	return (word);
//}
//
//static char **ft_dop(char *s, char c, int index, char **arr_words, size_t i)
//{
//	int j;
//
//	j = 0;
//	while (i <= ft_strlen(s))
//	{
//		if (s[i] != c && index < 0)
//			index = 1;
//		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
//		{
//			arr_words[j] = word_dup(s, index, i);
//			if (!arr_words[j])
//			{
//				while (j != 0)
//					free(arr_words[j-- - 1]);
//				free(arr_words);
//				return ((char **)0);
//			}
//			index = -1;
//			j++;
//		}
//		i++;
//	}
//	arr_words[j] = 0;
//	return (arr_words);
//}
//
//char	**ft_split(char const *s, char c)
//{
//	int		index;
//	char	**arr_words;
//	size_t 		i;
//
//	i = 0;
//	if (!s)
//		return (NULL);
//	arr_words = malloc((count_words(s, c) + 1) * sizeof(char *));
//	if (!s || !(arr_words))
//		return (0);
//	index = -1;
//	arr_words = ft_dop((char *)s, c, index, arr_words, i);
//	return (arr_words);
//}
static size_t	count_words(char const *s, char c)
{
	size_t	word_count;
	int		delim;

	word_count = 0;
	delim = 1;
	while (*s)
	{
		if (*s != c && delim)
		{
			delim = 0;
			word_count++;
		}
		else if (*s == c)
			delim = 1;
		s++;
	}
	return (word_count);
}

static void	make_words(char **words, char const *s, char c, size_t n_words)
{
	char	*ptr_c;

	while (*s && *s == c)
		s++;
	while (n_words--)
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
	size_t	num_words;
	char	**words;

	if (s == NULL)
		return (NULL);
	num_words = count_words(s, c);
	words = malloc(sizeof(char **) * (num_words + 1));
	if (words == NULL)
		return (NULL);
	make_words(words, s, c, num_words);
	return (words);
}