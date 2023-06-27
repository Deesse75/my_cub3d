/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadorlin <sadorlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 07:00:24 by sadorlin          #+#    #+#             */
/*   Updated: 2023/06/28 00:53:07 by sadorlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "cub3d_struct.h"

int		check_argv(int ac, char **av);
void	close_game(t_game *g);
void	free_win(t_win *mlx);
void	free_parse(t_parse *p);
void	free_xpm(t_xpm *tx);
int		copy_file(t_parse *prs, char *file, int ret);
int		init_parse(t_parse *prs);
int		parse_param(t_game *g, int i, char *tp);
int		fill_color_param(t_parse *prs, char *tp);
int		fill_texture_param(t_parse *prs, char *tex, char *tp);
int		parse_map(t_game *g, int i);
int		check_map(t_game *g);
void	init_win(t_win *mlx);
int		init_game(t_game *g);

# endif