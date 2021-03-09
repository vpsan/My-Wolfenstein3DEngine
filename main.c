/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 17:29:03 by bhatches          #+#    #+#             */
/*   Updated: 2021/03/09 16:02:13 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
#include "get_next_line.h"
#include "map_parser.h"
#include "mlx.h"

int main()
{
	void	*mlx = NULL;
	void	*window = NULL;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 640, 480, "main");
	
	map_parser();

	mlx_loop(mlx);
	return (0);
}
