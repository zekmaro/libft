/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:53:23 by anarama           #+#    #+#             */
/*   Updated: 2024/04/04 12:24:44 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	helper_isalpha(int num)
{
	if ((num >= 65 && num <= 90) || (num >= 97 && num <= 122))
		return (1);
	return (0);
}

static int	helper_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_isalnum(int arg)
{
	if (!(helper_isalpha(arg)) && !(helper_isdigit(arg)))
		return (0);
	return (1);
}
