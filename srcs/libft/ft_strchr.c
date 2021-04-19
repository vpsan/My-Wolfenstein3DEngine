/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:42:38 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/19 13:48:27 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int value)
{
	while (*str != '\0')
	{
		if (*str == (char)value)
		{
			return ((char *)str);
		}
		str++;
	}
	if ((char)value == '\0')
	{
		return ((char *)str);
	}
	return (NULL);
}
