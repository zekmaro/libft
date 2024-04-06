/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 16:07:22 by anarama           #+#    #+#             */
/*   Updated: 2024/04/06 21:20:49 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int  helper_count_words(char const *s, char c)
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

static void helper_terminate_strings(char *str, char c)
{
    while(*str)
    {
        if (*str == c)
            *str = '\0';
        str++;
    }
}

char    **ft_split(char const *s, char c)
{
    int  count_words;
    char **arr;
    char **temp_arr;

    if (s == NULL)
        return (NULL);
    count_words = helper_count_words(s, c);
    printf("%d", count_words);
    arr = (char **)malloc(sizeof(char *) * count_words + 1);
    if (!arr)
        return (NULL);
    temp_arr = arr;
    if (*s != c)
    {
        *arr = ft_strdup(s);    
        helper_terminate_strings(*arr, c);
        arr++;
    }
    while (*s)
    {
        if (*s == c && *(s + 1) != c && *(s + 1) != '\0')
        {
            *arr = ft_strdup((s + 1));
            helper_terminate_strings(*arr, c);
            arr++;
        }
        s++;
    }
    arr = NULL;
    return (temp_arr);
}

// int main(void)
// {
//     char *s = "\0aa\0bbb";
//     char **result = ft_split(s, '\0');

//     while (*result)
//     {
//         printf("%s\n", *result);
//         result++;
//     }
// }