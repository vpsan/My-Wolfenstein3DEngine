/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 12:27:24 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/19 13:45:12 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*buf;

	if (*lst == NULL)
	{
		*lst = new;
	}
	else if (new == NULL)
	{
		return ;
	}
	else
	{
		buf = *lst;
		*lst = new;
		new->next = buf;
	}
}
