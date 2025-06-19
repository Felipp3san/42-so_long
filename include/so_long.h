/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:27:16 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/19 21:44:15 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx_int.h"
# include "libft.h"
# include "mlx.h"
# include <math.h>

# define MALLOC_ERROR -1
# define SUCCESS 0 

// Window 
# define NAME "So_long"
# define TILE_WIDTH 64 
# define TILE_HEIGHT 64 
# define MENU_HEIGHT 64

// Lives
# define MAX_LIVES 3 
# define EMPTY 0
# define FILLED 1

// Objects
# define OPEN 0
# define CLOSED 1

// Frames 
# define MAX_FRAME 4294967290
# define FRAMES 5
# define ANIMATION_SPEED 1000
# define MOVEMENT_SPEED 100000

// Assets
# define FLOORS 3
# define NUMBERS 10
# define COLLECTABLES 3
# define HEARTS 2
# define DOORS 2

// Movement
# define UP 0  
# define LEFT 1 
# define DOWN 2 
# define RIGHT 3

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
	int		collectable_count;
	int		player_count;
	int		enemy_count;
	int		exit_count;
	int		door_state;
}	t_map;

typedef struct s_player
{
	t_point	location;
	int		lives;
	int		collectables;
	int		move_count;
}	t_player;

typedef struct s_enemy
{
	t_point	location;
	int		alive;
	int		next_direction;
}	t_enemy;

typedef struct s_assets
{
	t_img	*player;
	t_img	*wall;
	t_img	*floors[FLOORS];
	t_img	*hearts[HEARTS];
	t_img	*numbers[NUMBERS];
	t_img	*collectables[COLLECTABLES];
	t_img	*enemy[FRAMES];
	t_img	*torch[FRAMES];
	t_img	*doors[DOORS];
}	t_assets;

typedef struct s_frames
{
	unsigned int	frame_count;
	unsigned int	real_frame;
	unsigned int	last_frame;
}	t_frames;

typedef struct s_game
{
	t_frames	frames;
	t_win		win;
	t_map		map;
	t_enemy		*enemies;
	t_player	player;
	t_assets	assets;
}	t_game;

// main.c 
void	clear_program(t_game *game);

// map.c 
void	init_map(t_map *map, char *map_name);
int		parse_map(t_map *map);
void	extract_map_info(t_map *map);

// map_utils.c
int		open_map(char *map_name);
void	free_map(t_map *map);
void	free_map_exit(t_map *map, char *error);
char	**ft_clone_map(t_map *map);

// map_validation.c
void	validate_map(t_map *map);

// flood_fill.c
void	flood_fill(t_map *map, char **clone_map, t_point start);

// player.c 
t_point	get_player_location(t_map *map);
void	init_player(t_game *game);

// enemy.c 
void	init_enemies(t_game *game);
void	movement_enemies(t_game *game);

// assets.c 
void	free_assets(t_game *game);
void	load_assets(t_game *game);

// asset_groups.c
void	load_numbers(t_game *game);
void	load_collectables(t_game *game);
void	load_enemy_frames(t_game *game);
void	load_torch_frames(t_game *game);

// asset_utils.c
t_img	*open_img(t_game *game, char *path);

// render_utils.c
void	put_image(t_win *win, t_img *asset, int x, int y);
int		get_random_idx(int column, int row);

// render_map.c
void	draw_background(t_game *game);
void	draw_walls(t_game *game);
void	draw_objects(t_game *game);
void	draw_torches(t_game *game);

// render_entities.c
void	draw_player(t_game *game);
void	draw_enemies(t_game *game);

// render_ui.c
void	draw_hearts(t_game *game);
void	draw_movements(t_game *game);

// events.c
int		close_window(void *param);
int		on_key_press(int key_code, void *param);

// actions.c
void	move_up(t_game *game);
void	move_right(t_game *game);
void	move_left(t_game *game);
void	move_down(t_game *game);

#endif
