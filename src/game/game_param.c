/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadorlin <sadorlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 03:54:50 by sadorlin          #+#    #+#             */
/*   Updated: 2023/06/30 08:29:34 by sadorlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	wall_len(t_game *g, int *line_up, int *line_down)
{
	if (g->rx.side == 0)
	{
		if (g->rx.map_x < g->pt.x)
			g->rx.texture = g->no.text;
		else
			g->rx.texture = g->so.text;
		g->rx.perpwalldist = g->rx.side_x - g->rx.delta_x;
		g->rx.wallx = g->pt.y + g->rx.perpwalldist * g->rx.ray_y;
	}
	else
	{
		if (g->rx.map_y < g->pt.y)
			g->rx.texture = g->we.text;
		else
			g->rx.texture = g->ea.text;
		g->rx.perpwalldist = g->rx.side_y - g->rx.delta_y;
		g->rx.wallx = g->pt.x + g->rx.perpwalldist * g->rx.ray_x;
	}
	g->rx.line_h = (int)(g->mlx.h / g->rx.perpwalldist);
	*line_up = (-1 * g->rx.line_h) / 2 + g->mlx.h / 2;
	if (*line_up < 0 || *line_up >= g->mlx.h)
		*line_up = 0;
	*line_down = g->rx.line_h / 2 + g->mlx.h / 2;
	if (*line_down >= g->mlx.h || *line_down < 0)
		*line_down = g->mlx.h - 1;
}

static void	hit_wall(t_game *g)
{
	g->rx.hit = 0;
	while (g->rx.hit == 0)
	{
		if (g->rx.side_x < g->rx.side_y)
		{
			g->rx.side_x += g->rx.delta_x;
			g->rx.map_x += g->rx.step_x;
			g->rx.side = 0;
		}
		else
		{
			g->rx.side_y += g->rx.delta_y;
			g->rx.map_y += g->rx.step_y;
			g->rx.side = 1;
		}
		if (g->prs.map[g->rx.map_x][g->rx.map_y] == '1')
			g->rx.hit = 1;
	}
}

static void	get_dist(t_game *g)
{
	if (g->rx.ray_x < 0)
	{
		g->rx.step_x = -1;
		g->rx.side_x = (g->pt.x - g->rx.map_x) * g->rx.delta_x;
	}
	else
	{
		g->rx.step_x = 1;
		g->rx.side_x = (g->rx.map_x + 1.0 - g->pt.x) * g->rx.delta_x;
	}
	if (g->rx.ray_y < 0)
	{
		g->rx.step_y = -1;
		g->rx.side_y = (g->pt.y - g->rx.map_y) * g->rx.delta_y;
	}
	else
	{
		g->rx.step_y = 1;
		g->rx.side_y = (g->rx.map_y + 1.0 - g->pt.y) * g->rx.delta_y;
	}
}

static void	get_ray(t_game *g)
{
	g->rx.ray_x = g->pt.dir_x + g->pt.plane_x * g->pt.cam;
	g->rx.ray_y = g->pt.dir_y + g->pt.plane_y * g->pt.cam;
	g->rx.delta_x = fabs(1 / g->rx.ray_x);
	g->rx.delta_y = fabs(1 / g->rx.ray_y);
	g->rx.map_x = (int)g->pt.x;
	g->rx.map_y = (int)g->pt.y;
}

void	game_param(t_game *g, int i, int line_up, int line_down)
{
	while (++i < g->mlx.w)
	{
		g->pt.cam = 2 * i / (double)g->mlx.w - 1;
		get_ray(g);
		get_dist(g);
		hit_wall(g);
		wall_len(g, &line_up, &line_down);
		g->rx.texnum = (int)(g->rx.wallx * 64.0);
		if ((g->rx.side == 0 && g->rx.ray_x > 0)
			|| (g->rx.side == 1 && g->rx.ray_y < 0))
			g->rx.texnum = 64 - g->rx.texnum - 1;
		draw_map(g, line_up, line_down, i);
	}
}
