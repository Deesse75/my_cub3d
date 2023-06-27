/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadorlin <sadorlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 08:57:52 by sadorlin          #+#    #+#             */
/*   Updated: 2023/06/28 00:46:42 by sadorlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_win(t_win *mlx)
{
	mlx->state = 1;
	mlx->w = 800;
	mlx->h = 700;
	mlx->ptr = NULL;
	mlx->win = NULL;
}

int	init_parse(t_parse *prs)
{
	prs->state = 1;
	prs->size = -1;
	prs->index = 0;
	prs->player = 0;
	prs->floor = -1;
	prs->ceiling = -1;
	prs->fd = 0;
	prs->file = NULL;
	prs->tmp = NULL;
	prs->line = NULL;
	prs->map = NULL;
	prs->no = NULL;
	prs->so = NULL;
	prs->we = NULL;
	prs->ea = NULL;
	prs->buff = malloc(4096);
	if (!prs->buff)
		return (perror("Malloc() init_parse() "), 1);
	prs->color = malloc(sizeof(int) * 3);
	if (!prs->color)
		return (perror("Malloc() init_parse() "), 1);
	return (0);
}

int	init_texture(t_game *g)
{
	g->no.img = mlx_xpm_file_to_image(
			g->mlx.ptr, g->prs.no, &g->no.w, &g->no.h);
	g->so.img = mlx_xpm_file_to_image(
			g->mlx.ptr, g->prs.so, &g->so.w, &g->so.h);
	g->we.img = mlx_xpm_file_to_image(
			g->mlx.ptr, g->prs.we, &g->we.w, &g->we.h);
	g->ea.img = mlx_xpm_file_to_image(
			g->mlx.ptr, g->prs.ea, &g->ea.w, &g->ea.h);
	if (!g->no.img || !g->so.img || !g->ea.img || !g->we.img)
		return (perror("init_texture() "), 1);
	g->no.addr = mlx_get_data_addr(
			g->no.img, &g->no.bpp, &g->no.len, &g->no.endian);
	g->so.addr = mlx_get_data_addr(
			g->so.img, &g->so.bpp, &g->so.len, &g->so.endian);
	g->we.addr = mlx_get_data_addr(
			g->we.img, &g->we.bpp, &g->we.len, &g->we.endian);
	g->ea.addr = mlx_get_data_addr(
			g->ea.img, &g->ea.bpp, &g->ea.len, &g->ea.endian);
	if (!g->no.addr || !g->so.addr || !g->ea.addr || !g->we.addr)
		return (perror("init_texture() "), 1);
	// if (check_size_texture_file(g))
	// 	return (1);
	return (0);
}
