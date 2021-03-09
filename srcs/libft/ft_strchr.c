/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:42:38 by bhatches          #+#    #+#             */
/*   Updated: 2020/11/11 23:44:25 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int value)
{
	int		len;
	int		i;

	len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		if (*str == (char)value)
		{
			return ((char*)str);
		}
		str++;
		i++;
	}
	if ((char)value == '\0')
	{
		return ((char*)str);
	}
	return (NULL);
}
