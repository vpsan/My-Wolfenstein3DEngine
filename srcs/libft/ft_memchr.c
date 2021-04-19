/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:24:32 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/19 13:46:49 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int value, size_t size)
{
	unsigned char	*ptr_arr;

	ptr_arr = (unsigned char *)arr;
	while (size--)
	{
		if (*ptr_arr != (unsigned char)value)
		{
			ptr_arr++;
		}
		else
		{
			return (ptr_arr);
		}
	}
	return (NULL);
}
