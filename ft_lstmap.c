/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 12:39:03 by anarama           #+#    #+#             */
/*   Updated: 2024/04/08 17:20:52 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*head_new_lst;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new_lst = (t_list *)malloc(sizeof(t_list));
	if (!new_lst)
		return (NULL);
	head_new_lst = new_lst;
	while (lst != NULL)
	{
		new_lst->content = f(lst->content);
		new_lst->next = lst->next;
		del(lst->content);
		free(lst);
		lst = lst->content;
	}
	return (head_new_lst);
}
