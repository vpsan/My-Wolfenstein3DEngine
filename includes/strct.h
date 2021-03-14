/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strct.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 18:20:35 by bhatches          #+#    #+#             */
/*   Updated: 2021/03/13 14:50:54 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRCT_H
# define STRCT_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# define SCALE 16
# define ERROR -1

typedef struct	s_wndw //структура для окна
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*addr;
	int			size_line;
	int			bpp;
	int			endian;
}				t_wndw;

typedef struct	s_point // структура для точки
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_plr //структура для игрока и луча
{
	float		x;
	float		y;
	float		dir;
	float		start;
	float		end;
}				t_plr;

typedef struct	s_game // структура для всего вместе
{
	t_wndw		wndw;
	t_plr		plr;
	char		**map;
	t_list		*head_lstmap;
}				t_game;

void	game_init(t_game *cube);
int 	game_start(t_game *cube);

#endif