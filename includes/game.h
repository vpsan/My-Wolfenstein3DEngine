/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strct.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 18:20:35 by bhatches          #+#    #+#             */
/*   Updated: 2021/03/19 17:01:30 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRCT_H
# define STRCT_H

# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"
# include "libft.h"

# define SCALE 16
# define KEY_ESC 53
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define SPEED_MOVE 0.1 // change speed
# define SPEED_TURN 0.05 // change speed

# define ERROR -1

typedef struct		s_texture
{
	void			*img_ptr;
	char			*addr_ptr;
	int				size_line;
	int				bits_per_pixel;
	int				endian;
	int				width;
	int				height;
}					t_texture;

typedef struct		s_keys
{
	int				w;
	int				a;
	int				s;
	int				d;
	int				left;
	int				right;
}					t_keys;

typedef struct		s_map_prmtrs
{
	int				win_width;
	int 			win_height;
	char 			*no_path;
	char 			*so_path;
	char 			*we_path;
	char 			*ea_path;
	char 			*sprts_path;
}					t_map_prmtrs;

typedef struct		s_game
{
	void			*mlx_ptr;
	void			*win_ptr;
	//	t_player		plr;
	t_keys			keys;
	t_texture		no_txtr;
	t_texture		so_txtr;
	t_texture		we_txtr;
	t_texture		ea_txtr;
	t_texture		sprts_txtr;
	t_map_prmtrs	map_prmtrs;
	char			**map;
	t_list			*head_lstmap;
}					t_game;

int					game_init(t_game *cube);
int					game_map_init(t_game *cube);
int					game_preparsing_init(t_game *cube);
int					game_window_init(t_game *cube);
int					game_keys_init(t_game *cube);
int					game_textures_img_init(t_game *cube);
int					game_textures_adr_init(t_game *cube);
int					game_start(t_game *cube, int argc);
int					hook_press_on_keys(int keycode, t_game *cube);
int					hook_press_off_keys(int keycode, t_game *cube);
int					hook_close_window(t_game *cube);
int					hook_next_frame(t_game *cube);

#endif