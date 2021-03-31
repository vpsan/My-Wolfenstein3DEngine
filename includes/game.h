/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strct.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 18:20:35 by bhatches          #+#    #+#             */
/*   Updated: 2021/03/31 00:57:09 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRCT_H
# define STRCT_H

#include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
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
# define SPEED_MOVE 0.2
# define SPEED_TURN 0.1

# define WHITE 0x00FFFFFF
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF

# define BLACK_clr_clng 0x00000000
# define NAVI_clr_flr 70

# define ERROR -1

typedef struct		s_img_frame
{
	void			*img_ptr;
	char			*addr_ptr;
	int				size_line;
	int				bits_per_pixel;
	int				endian;
}					t_img_frame;

typedef struct		s_keys
{
	int				w;
	int				a;
	int				s;
	int				d;
	int				left;
	int				right;
}					t_keys;

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

typedef struct		s_map_prmtrs
{
	int				win_width;
	int 			win_height;
	char 			*no_path;
	char 			*so_path;
	char 			*we_path;
	char 			*ea_path;
	int 			clr_flr;
	int 			clr_clng;
	char 			*sprts_path;
}					t_map_prmtrs;

typedef struct 		s_player
{
	double 			pos_x;
	double 			pos_y;
	double 			dir_x;
	double 			dir_y;
	double 			plane_x;
	double 			plane_y;
}					t_player;

typedef struct 		s_rcstg
{
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	unsigned int color;// for no textures
//	double		wall_x;
//	t_texture	*tex;
//	int			tex_x;
//	int			tex_y;
//	double		tex_step;
//	double		tex_pos;
//	double		sprite_x;
//	double		sprite_y;
//	double		inv_det;
//	double		transform_x;
//	double		transform_y;
//	int			sprite_screen_x;
//	int			sprite_height;
//	int			sprite_width;
//	int			draw_start_y;
//	int			draw_end_y;
//	int			draw_start_x;
//	int			draw_end_x;
}					t_rcstg;

typedef struct		s_game
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_img_frame		nxt_frame;
	t_player		plr;
	t_keys			keys;
	t_texture		no_txtr;
	t_texture		so_txtr;
	t_texture		we_txtr;
	t_texture		ea_txtr;
	t_texture		sprts_txtr;
	t_map_prmtrs	map_prmtrs;
	t_rcstg			rcstg;
	char			**map;
	t_list			*head_lstmap;
}					t_game;

int					game_init(t_game *cube);
int					game_map_init(t_game *cube);
int					game_window_init(t_game *cube);
int					game_keys_init(t_game *cube);
int					game_textures_img_init(t_game *cube);
int					game_textures_adr_init(t_game *cube);
int					game_start(t_game *cube, int argc);
int					hook_press_on_keys(int keycode, t_game *cube);
int					hook_press_off_keys(int keycode, t_game *cube);
int					hook_close_window(t_game *cube);
int					hook_next_frame(t_game *cube);
void				rcstng_color_pixel(t_img_frame *nxt_frame, int x, int y,
						   int color);

int 				move_w(t_game *cube);
int 				move_s(t_game *cube);
int 				move_a(t_game *cube);
int 				move_d(t_game *cube);
int 				move_right(t_game *cube);
int 				move_left(t_game *cube);

int 				rcstng(t_game *cube);

#endif