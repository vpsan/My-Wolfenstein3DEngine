/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 12:19:21 by bhatches          #+#    #+#             */
/*   Updated: 2020/11/11 19:47:07 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list	*p;

	p = (t_list*)malloc(1 * sizeof(t_list));
	if (p == NULL)
	{
		return (NULL);
	}
	p->content = content;
	p->next = NULL;
	return (p);
}
