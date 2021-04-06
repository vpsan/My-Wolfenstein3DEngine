/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:01:29 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/06 12:44:23 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalpha(int value)
{
	if ((value >= 'a' && value <= 'z') ||
		(value >= 'A' && value <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
