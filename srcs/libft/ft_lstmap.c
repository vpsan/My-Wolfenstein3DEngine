/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 20:17:25 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/20 18:29:22 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_begin;
	t_list	*p;

	if (lst == NULL)
		return (NULL);
	new_begin = ft_lstnew(f(lst->content));
	if (new_begin == NULL)
	{
		return (NULL);
	}
	p = new_begin;
	lst = lst->next;
	while (lst != NULL)
	{
		p = ft_lstnew(f(lst->content));
		if (p == NULL)
		{
			ft_lstclear(&new_begin, del);
			return (NULL);
		}
		ft_lstadd_back(&new_begin, p);
		lst = lst->next;
	}
	return (new_begin);
}
