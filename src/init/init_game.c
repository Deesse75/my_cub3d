/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadorlin <sadorlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:03:05 by sadorlin          #+#    #+#             */
/*   Updated: 2023/06/28 00:51:24 by sadorlin         ###   ########.fr       */
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
	if (key == 65307 || key == 113)
		close_game(g);
	return (0);
}

int	init_game(t_game *g)
{
	init_win(&g->mlx);
	g->mlx.ptr = mlx_init();
	if (!g->mlx.ptr)
		return (perror("mlx_ptr "), 1);
	g->mlx.win = mlx_new_window(g->mlx.ptr, g->mlx.w, g->mlx.h, "CUB3D");
	if (!g->mlx.win)
		return (perror("mlx_win "), 1);
	mlx_hook(g->mlx.win, 2, 1L << 0, keypress, g);
	mlx_hook(g->mlx.win, 17, 1L << 0, quit, g);
	mlx_loop(g->mlx.ptr);
	return (0);
}
