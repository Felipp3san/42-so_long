/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:33:01 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/18 17:29:51 by fde-alme         ###   ########.fr       */
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

int	parse_map(t_map *map)
{
	char	*line;
	int		i;
	int		j;

	map->fd = open_map(map->name);
	map->map = (char **) malloc(sizeof(char *) * map->rows);
	if (!map->map)
		return (MALLOC_ERROR);
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		map->map[i] = (char *) malloc(map->columns + 1);
		if (!map->map[i])
			return (free_map(map), MALLOC_ERROR);
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
	return (SUCCESS);
}

void	get_map_info(t_map *map, char *map_name)
{
	char	*line;
	int		i;

	map->name = map_name;
	map->rows = 0;
	map->columns = 0;
	map->redraw = 1;
	map->collectables = 0;
	map->door_closed = 1;
	map->fd = open_map(map->name);
	line = get_next_line(map->fd);
	while (line)
	{
		i = 0;
		while (line[i] && line[i] != '\n')
		{
			if (line[i] == 'C')
				map->collectables++;
			i++;
			if (i > map->columns)
				map->columns++;
		}
		free(line);
		line = get_next_line(map->fd);
		map->rows++;
	}
	close(map->fd);
}
