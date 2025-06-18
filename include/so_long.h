/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:27:16 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/18 13:37:06 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft.h"
#include "mlx.h"
#include "mlx_int.h"
#include <math.h>

#define NAME "So_long"
#define TILE_WIDTH 64 
#define TILE_HEIGHT 64 
#define MENU_HEIGHT 64
#define MALLOC_ERROR -1
#define SUCCESS 0 

typedef struct s_point
{
	int	column;
	int	row;
}	t_point;

typedef struct s_win
{
	t_xvar		*mlx;
	t_win_list	*win;
	int			width;
	int			height;
}	t_win;

typedef struct s_map
{
	char	**map;
	char	*name;
	int		columns;
	int		rows;
	int		redraw;
	int		fd;
}	t_map;

typedef struct s_player
{
	t_point	location;
	int		lives;
	int		collectables;
	int		move_count;
}	t_player;

typedef	struct s_assets
{
	t_img	*wall;
	t_img	*floor;
	t_img	*player;
	t_img	*collectable;
}	t_assets;

typedef struct s_game
{
	t_win		*win;
	t_map		*map;
	t_player	*player;
	t_assets	*assets;
}	t_game;

// Main 
void	clear_program(t_win *win, t_map *map, t_assets *assets);

// Map
void	free_map(t_map *map);
int		parse_map(t_map *map);
void	get_map_info(t_map *map, char *map_name);

// Player 
void	init_player(t_player *player, t_map *map);

// Assets
void	free_assets(t_win *win, t_assets *assets);
void	init_assets(t_win *win, t_map *map, t_assets *assets);

// Render
void	draw_player(t_win *win, t_assets *assets, t_player *player);
void	draw_objects(t_win *win, t_map *map, t_assets *assets);
void	draw_map(t_win *win, t_map *map, t_assets *assets);

// Events
int		on_key_press(int key_code, void *param);

// Movement
void	move_up(t_map *map, t_player *player);
void	move_right(t_map *map, t_player *player);
void	move_left(t_map *map, t_player *player);
void	move_down(t_map *map, t_player *player);

#endif
