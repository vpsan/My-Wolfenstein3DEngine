/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:54:25 by bhatches          #+#    #+#             */
/*   Updated: 2020/11/11 23:44:11 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int value)
{
	int		len;
	int		i;
	char	*buf;

	len = ft_strlen(str);
	buf = NULL;
	i = 0;
	while (i < len)
	{
		if (*str == (char)value)
		{
			buf = (char*)str;
		}
		str++;
		i++;
	}
	if ((char)value == '\0')
	{
		return ((char*)str);
	}
	return (buf);
}
