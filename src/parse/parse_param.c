/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadorlin <sadorlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:33:18 by sadorlin          #+#    #+#             */
/*   Updated: 2023/06/27 21:41:35 by sadorlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	double_check(t_parse *prs, char c)
{
	if ((c == 'N' && prs->no) || (c == 'S' && prs->so) || (c == 'E' && prs->ea)
		|| (c == 'W' && prs->we) || (c == 'F' && prs->floor > -1)
		|| (c == 'C' && prs->ceiling > -1))
	{
		write(2, "Error.\nFind double parameter.\n", 30);
		return (1);
	}
	return (0);
}

static int	select_param(t_parse *prs, char *tex)
{
	if (double_check(prs, tex[0]))
		return (1);
	if (!ft_strncmp(tex, "F ", 2) || !ft_strncmp(tex, "C ", 2))
	{
		if (fill_color_param(prs, tex))
			return (1);
	}
	else
	{
		if (fill_texture_param(prs, tex, NULL))
			return (1);
	}
	return (0);
}

int	parse_param(t_game *g, int i, char *tex)
{
	while (g->prs.file[++i])
	{
		tex = ft_strtrim(g->prs.file[i], " ");
		if (!tex)
			return (perror("Malloc() parse_param() "), 1);
		if (!tex[0] && g->prs.file[i][0])
			return (write(2, "Error.\nInvalid whitespace line.\n", 32));
		if (tex[0])
		{
			if (select_param(&g->prs, tex))
				return (free(tex), 1);
			free(tex);
			tex = NULL;
			if (++g->prs.index == 6)
				break ;
		}
		free(tex);
	}
	g->prs.size = i;
	if (!g->prs.no || !g->prs.so || !g->prs.we || !g->prs.ea
		|| g->prs.ceiling == -1 || g->prs.floor == -1)
		return (write(2, "Error.\nNumber of parameters invalid\n", 36));
	return (0);
}