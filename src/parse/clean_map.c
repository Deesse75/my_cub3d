/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadorlin <sadorlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 05:52:28 by sadorlin          #+#    #+#             */
/*   Updated: 2023/06/28 05:53:53 by sadorlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	clean_line(t_game *g, int i, int size, char *tmp)
{
	int	x;

	x = -1;
	size = ft_strlen(g->prs.map[i]);
	tmp = ft_strdup(g->prs.map[i]);
	free(g->prs.map[i]);
	g->prs.map[i] = malloc(g->prs.size + 1);
	if (!g->prs.map[i])
		return (perror("Malloc() clean_line()"), 1);
	while (++x < g->prs.size)
	{
		if (x >= size || tmp[x] == ' ')
			g->prs.map[i][x] = '1';
		else
			g->prs.map[i][x] = tmp[x];
	}
	g->prs.map[i][x] = '\0';
	free(tmp);
	return (0);
}

int	clean_map_line(t_game *g, int i, int size)
{
	g->prs.size = 0;
	while (g->prs.map[++i])
	{
		size = ft_strlen(g->prs.map[i]);
		if (size > g->prs.size)
			g->prs.size = size;
	}
	i = -1;
	while (g->prs.map[++i])
	{
		if (clean_line(g, i, 0, NULL))
			return (1);
	}
	return (0);
}
