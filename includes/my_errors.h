/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_errors.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:56:18 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/01 16:38:52 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_ERRORS_H
# define MY_ERRORS_H

# include <stdio.h>
# include "libft.h"

void	my_errors_init(void);
void	my_errors_call(int number);

char	*g_error_arr[20];

#endif
