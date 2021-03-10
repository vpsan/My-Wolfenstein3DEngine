/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parse_file.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 19:13:41 by bhatches          #+#    #+#             */
/*   Updated: 2021/03/10 14:48:04 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_PARSER_H
# define FILE_PARSER_H

# include <stdlib.h>
# include <unistd.h>

int     file_parse_file(int fd, t_game* cube);

#endif