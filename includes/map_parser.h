/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 19:13:41 by bhatches          #+#    #+#             */
/*   Updated: 2021/03/10 14:48:04 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_PARSER_H
# define MAP_PARSER_H

# include <stdlib.h>
# include <unistd.h>

int     map_parser(int fd, t_game* cube);

#endif