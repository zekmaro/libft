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
	char			*last_addr_c;
	unsigned char	unsigned_c;

	last_addr_c = NULL;
	unsigned_c = (unsigned char)c;
	while (*str)
	{
		if ((unsigned char)(*str) == unsigned_c)
			last_addr_c = (char *)str;
		str++;
	}
	if (unsigned_c == '\0')
		return ((char *)str);
	return (last_addr_c);
}
