/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:33:01 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/21 00:08:58 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_map *map, char *map_name)
{
	map->name = map_name;
	map->rows = 0;
	map->columns = 0;
	map->redraw = 1;
	map->collectable_count = 0;
	map->exit_count = 0;
	map->player_count = 0;
	map->door_state = CLOSED;
}

int	parse_map(t_map *map)
{
	char	*line;
	int		map_fd;
	int		i;

	map_fd = open_map(map->name);
	map->map = (char **) malloc(sizeof(char *) * map->rows);
	if (!map->map)
		return (MALLOC_ERROR);
	i = 0;
	while (i < map->rows)
	{
		map->map[i] = (char *) malloc(map->columns + 1);
		if (!map->map[i])
			return (free_map(map), MALLOC_ERROR);
		line = get_next_line(map_fd);
		if (line)
		{
			ft_strlcpy(map->map[i], line, ft_strlen(line));
			free(line);
		}
		i++;
	}
	close(map_fd);
	return (0);
}

static void	count_map_tile(t_map *map, char tile)
{
	if (tile == 'C')
		map->collectable_count++;
	else if (tile == 'E')
		map->exit_count++;
	else if (tile == 'P')
		map->player_count++;
}

void	extract_map_info(t_map *map)
{
	char	*line;
	int		map_fd;
	int		i;

	map_fd = open_map(map->name);
	line = get_next_line(map_fd);
	while (line)
	{
		i = 0;
		while (line[i] && line[i] != '\n')
		{
			count_map_tile(map, line[i]);
			i++;
			if (i > map->columns)
				map->columns++;
		}
		free(line);
		line = get_next_line(map_fd);
		map->rows++;
	}
	close(map_fd);
}

void	validate_map(t_map *map)
{
	if (map->rows == 0)
		free_map_exit(map, "Map is empty.");
	if (!has_equal_rows(map))
		free_map_exit(map, "Map is not rectangular.");
	if (map->exit_count > 1)
		free_map_exit(map, "Map has more than 1 exit.");
	if (map->exit_count == 0)
		free_map_exit(map, "Map has no exit.");
	if (map->player_count > 1)
		free_map_exit(map, "Map has more than 1 player.");
	if (map->player_count == 0)
		free_map_exit(map, "Map has no player.");
	if (map->collectable_count < 1)
		free_map_exit(map, "Map has no collectables.");
	if (!is_enclosed_by_walls(map))
		free_map_exit(map, "Map is not enclosed by walls.");
	if (!has_valid_path(map))
		free_map_exit(map, "Map has no valid path.");
	if (has_invalid_tiles(map))
		free_map_exit(map, "Map is not valid.");
}
