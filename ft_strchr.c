/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:07:10 by anarama           #+#    #+#             */
/*   Updated: 2024/04/04 14:48:22 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*chr_address;

	chr_address = NULL;
	while (*str)
	{
		if (*str == c)
		{
			chr_address = (char *)str;
			return (chr_address);
		}
		str++;
	}
	if (c == '\0')
		chr_address = (char *)str;
	return (chr_address);
}
