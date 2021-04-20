/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 19:18:57 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/20 18:29:22 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int value, size_t size)
{
	unsigned char		*ptr_dst;
	const unsigned char	*ptr_src;
	unsigned char		copy_value;

	if (src == NULL && dst == NULL)
	{
		return (NULL);
	}
	ptr_dst = (unsigned char *)dst;
	ptr_src = (const unsigned char *)src;
	copy_value = (unsigned char)value;
	while (size--)
	{
		if (*ptr_src == copy_value)
		{
			*ptr_dst = *ptr_src;
			ptr_dst++;
			return (ptr_dst);
		}
		*ptr_dst++ = *ptr_src++;
	}
	return (NULL);
}
