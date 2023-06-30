/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadorlin <sadorlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 07:00:24 by sadorlin          #+#    #+#             */
/*   Updated: 2023/06/30 08:30:08 by sadorlin         ###   ########.fr       */
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
int		copy_file(t_parse *prs, char *file, int ret);
int		parse_param(t_game *g, int i, char *tp);
int		fill_color_param(t_parse *prs, char *tp);
int		fill_texture_param(t_parse *prs, char *tex, char *tp);
int		parse_map(t_game *g, int i);
int		check_map(t_game *g);
int		init_game(t_game *g);
int		init_texture(t_game *g);
void	init_data(t_data *dt);
void	init_player(t_game *g);
void	game_param(t_game *g, int i, int line_up, int line_down);
void	draw_map(t_game *g, int line_up, int line_down, int col);
int		clean_map_line(t_game *g, int i, int size);

#endif