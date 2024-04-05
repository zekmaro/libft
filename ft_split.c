/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 16:07:22 by anarama           #+#    #+#             */
/*   Updated: 2024/04/05 19:17:37 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int helper_count_words(char const *s, char c)
{
    int  count_words;

    count_words = 0;
    if (*s != c)
        count_words++;
    while (*s)
    {
        if (*s == c && *(s + 1) != c && *(s + 1) != '\0')
            count_words++;
        s++;
    }
    return (count_words);
}

char	*helper_strdup(const char *s)
{
	int		len_s;
	char	*dup_s;
	char	*temp_s;
	char	*temp_dup_s;

	len_s = 0;
	temp_s = (char *)s;
    printf("%s\n", s);
	while (*s)
	{
		len_s++;
		s++;
	}
	s = temp_s;
	dup_s = (char *)malloc(sizeof(char) * len_s + 1);
	if (!dup_s)
		return (NULL);
	temp_dup_s = dup_s;
	while (*s)
		*dup_s++ = *s++;
	*dup_s = '\0';
	return (temp_dup_s);
}

void    helper_terminate_strings(char *str, char c)
{
    while(*str)
    {
        if (*str == c)
            *str = '\0';
        str++;
    }
}

char **ft_split(char const *s, char c)
{
    int  count_words;
    char **arr;
    char **temp_arr;

    if (s == NULL)
        return (NULL);
    count_words = helper_count_words(s, c);
    arr = (char **)malloc(sizeof(char *) * count_words + 1);
    if (!arr)
        return (NULL);
    temp_arr = arr;
    if (*s != c)
    {
        *arr = helper_strdup(s);    
        helper_terminate_strings(*arr, c);
        arr++;
    }
    while (*s)
    {
        if (*s == c && *(s + 1) != c && *(s + 1) != '\0')
        {
            *arr = helper_strdup((s + 1));
            helper_terminate_strings(*arr, c);
            arr++;
        }
        s++;
    }
    arr = NULL;
    return (temp_arr);
}


int main(void)
{
    char str[] = "olol     olol          ollo      ";
    char **arr;

    arr = ft_split(str, ' ');
    while(*arr)
    {
        printf("%s\n", *arr);
        arr++;
    }
}
