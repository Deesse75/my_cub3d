/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadorlin <sadorlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:47:26 by sadorlin          #+#    #+#             */
/*   Updated: 2023/06/30 16:03:59 by sadorlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	moveleft(t_game *g)
{
	double	v;

	v = 0.1;
	if (g->prs.map[(int)(g->pt.x - g->pt.dir_y * v)][(int)(g->pt.y)] == '0')
		g->pt.x -= g->pt.dir_y * v * 0.001;
	if (g->prs.map[(int)(g->pt.x)][(int)(g->pt.y + g->pt.dir_x * v)] == '0')
		g->pt.y += g->pt.dir_x * v * 0.001;
}

static void	moveright(t_game *g)
{
	double	v;

	v = 0.1;
	if (g->prs.map[(int)(g->pt.x + g->pt.dir_y * v)][(int)(g->pt.y)] == '0')
		g->pt.x += g->pt.dir_y * v * 0.001;
	if (g->prs.map[(int)(g->pt.x)][(int)(g->pt.y - g->pt.dir_x * v)] == '0')
		g->pt.y -= g->pt.dir_x * v * 0.001;
}

static void	moveforward(t_game *g)
{
	double	v;

	v = 0.1;
	if (g->prs.map[(int)(g->pt.x + g->pt.dir_x * v)][(int)(g->pt.y)] == '0')
		g->pt.x += g->pt.dir_x * v * 0.001;
	if (g->prs.map[(int)(g->pt.x)][(int)(g->pt.y + g->pt.dir_y * v)] == '0')
		g->pt.y += g->pt.dir_y * v * 0.001;
}

static void	movebackward(t_game *g)
{
	double	v;

	v = 0.1;
	if (g->prs.map[(int)(g->pt.x - g->pt.dir_x * v)][(int)(g->pt.y)] == '0')
		g->pt.x -= g->pt.dir_x * v * 0.001;
	if (g->prs.map[(int)(g->pt.x)][(int)(g->pt.y - g->pt.dir_y * v)] == '0')
		g->pt.y -= g->pt.dir_y * v * 0.001;
}

void	check_move(t_game *g)
{
	if (g->pt.left)
		moveleft(g);
	if (g->pt.right)
		moveright(g);
	if (g->pt.backwards)
		movebackward(g);
	if (g->pt.forward)
		moveforward(g);
	if (g->pt.rotleft)
		rotateleft(g);
	if (g->pt.rotright)
		rotateright(g);
}
