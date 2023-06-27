/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadorlin <sadorlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 07:03:19 by sadorlin          #+#    #+#             */
/*   Updated: 2023/06/27 15:34:03 by sadorlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

# include "cub3d.h"

typedef struct s_parse{
	int		state;
	char	**file;
	char	**tmp;
	char	*line;
	char	*buff;
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	int		floor;
	int		ceiling;
	int		*color;
	char	**map;
	int		size;
	int		index;
	int		player;
	int		fd;

}t_parse;

typedef struct s_player{
	int		state;
	char	pos;
	double	cam;
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}t_player;

typedef struct s_ray{
	double	ray_x;
	double	ray_y;
	double	side_x;
	double	side_y;
	double	delta_x;
	double	delta_y;
	double	perpwalldist;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		line_h;
	int		hit;
	int		side;
}t_ray;

typedef struct s_xpm{
	int		state;
	void	*img;
	void	*tex;
	char	*name;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
	int		h;
	int		w;
}t_xpm;

typedef struct s_win{
	int		state;
	void	*ptr;
	void	*win;
	int		h;
	int		w;
}t_win;

typedef struct s_game{
	t_win		mlx;
	t_parse		prs;
	t_player	pt;
	t_ray		rx;
	t_xpm		no;
	t_xpm		so;
	t_xpm		ea;
	t_xpm		we;
}t_game;

#endif