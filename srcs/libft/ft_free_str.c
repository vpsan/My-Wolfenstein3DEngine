/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:56:34 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/20 15:10:32 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION
**	ft_free_str() must free up malloc'ed memory of s and set s as NULL.
**	RETURN VALUES
**	ft_free_str() returns 0.
*/

int	ft_free_str(char **s)
{
	if (*s != NULL)
	{
		free(*s);
	}
	*s = NULL;
	return (0);
}
