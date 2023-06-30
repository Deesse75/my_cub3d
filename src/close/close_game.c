/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadorlin <sadorlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 08:58:28 by sadorlin          #+#    #+#             */
/*   Updated: 2023/06/30 08:14:34 by sadorlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_parse(t_parse *prs)
{
	if (prs->line)
		free(prs->line);
	if (prs->buff)
		free(prs->buff);
	if (prs->no)
		free(prs->no);
	if (prs->so)
		free(prs->so);
	if (prs->we)
		free(prs->we);
	if (prs->ea)
		free(prs->ea);
	if (prs->file)
		free_strs(prs->file);
	if (prs->tmp)
		free_strs(prs->tmp);
	if (prs->map)
		free_strs(prs->map);
	if (prs->color)
		free(prs->color);
}

static void	free_win(t_win *mlx)
{
	if (mlx->win)
		mlx_destroy_window(mlx->ptr, mlx->win);
	if (mlx->ptr)
	{
		mlx_destroy_display(mlx->ptr);
		free(mlx->ptr);
	}
}

static void	destroy_img(t_game *g)
{
	if (g->no.img)
		mlx_destroy_image(g->mlx.ptr, g->no.img);
	if (g->so.img)
		mlx_destroy_image(g->mlx.ptr, g->so.img);
	if (g->we.img)
		mlx_destroy_image(g->mlx.ptr, g->we.img);
	if (g->ea.img)
		mlx_destroy_image(g->mlx.ptr, g->ea.img);
	if (g->sc.img && g->state == 2)
		mlx_destroy_image(g->mlx.ptr, g->sc.img);
}

void	close_game(t_game *g)
{
	if (g->prs.state)
		free_parse(&g->prs);
	if (g->state)
		destroy_img(g);
	if (g->mlx.state)
		free_win(&g->mlx);
	exit(EXIT_SUCCESS);
}
