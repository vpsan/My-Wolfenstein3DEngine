/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 17:44:50 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/15 12:57:28 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t size)
{
	char		*ptr_dst;
	const char	*ptr_src;

	if (src == NULL && dst == NULL)
	{
		return (NULL);
	}
	ptr_dst = (char*)dst;
	ptr_src = (const char*)src;
	while (size != 0)
	{
		*ptr_dst = *ptr_src;
		ptr_dst++;
		ptr_src++;
		size--;
	}
	return (dst);
}
