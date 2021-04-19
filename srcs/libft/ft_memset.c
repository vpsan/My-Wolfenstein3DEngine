/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:46:43 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/19 13:47:39 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int value, size_t size)
{
	unsigned char	*ptr_dst;

	ptr_dst = (unsigned char *)dst;
	while (size != 0)
	{
		*ptr_dst = (unsigned char)value;
		size = size - 1;
		ptr_dst++;
	}
	return (dst);
}
