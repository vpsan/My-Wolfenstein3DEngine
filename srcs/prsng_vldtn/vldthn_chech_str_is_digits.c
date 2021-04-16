/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vldthn_chech_str_is_digits.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 21:48:26 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/16 21:48:28 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "prsng_vldtn.h"

int		vldthn_chech_str_is_digits(char *str, int exit_number)
{
	int		j;
	int		exit_flag;

	j = 0;
	exit_flag = 0;
	while (str[j] != '\0')
	{
		if (ft_isdigit(str[j]) == false)
			exit_flag = 1;
		j++;
	}
	if (exit_flag == 1)
		my_exit(exit_number);
	return (0);
}
