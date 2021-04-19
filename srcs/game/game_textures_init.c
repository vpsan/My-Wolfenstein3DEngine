/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_textures_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 01:59:33 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/19 11:11:50 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	game_textures_img_init(t_game *cube)
{
	cube->no_txtr.img_ptr = mlx_xpm_file_to_image(cube->mlx_ptr,
			cube->map_prmtrs.no_path, &(cube->no_txtr.width),
			&(cube->no_txtr.height));
	cube->so_txtr.img_ptr = mlx_xpm_file_to_image(cube->mlx_ptr,
			cube->map_prmtrs.so_path, &cube->so_txtr.width,
			&cube->so_txtr.height);
	cube->we_txtr.img_ptr = mlx_xpm_file_to_image(cube->mlx_ptr,
			cube->map_prmtrs.we_path, &cube->we_txtr.width,
			&cube->we_txtr.height);
	cube->ea_txtr.img_ptr = mlx_xpm_file_to_image(cube->mlx_ptr,
			cube->map_prmtrs.ea_path, &cube->ea_txtr.width,
			&cube->ea_txtr.height);
	cube->sprts_txtr.img_ptr = mlx_xpm_file_to_image(cube->mlx_ptr,
			cube->map_prmtrs.sprts_path, &cube->sprts_txtr.width,
			&cube->sprts_txtr.height);
	return (0);
}

int	game_textures_adr_init(t_game *cube)
{
	cube->no_txtr.addr_ptr = mlx_get_data_addr(cube->no_txtr.img_ptr,
			&cube->no_txtr.bits_per_pixel, &cube->no_txtr.size_line,
			&cube->no_txtr.endian);
	cube->so_txtr.addr_ptr = mlx_get_data_addr(cube->so_txtr.img_ptr,
			&cube->so_txtr.bits_per_pixel, &cube->so_txtr.size_line,
			&cube->so_txtr.endian);
	cube->we_txtr.addr_ptr = mlx_get_data_addr(cube->we_txtr.img_ptr,
			&cube->we_txtr.bits_per_pixel, &cube->we_txtr.size_line,
			&cube->we_txtr.endian);
	cube->ea_txtr.addr_ptr = mlx_get_data_addr(cube->ea_txtr.img_ptr,
			&cube->ea_txtr.bits_per_pixel, &cube->ea_txtr.size_line,
			&cube->ea_txtr.endian);
	cube->sprts_txtr.addr_ptr = mlx_get_data_addr(cube->sprts_txtr.img_ptr,
			&cube->sprts_txtr.bits_per_pixel, &cube->sprts_txtr.size_line,
			&cube->sprts_txtr.endian);
	return (0);
}

int	check_img_ptr(t_game *cube)
{
	if (cube->no_txtr.img_ptr == NULL
		|| cube->so_txtr.img_ptr == NULL
		|| cube->ea_txtr.img_ptr == NULL
		|| cube->we_txtr.img_ptr == NULL
		|| cube->sprts_txtr.img_ptr == NULL)
		my_exit(14);
	return (0);
}

int	check_addr_ptr(t_game *cube)
{
	if (cube->no_txtr.addr_ptr == NULL
		|| cube->so_txtr.addr_ptr == NULL
		|| cube->ea_txtr.addr_ptr == NULL
		|| cube->we_txtr.addr_ptr == NULL
		|| cube->sprts_txtr.addr_ptr == NULL)
		my_exit(14);
	return (0);
}

int	game_textures_init(t_game *cube)
{
	game_textures_img_init(cube);
	check_img_ptr(cube);
	game_textures_adr_init(cube);
	check_addr_ptr(cube);
	return (0);
}
