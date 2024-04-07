/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 16:07:22 by anarama           #+#    #+#             */
/*   Updated: 2024/04/07 13:54:11 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	helper_count_words(char const *s, char c)
{
	int	count_words;

	count_words = 0;
	if (*s != c && *s != '\0')
		count_words++;
	while (*s)
	{
		if (*s == c && *(s + 1) != c && *(s + 1) != '\0')
			count_words++;
		s++;
	}
	return (count_words);
}

static	int	helper_len_substr(const char *s, char c)
{
	int	i;

	i = 0;
	while (*s != c)
	{
		i++;
		s++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		count_words;
	char	**temp_arr;

	if (s == NULL)
		return (NULL);
	count_words = helper_count_words(s, c);
	arr = (char **)malloc(sizeof(char *) * (count_words + 1));
	if (!arr)
		return (NULL);
	temp_arr = arr;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != '\0')
		{
			*arr = ft_substr(s, 0, helper_len_substr(s, c));
			arr++;
		}
		while (*s != c && *s)
			s++;
	}
	*arr = NULL;
	return (temp_arr);
}
