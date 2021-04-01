/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 13:24:08 by bhatches          #+#    #+#             */
/*   Updated: 2021/03/31 23:05:57 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t size)
{
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;

	if (src == NULL && dst == NULL)
	{
		return (NULL);
	}
	ptr_dst = (unsigned char*)dst;
	ptr_src = (unsigned char*)src;
	if (ptr_dst < ptr_src)
	{
		while (size--)
		{
			*ptr_dst++ = *ptr_src++;
		}
	}
	if (ptr_dst >= ptr_src)
	{
		while (size--)
		{
			ptr_dst[size] = ptr_src[size];
		}
	}
	return (dst);
}
