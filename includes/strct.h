/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strct.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 18:20:35 by bhatches          #+#    #+#             */
/*   Updated: 2021/03/10 14:58:48 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRCT_H
# define STRCT_H

# define SCALE 16

typedef struct	s_win //структура для окна
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*addr;
	int			size_line;
	int			bpp;
	int			endian;
}				t_win;

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
	t_win		*win;
	t_plr		*plr;
	char		**map;
}				t_game;

void	game_init(t_game *cube);


#endif