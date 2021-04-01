/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:26:27 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/01 16:59:16 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	char	*buf;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		return (ft_strdup(""));
	}
	substr = (char *)malloc(len * sizeof(char) + 1);
	if (substr == NULL)
	{
		return (NULL);
	}
	buf = substr;
	while (len-- && s[start] != '\0')
	{
		*substr = s[start++];
		substr++;
	}
	*substr = '\0';
	return (buf);
}
