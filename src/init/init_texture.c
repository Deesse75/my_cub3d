/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadorlin <sadorlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 01:06:22 by sadorlin          #+#    #+#             */
/*   Updated: 2023/06/30 08:29:50 by sadorlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_size_texture(t_game *g)
{
	if (g->no.h != 64 || g->no.w != 64)
		return (write(2, "Error.\nInvalid size texture file NO.\n", 37));
	if (g->so.h != 64 || g->so.w != 64)
		return (write(2, "Error.\nInvalid size texture file SO.\n", 37));
	if (g->ea.h != 64 || g->ea.w != 64)
		return (write(2, "Error.\nInvalid size texture file EA.\n", 37));
	if (g->we.h != 64 || g->we.w != 64)
		return (write(2, "Error.\nInvalid size texture file WE.\n", 37));
	return (0);
}

static int	check_texture(t_game *g)
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
	g->no.text = (int *)mlx_get_data_addr(
			g->no.img, &g->no.bpp, &g->no.len, &g->no.endian);
	g->so.text = (int *)mlx_get_data_addr(
			g->so.img, &g->so.bpp, &g->so.len, &g->so.endian);
	g->we.text = (int *)mlx_get_data_addr(
			g->we.img, &g->we.bpp, &g->we.len, &g->we.endian);
	g->ea.text = (int *)mlx_get_data_addr(
			g->ea.img, &g->ea.bpp, &g->ea.len, &g->ea.endian);
	if (!g->no.text || !g->so.text || !g->ea.text || !g->we.text)
		return (perror("init_texture() "), 1);
	return (0);
}

int	init_texture(t_game *g)
{
	g->state = 1;
	if (check_texture(g))
		return (1);
	if (check_size_texture(g))
		return (1);
	return (0);
}
