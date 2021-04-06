/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:47:04 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/06 12:44:23 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t size)
{
	unsigned char	*ptr_str1;
	unsigned char	*ptr_str2;

	ptr_str1 = (unsigned char*)str1;
	ptr_str2 = (unsigned char*)str2;
	while (size--)
	{
		if (*ptr_str1 != *ptr_str2)
		{
			return (*ptr_str1 - *ptr_str2);
		}
		if (*ptr_str1 == '\0' && *ptr_str2 == '\0')
		{
			return (*ptr_str1 - *ptr_str2);
		}
		ptr_str1++;
		ptr_str2++;
	}
	return (0);
}
