/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:49:48 by anarama           #+#    #+#             */
/*   Updated: 2024/04/05 16:04:36 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int helper_strlen(char const *s)
{
	unsigned int i;
	
	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

static char *get_start(char const *s1, char const *set)
{
    char    *temp_set;
    int     in_set;

    while (*s1)
    {
        in_set = 0;
        temp_set = (char *)set;
        while (*temp_set)
        {
            if (*temp_set == *s1)
                in_set = 1;
            temp_set++;
        }
        if (!in_set)
            return ((char *)s1);
        s1++;
    }
    return (NULL);
}

static char *get_end(char const *s1, char const *set, size_t len_s1)
{
    char    *temp_set;
    int     in_set;

    len_s1--;
    while (len_s1)
    {
        in_set = 0;
        temp_set = (char *)set;
        while (*temp_set)
        {
            if (*temp_set == *(s1 + len_s1))
                in_set = 1;
            temp_set++;
        }
        if (!in_set)
            return ((char *)(s1 + len_s1));
        len_s1--;
    }
    return (NULL);
}

char    *ft_strtrim(char const *s1, char const *set)
{
    char            *trim_s1;
    char            *temp_trim_s1;
    unsigned int    len_s1;
    char            *start;
    char            *end;

    if (s1 == NULL || set == NULL)
        return (NULL);
    len_s1 = helper_strlen(s1);
    start = get_start(s1, set);
    end = get_end(s1, set, len_s1);
    if (start == NULL || end == NULL)
        return (NULL);
    trim_s1 = (char *)malloc(sizeof(char) * len_s1 + 1);
    if (!trim_s1)
        return (NULL);
    temp_trim_s1 = trim_s1;
    while (start != end)
        *trim_s1++ = *start++;
    *trim_s1++ = *start++;
    *trim_s1 = '\0';
    return (temp_trim_s1);
}
