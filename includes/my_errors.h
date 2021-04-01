/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_errors.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:56:18 by bhatches          #+#    #+#             */
/*   Updated: 2021/03/31 23:06:03 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <stdio.h>
# include "libft.h"

void	my_errors_init(void);
void	my_errors_call(int number);

char	*g_error_arr[20];

#endif
