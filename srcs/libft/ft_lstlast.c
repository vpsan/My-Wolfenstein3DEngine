/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:06:08 by bhatches          #+#    #+#             */
/*   Updated: 2021/03/31 23:05:57 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstlast(t_list *lst)
{
	t_list	*p;

	if (lst == NULL)
	{
		return (NULL);
	}
	p = lst;
	while (p->next != NULL)
	{
		p = p->next;
	}
	return (p);
}
