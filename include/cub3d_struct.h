/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadorlin <sadorlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 07:03:19 by sadorlin          #+#    #+#             */
/*   Updated: 2023/06/30 16:49:20 by sadorlin         ###   ########.fr       */
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
	int		left;
	int		right;
	int		forward;
	int		backwards;
	int		rotleft;
	int		rotright;
}t_player;

typedef struct s_data{
	int		*text;
	void	*img;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
	int		h;
	int		w;
	int		on;
}t_data;

typedef struct s_ray{
	double	ray_x;
	double	ray_y;
	double	side_x;
	double	side_y;
	double	delta_x;
	double	delta_y;
	double	perpwalldist;
	double	wallx;
	int		texnum;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		line_h;
	int		hit;
	int		side;
}t_ray;

typedef struct s_win{
	int		state;
	void	*ptr;
	void	*win;
	int		h;
	int		w;
}t_win;

typedef struct s_game{
	int			state;
	t_win		mlx;
	t_parse		prs;
	t_player	pt;
	int			*texture;
	int			t_size;
	t_ray		rx;
	t_data		no;
	t_data		so;
	t_data		ea;
	t_data		we;
	t_data		sc;
	t_data		mp;
}t_game;

#endif