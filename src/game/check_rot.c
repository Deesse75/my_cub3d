/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadorlin <sadorlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 13:18:26 by sadorlin          #+#    #+#             */
/*   Updated: 2023/06/30 13:21:59 by sadorlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotateleft(t_game *g)
{
	double	speed;
	double	old_dirx;
	double	old_planex;

	speed = 0.0001;
	old_dirx = g->pt.dir_x;
	g->pt.dir_x = g->pt.dir_x * cos(speed) - g->pt.dir_y * sin(speed);
	g->pt.dir_y = old_dirx * sin(speed) + g->pt.dir_y * cos(speed);
	old_planex = g->pt.plane_x;
	g->pt.plane_x = g->pt.plane_x * cos(speed) - g->pt.plane_y * sin(speed);
	g->pt.plane_y = old_planex * sin(speed) + g->pt.plane_y * cos(speed);
}

void	rotateright(t_game *g)
{
	double	speed;
	double	old_dirx;
	double	old_planex;

	speed = 0.0001;
	old_dirx = g->pt.dir_x;
	g->pt.dir_x = g->pt.dir_x * cos(-speed) - g->pt.dir_y * sin(-speed);
	g->pt.dir_y = old_dirx * sin(-speed) + g->pt.dir_y * cos(-speed);
	old_planex = g->pt.plane_x;
	g->pt.plane_x = g->pt.plane_x * cos(-speed) - g->pt.plane_y * sin(-speed);
	g->pt.plane_y = old_planex * sin(-speed) + g->pt.plane_y * cos(-speed);
}
