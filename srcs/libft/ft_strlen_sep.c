/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_sep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:56:49 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/22 19:47:48 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION
**	ft_strlen_sep() counts length of the string till the first
**	occurrence of character value.
**	RETURN VALUES
**	ft_strlen_sep() returns type size_t.
*/

size_t	ft_strlen_sep(const char *str, int value)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (*str != '\0' && *str != value)
	{
		i = i + 1;
		str++;
	}
	return (i);
}
