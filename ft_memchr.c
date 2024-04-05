/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:49:58 by anarama           #+#    #+#             */
/*   Updated: 2024/04/04 18:15:22 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*temp_str;

	temp_str = (unsigned char *)str;
	if (c == '\0')
	{
		while (*temp_str)
			temp_str++;
		return ((void *)temp_str);
	}
	while (*temp_str && n--)
	{
		if (*temp_str == (unsigned char)c)
			return ((void *)temp_str);
		temp_str++;
	}
	return (NULL);
}
