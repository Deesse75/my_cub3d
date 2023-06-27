/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadorlin <sadorlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 08:58:28 by sadorlin          #+#    #+#             */
/*   Updated: 2023/06/27 15:20:15 by sadorlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_xpm(t_xpm *tx)
{
	free(tx->addr);
	free(tx->img);
	free(tx->name);
	free(tx->tex);
}

void	free_parse(t_parse *p)
{
	if (p->line)
		free(p->line);
	if (p->buff)
		free(p->buff);
	if (p->no)
		free(p->no);
	if (p->so)
		free(p->so);
	if (p->we)
		free(p->we);
	if (p->ea)
		free(p->ea);
	if (p->file)
		free_strs(p->file);
	if (p->tmp)
		free_strs(p->tmp);
	if (p->map)
		free_strs(p->map);
	if (p->color)
		free(p->color);
}

void	free_win(t_win *mlx)
{
	if (mlx->win)
		mlx_destroy_window(mlx->ptr, mlx->win);
	if (mlx->ptr)
	{
		mlx_destroy_display(mlx->ptr);
		free(mlx->ptr);
	}
}

void	close_game(t_game *g)
{
	if (g->prs.state)
		free_parse(&g->prs);
	if (g->no.state)
		free_xpm(&g->no);
	if (g->so.state)
		free_xpm(&g->so);
	if (g->we.state)
		free_xpm(&g->we);
	if (g->ea.state)
		free_xpm(&g->ea);
	if (g->mlx.state)
		free_win(&g->mlx);
	exit(EXIT_SUCCESS);
}
