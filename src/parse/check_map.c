/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadorlin <sadorlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:57:34 by sadorlin          #+#    #+#             */
/*   Updated: 2023/06/28 05:55:44 by sadorlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_place(t_parse *prs, int i, int j)
{
	if (!prs->map[i][j - 1] || prs->map[i][j - 1] == ' ')
		return (1);
	if (!prs->map[i][j + 1] || prs->map[i][j + 1] == ' ')
		return (1);
	if (!prs->map[i - 1] || !prs->map[i - 1][j]
		|| prs->map[i - 1][j] == ' ')
		return (1);
	if (!prs->map[i + 1] || !prs->map[i + 1][j]
		|| prs->map[i + 1][j] == ' ')
		return (1);
	return (0);
}

static int	map_is_close(t_parse *prs, int i, int j)
{
	while (prs->map[i] && prs->map[i][++j])
	{
		if (prs->map[i][j] == '0'
			|| prs->map[i][j] == 'N' || prs->map[i][j] == 'S'
			|| prs->map[i][j] == 'W' || prs->map[i][j] == 'E')
		{
			if (check_place(prs, i, j))
				return (write(2, "Error.\nMap is not close.\n", 25));
		}
		if (!prs->map[i][j + 1])
		{
			i++;
			j = -1;
		}
	}
	return (0);
}

static int	player_is_valid(t_parse *prs, int i, int j)
{
	while (prs->map[i] && prs->map[i][++j])
	{
		if (prs->map[i][j] == 'N' || prs->map[i][j] == 'S'
			|| prs->map[i][j] == 'W' || prs->map[i][j] == 'E')
			prs->player++;
		if (prs->player > 1)
			return (write(2, "Error.\nToo many players.\n", 25));
		if (!prs->map[i][j + 1])
		{
			i++;
			j = -1;
		}
	}
	if (prs->player == 0)
		return (write(2, "Error.\nPlayer missing.\n", 23));
	return (0);
}

static int	check_map_element(t_parse *prs, int i, int j)
{
	while (prs->map[i] && prs->map[i][++j])
	{
		if (prs->map[i][j] != ' '
			&& prs->map[i][j] != '1' && prs->map[i][j] != '0'
			&& prs->map[i][j] != 'N' && prs->map[i][j] != 'S'
			&& prs->map[i][j] != 'W' && prs->map[i][j] != 'E')
			return (write(2, "Error.\nInvalid elements in map.\n", 32));
		if (!prs->map[i][j + 1])
		{
			i++;
			j = -1;
		}
	}
	return (0);
}

int	check_map(t_game *g)
{
	if (check_map_element(&g->prs, 0, 1))
		return (1);
	if (player_is_valid(&g->prs, 0, -1))
		return (1);
	if (map_is_close(&g->prs, 0, -1))
		return (1);
	if (clean_map_line(g, -1, 0))
		return (1);
	return (0);
}
