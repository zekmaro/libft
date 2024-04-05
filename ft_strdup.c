/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:30:43 by anarama           #+#    #+#             */
/*   Updated: 2024/04/04 10:57:34 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len_s;
	char	*dup_s;
	char	*temp_s;
	char	*temp_dup_s;

	len_s = 0;
	temp_s = (char *)s;
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
