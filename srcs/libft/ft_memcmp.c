/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:35:39 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/03 12:14:10 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *arr1, const void *arr2, size_t size)
{
	unsigned char	*ptr_arr1;
	unsigned char	*ptr_arr2;

	ptr_arr1 = (unsigned char*)arr1;
	ptr_arr2 = (unsigned char*)arr2;
	while (size--)
	{
		if (*ptr_arr1 != *ptr_arr2)
		{
			return (*ptr_arr1 - *ptr_arr2);
		}
		ptr_arr1++;
		ptr_arr2++;
	}
	return (0);
}
