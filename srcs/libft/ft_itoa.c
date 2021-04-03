/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 10:43:16 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/03 12:14:10 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbrlen(int n)
{
	int i;

	i = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char		*s;
	size_t		len;
	long int	ln;

	ln = n;
	len = (n >= 0) ? (ft_nbrlen(n)) : (ft_nbrlen(n) + 1);
	s = (char*)ft_calloc(len + 1, sizeof(char));
	if (s == NULL)
		return (NULL);
	s[len] = '\0';
	if (n < 0)
	{
		s[0] = '-';
		ln = (-1) * ln;
	}
	while (len-- > 0 && s[len] != '-')
	{
		s[len] = ln % 10 + '0';
		ln = ln / 10;
	}
	return (s);
}
