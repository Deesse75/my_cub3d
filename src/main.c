/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadorlin <sadorlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 07:22:54 by sadorlin          #+#    #+#             */
/*   Updated: 2023/07/19 19:09:38 by sadorlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	init_g(t_game *g)
{
	g->mlx = (t_win){0};
	g->prs = (t_parse){0};
	g->pt = (t_player){0};
	g->rx = (t_ray){0};
	g->no = (t_data){0};
	g->so = (t_data){0};
	g->we = (t_data){0};
	g->ea = (t_data){0};
	g->mlx.h = 700;
	g->mlx.w = 1000;
	return (0);
}

int	main(int ac, char **av)
{
	t_game	g;

	g = (t_game){0};
	init_g(&g);
	if (parsing(&g, ac, av))
		return (close_game(&g), 0);
	if (init_game(&g))
		close_game(&g);
	close_game(&g);
	return (0);
}
