/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:31:05 by anarama           #+#    #+#             */
/*   Updated: 2024/04/04 14:48:37 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*chr_address;

	chr_address = NULL;
	while (*str)
	{
		if (*str == c)
			chr_address = (char *)str;
		str++;
	}
	if (c == '\0')
		chr_address = (char *)str;
	return (chr_address);
}
