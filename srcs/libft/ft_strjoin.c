/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:15:49 by bhatches          #+#    #+#             */
/*   Updated: 2021/03/15 22:48:22 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*s;
	char		*buf;
	size_t		s1_len;
	size_t		s2_len;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	s1_len = ((s1 == NULL) ? 0 : ft_strlen(s1));
	s2_len = ((s2 == NULL) ? 0 : ft_strlen(s2));
	s = (char*)malloc((s1_len + s2_len) * sizeof(char) + 1);
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
