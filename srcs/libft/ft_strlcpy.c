/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:42:58 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/15 12:57:28 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t dst_len)
{
	size_t src_len;

	if (dst == NULL || src == NULL)
	{
		return (0);
	}
	if (dst_len == 0)
	{
		return (ft_strlen(src));
	}
	src_len = ft_strlen(src);
	if (src_len < dst_len - 1)
	{
		ft_memcpy(dst, src, src_len + 1);
	}
	else if (dst_len != 0)
	{
		ft_memcpy(dst, src, dst_len - 1);
		dst[dst_len - 1] = '\0';
	}
	return (src_len);
}
