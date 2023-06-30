/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadorlin <sadorlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 07:22:54 by sadorlin          #+#    #+#             */
/*   Updated: 2023/06/30 08:23:54 by sadorlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static void	ft_print(t_game *g)
// {
// 	int	i;

// 	i = -1;
// 	while (g->prs.file[++i])
// 		printf("FILE : *%s*\n", g->prs.file[i]);
// 	printf("NO: *%s*\n", g->prs.no);
// 	printf("SO: *%s*\n", g->prs.so);
// 	printf("WE: *%s*\n", g->prs.we);
// 	printf("EA: *%s*\n", g->prs.ea);
// 	printf("F: [%X] C: [%X]\n", g->prs.floor, g->prs.ceiling);
// 	i = -1;
// 	while (g->prs.map[++i])
// 		printf("*%s*\n", g->prs.map[i]);
// }

static int	init_parse(t_parse *prs)
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
		return (free(prs->buff), perror("Malloc() init_parse() "), 1);
	return (0);
}

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
	if (init_parse(&g->prs))
		return (1);
	g->mlx.h = 900;
	g->mlx.w = 1200;
	return (0);
}

int	main(int ac, char **av)
{
	t_game	g;

	g = (t_game){0};
	if (check_argv(ac, av) || init_g(&g))
		return (1);
	if (copy_file(&g.prs, av[1], 0))
		close_game(&g);
	if (parse_param(&g, -1, NULL) || parse_map(&g, 0))
		close_game(&g);
	if (init_game(&g))
		close_game(&g);
	close_game(&g);
	return (0);
}
