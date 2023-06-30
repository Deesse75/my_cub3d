/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadorlin <sadorlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 04:33:07 by sadorlin          #+#    #+#             */
/*   Updated: 2023/06/30 08:28:40 by sadorlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_texture(t_game *g, int col)
{
	int		y;
	int		tex_y;
	double	step;
	double	tex_pos;
	char	*dst;

	y = -((int)(g->mlx.h / g->rx.perpwalldist)) / 2 + g->mlx.h / 2;
	if (y < 0)
		y = 0;
	step = 1.0 * 64 / ((int)(g->mlx.h / g->rx.perpwalldist));
	tex_pos = (y - (int)g->mlx.h / 2 + (
				(int)(g->mlx.h / g->rx.perpwalldist)) / 2) * step;
	while (y < (((int)(g->mlx.h / g->rx.perpwalldist)) / 2 + g->mlx.h / 2))
	{
		dst = g->sc.addr + (y * g->sc.len + col * (g->sc.bpp / 8));
		tex_y = (int)tex_pos & (64 - 1);
		tex_pos += step;
		*(unsigned int *)dst = *(g->rx.texture + 64 * tex_y + g->rx.texnum);
		y++;
		if (y == g->mlx.h)
			return ;
	}
}

static void	draw_ceiling(t_game *g, int line_up, int col)
{
	char	*dst;
	int		i;

	i = 0;
	while (i < line_up)
	{
		dst = g->sc.addr + (i * g->sc.len + col * (g->sc.bpp / 8));
		*(unsigned int *)dst = g->prs.ceiling;
		i++;
	}
}

static void	draw_floor(t_game *g, int line_down, int col)
{
	char	*dst;

	while (line_down < g->mlx.h)
	{
		dst = g->sc.addr + (line_down * g->sc.len + col * (g->sc.bpp / 8));
		*(unsigned int *)dst = g->prs.floor;
		line_down++;
	}
}

void	draw_map(t_game *g, int line_up, int line_down, int col)
{
	draw_ceiling(g, line_up, col);
	draw_texture(g, col);
	draw_floor(g, line_down, col);
}
