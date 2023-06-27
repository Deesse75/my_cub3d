/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadorlin <sadorlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 07:22:54 by sadorlin          #+#    #+#             */
/*   Updated: 2023/06/28 00:53:26 by sadorlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_print(t_game *g)
{
	int	i;

	i = -1;
	while (g->prs.file[++i])
		printf("FILE : *%s*\n", g->prs.file[i]);
	printf("NO: *%s*\n", g->prs.no);
	printf("SO: *%s*\n", g->prs.so);
	printf("WE: *%s*\n", g->prs.we);
	printf("EA: *%s*\n", g->prs.ea);
	printf("F: [%X] C: [%X]\n", g->prs.floor, g->prs.ceiling);
	i = -1;
	while (g->prs.map[++i])
		printf("*%s*\n", g->prs.map[i]);
}

static void	init_g(t_game *g)
{
	g->mlx = (t_win){0};
	g->prs = (t_parse){0};
	g->pt = (t_player){0};
	g->rx = (t_ray){0};
	g->no = (t_xpm){0};
	g->so = (t_xpm){0};
	g->we = (t_xpm){0};
	g->ea = (t_xpm){0};
}

int	main(int ac, char **av)
{
	t_game	g;

	g = (t_game){0};
	init_g(&g);
	if (check_argv(ac, av))
		return (1);
	if (copy_file(&g.prs, av[1], 0))
		close_game(&g);
	if (parse_param(&g, -1, NULL))
		close_game(&g);
	if (parse_map(&g, 0))
		close_game(&g);
	if (init_game(&g))
		close_game(&g);
	ft_print(&g);
	close_game(&g);
	return (0);
}
