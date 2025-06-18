/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:27:16 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/18 00:55:43 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft.h"
#include "mlx.h"
#include "mlx_int.h"
#include <math.h>

#define TILE_WIDTH 16
#define TILE_HEIGHT 16

typedef struct s_win
{
	t_xvar		*mlx;
	t_win_list	*win;
	char		*name;
	int			width;
	int			height;
}	t_win;

typedef struct s_map_info
{
	int		rows;
	int		columns;
}	t_map_info;

typedef struct s_tile_images
{
	t_img	**variants;
	int		count;
}	t_tile_images;

typedef	struct s_game_assets
{
	t_tile_images	walls;
	t_tile_images	floors;
	t_tile_images	player;
	t_tile_images	collectables;
}	t_game_assets;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	free_map(char **map);
void	clear_program(t_win *win, char **map);
void	get_map_info(t_map_info *map_info, char *map_name);
char	**parse_map(t_map_info *map_info, char *map_name);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

// Render
void	draw_map(t_win *win, char **map, t_map_info *map_info);
void	draw_objects(t_win *win, char **map, t_map_info *map_info);

// Events
int	on_key_press(int key_code, t_win *win);

// Assets
void	init_assets(t_game_assets	*assets)

#endif
