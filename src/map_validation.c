/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 19:14:45 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/19 22:00:40 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_enclosed_by_walls(t_map *map)
{
	int	all_1s;
	int	i;

	all_1s = 1;
	i = 0;
	while (i < map->columns)
	{
		if (map->map[0][i] != '1')
			all_1s = 0;
		if (map->map[map->rows - 1][i] != '1')
			all_1s = 0;
		i++;
	}
	i = 0;
	while (i < map->rows)
	{
		if (map->map[i][0] != '1')
			all_1s = 0;
		if (map->map[i][map->columns - 1] != '1')
			all_1s = 0;
		i++;
	}
	return (all_1s);
}

static int	exit_collectables_lookup(t_map *map, char **clone_map)
{
	int	found;
	int	i;
	int	j;

	i = 0;
	found = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			if(clone_map[i][j] == 'E' || clone_map[i][j] == 'C')
				found = 1;
			j++;
		}
		i++;
	}
	return (found);
}

static int	has_valid_path(t_map *map)
{
	char	**clone_map;
	t_point	start;

	start = get_player_location(map);
	clone_map = ft_clone_map(map);
	if (!clone_map)
		free_map_exit(map, "Failed to clone map.");
	flood_fill(map, clone_map, start);
	if (!exit_collectables_lookup(map, clone_map))
		return (free(clone_map), 1);
	else
		return (free(clone_map), 0);
}

void	validate_map(t_map *map)
{
	if (map->rows == 0)
		free_map_exit(map, "Map is empty.");
	//if (map->rows >= map->columns)
	//	free_map_exit(map, "Map is not rectangular.");
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
}
