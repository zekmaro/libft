/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:45:29 by anarama           #+#    #+#             */
/*   Updated: 2024/04/06 19:21:42 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*temp_dest;
	char		*temp_src;

	if ((dest == NULL && src == NULL) && n > 0)
		return (NULL);
	temp_dest = (char *)dest;
	temp_src = (char *)src;
	while (n--)
		*temp_dest++ = *temp_src++;
	return (dest);
}
