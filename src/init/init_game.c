/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadorlin <sadorlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:03:05 by sadorlin          #+#    #+#             */
/*   Updated: 2023/06/30 17:20:10 by sadorlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	quit(t_game *g)
{
	close_game(g);
	return (0);
}

static int	keypress(int key, t_game *g)
{
	if (key == 97)
		g->pt.left = 1;
	else if (key == 100)
		g->pt.right = 1;
	else if (key == 119)
		g->pt.forward = 1;
	else if (key == 115)
		g->pt.backwards = 1;
	else if (key == 65361)
		g->pt.rotleft = 1;
	else if (key == 65363)
		g->pt.rotright = 1;
	else if (key == 65307)
		close_game(g);
	return (0);
}

int	key_released(int key, t_game *g)
{
	if (key == 97)
		g->pt.left = 0;
	if (key == 100)
		g->pt.right = 0;
	if (key == 119)
		g->pt.forward = 0;
	if (key == 115)
		g->pt.backwards = 0;
	if (key == 65361)
		g->pt.rotleft = 0;
	if (key == 65363)
		g->pt.rotright = 0;
	return (0);
}

static int	play_cub(t_game *g)
{
	g->state = 1;
	g->sc.img = mlx_new_image(g->mlx.ptr, g->mlx.w, g->mlx.h);
	g->sc.addr = mlx_get_data_addr(g->sc.img, &g->sc.bpp,
			&g->sc.len, &g->sc.endian);
	game_param(g, -1, 0, 0);
	mlx_put_image_to_window(g->mlx.ptr, g->mlx.win, g->sc.img, 0, 0);
	mlx_destroy_image(g->mlx.ptr, g->sc.img);
	return (0);
}

int	init_game(t_game *g)
{
	init_player(g);
	g->mlx.state = 1;
	g->mlx.ptr = mlx_init();
	if (!g->mlx.ptr)
		return (write(2, "Error.\nEchec mlx_init().\n", 25), 1);
	if (init_texture(g))
		close_game(g);
	g->mlx.win = mlx_new_window(g->mlx.ptr, g->mlx.w, g->mlx.h, "CUB3D");
	if (!g->mlx.win)
		return (write(2, "Error.\nEchec mlx_new_window().\n", 31), 1);
	mlx_hook(g->mlx.win, 2, 1L << 0, keypress, g);
	mlx_key_hook(g->mlx.win, key_released, g);
	mlx_hook(g->mlx.win, 17, 1L << 0, quit, g);
	mlx_loop_hook(g->mlx.ptr, play_cub, g);
	mlx_loop(g->mlx.ptr);
	return (0);
}
