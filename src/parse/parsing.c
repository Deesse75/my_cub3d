/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadorlin <sadorlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:52:41 by sadorlin          #+#    #+#             */
/*   Updated: 2023/07/19 19:15:14 by sadorlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	parsing(t_game *g, int ac, char **av)
{
	if (check_argv(ac, av) || init_parse(&g->prs))
		return (1);
	if (copy_file(&g->prs, av[1], 0))
		return (free_parse(&g->prs), 1);
	if (parse_param(&g->prs, -1, NULL) || parse_map(&g->prs))
		return (free_parse(&g->prs), 1);
	return (0);
}
