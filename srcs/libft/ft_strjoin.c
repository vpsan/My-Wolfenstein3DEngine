/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:15:49 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/19 13:53:46 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*malloc_s(char const *s1, char const *s2)
{
	char	*s;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 == NULL)
		s1_len = 0;
	else
		s1_len = ft_strlen(s1);
	if (s2 == NULL)
		s2_len = 0;
	else
		s2_len = ft_strlen(s2);
	s = (char *)malloc((s1_len + s2_len) * sizeof(char) + 1);
	return (s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*s;
	char		*buf;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	s = malloc_s(s1, s2);
	if (s == NULL)
	{
		return (NULL);
	}
	buf = s;
	while (s1 != NULL && *s1 != '\0')
	{
		*s++ = *s1++;
	}
	while (s2 != NULL && *s2 != '\0')
	{
		*s++ = *s2++;
	}
	*s = '\0';
	return (buf);
}
