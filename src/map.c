/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:33:01 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/18 04:30:53 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_map(char *map_name)
{
	int	fd;
	
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	return (fd);
}

void	free_map(t_map *map)
{
	int	row;

	row = 0;
	if (!map->map)
		return ;
	while (row < map->rows)
	{
		free(map->map[row]);
		row++;
	}
	free(map->map);
}

void	parse_map(t_map *map)
{
	char	*line;
	int		i;
	int		j;

	map->fd = open_map(map->name);
	map->map = (char **) malloc(sizeof(char *) * map->rows);
	if (!map->map)
		return ;
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		map->map[i] = (char *) malloc(map->columns + 1);
		if (!map->map[i])
		{
			free_map(map);
			return ;
		}
		line = get_next_line(map->fd);
		while (line[j] && line[j] != '\n')
		{
			map->map[i][j] = line[j];
			j++;
		}
		free(line);
		i++;
	}
	close(map->fd);
}

void	get_player_location(t_map *map)
{
	int	row;
	int	column;

	map->player_location.row = 0;
	map->player_location.column = 0;
	row = 0;
	while (row < map->rows)
	{
		column = 0;
		while (column < map->columns)
		{
			if (map->map[row][column] == 'P')
			{
				map->player_location.column = column;
				map->player_location.row = row;
				break;
			}
			column++;
		}
		row++;
	}
}

void	get_map_info(t_map *map, char *map_name)
{
	char	*line;
	int		map_fd;

	map->name = map_name;
	map->rows = 0;
	map->columns = 0;
	map_fd = open_map(map->name);
	line = get_next_line(map_fd);
	while (line)
	{
		while (line[map->columns] && line[map->columns] != '\n')
			map->columns++;
		free(line);
		line = get_next_line(map_fd);
		map->rows++;
	}
	close(map_fd);
}
