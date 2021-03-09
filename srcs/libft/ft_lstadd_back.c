/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:28:49 by bhatches          #+#    #+#             */
/*   Updated: 2020/11/11 19:46:45 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*p;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	p = *lst;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = new;
}
