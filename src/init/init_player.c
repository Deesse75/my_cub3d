/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadorlin <sadorlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 03:38:23 by sadorlin          #+#    #+#             */
/*   Updated: 2023/06/30 13:55:32 by sadorlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_dir1(t_game *g)
{
	if (g->pt.pos == 'N')
	{
		g->pt.dir_x = -1;
		g->pt.dir_y = 0;
		g->pt.plane_x = 0;
		g->pt.plane_y = 0.66;
	}
	if (g->pt.pos == 'S')
	{
		g->pt.dir_x = 1;
		g->pt.dir_y = 0;
		g->pt.plane_x = 0;
		g->pt.plane_y = -0.66;
	}
}

static void	get_dir2(t_game *g)
{
	if (g->pt.pos == 'E')
	{
		g->pt.dir_x = 0;
		g->pt.dir_y = 1;
		g->pt.plane_x = 0.66;
		g->pt.plane_y = 0;
	}
	if (g->pt.pos == 'W')
	{
		g->pt.dir_x = 0;
		g->pt.dir_y = -1;
		g->pt.plane_x = -0.66;
		g->pt.plane_y = 0;
	}
}

static void	get_position(t_game *g, int i, int j)
{
	while (g->prs.map[i][++j])
	{
		if (g->prs.map[i][j] == 'N' || g->prs.map[i][j] == 'S'
			|| g->prs.map[i][j] == 'E' || g->prs.map[i][j] == 'W')
		{
			g->pt.x = i + 0.5;
			g->pt.y = j + 0.5;
			g->pt.pos = g->prs.map[i][j];
			g->prs.map[i][j] = '0';
			break ;
		}
		if (!g->prs.map[i][j + 1])
		{
			j = -1;
			i++;
		}
	}
}

void	init_player(t_game *g)
{
	get_position(g, 0, -1);
	if (g->pt.pos == 'N' || g->pt.pos == 'S')
		get_dir1(g);
	else
		get_dir2(g);
}
