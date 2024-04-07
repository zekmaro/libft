/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 10:05:20 by anarama           #+#    #+#             */
/*   Updated: 2024/04/07 14:29:23 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	helper_strlen(char const *s)
{
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	char	*temp_substr;

	if (s == NULL || start >= helper_strlen(s) || len == 0)
	{
		substr = (char *)malloc(1);
		if (substr)
			*substr = '\0';
		return (substr);
	}
	substr = (char *)malloc(sizeof(char) * len + 1);
	if (!substr)
		return (NULL);
	temp_substr = substr;
	s += start;
	while (len && *s)
	{
		*substr++ = *s++;
		len--;
	}
	*substr = '\0';
	return (temp_substr);
}
