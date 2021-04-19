/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 12:10:14 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/19 11:11:50 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t		s1_len;
	char		*s_copy;

	s1_len = ft_strlen(s1);
	s_copy = malloc(s1_len * sizeof(char) + 1);
	if (s_copy == NULL)
	{
		return (NULL);
	}
	ft_memcpy(s_copy, s1, s1_len);
	*(s_copy + s1_len) = '\0';
	return (s_copy);
}
