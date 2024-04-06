#include <stdio.h>
#include "libft.h"

static void fill_array(char *str, int n)
{
    if (n >= 10)
        fill_array(str - 1, n / 10);
    *str = (n % 10) + '0';
}

char *ft_itoa(int n)
{
    char    *str;
    int     len_n;
    int     temp_n;
    char    *temp_str;

    temp_n = n;
    len_n = 0;
    if (n == 0)
        len_n = 1;
    while(n)
    {
        len_n += 1;
        n /= 10;
    }
    str = (char *)malloc(sizeof(char) * len_n + 2);
    if (!str)
        return (NULL);
    temp_str = str;
    if (temp_n < 0)
    {
        *str++ = '-';
        temp_n *= -1;
    }
    fill_array(str + len_n - 1 , temp_n);
    *(str + len_n) = '\0';
    return (temp_str);
}

int main(void)
{
    char *str;
    int n =-2147483648;

    str = ft_itoa(n);
    printf("%s\n", str);
}