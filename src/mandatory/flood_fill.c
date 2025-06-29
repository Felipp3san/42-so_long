/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 21:43:23 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/20 00:47:15 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	dfs(t_map *map, char **clone_map, int row, int column)
{
	if (row < 0 || column < 0 || column == map->columns - 1
		|| row == map->rows - 1 || clone_map[row][column] == '1')
		return ;
	if (clone_map[row][column] == 'E')
	{
		clone_map[row][column] = '1';
		return ;
	}
	clone_map[row][column] = '1';
	dfs(map, clone_map, row + 1, column);
	dfs(map, clone_map, row - 1, column);
	dfs(map, clone_map, row, column + 1);
	dfs(map, clone_map, row, column - 1);
}

void	flood_fill(t_map *map, char **clone_map, t_point start)
{
	if (clone_map[start.row][start.column] != 'P')
		return ;
	dfs(map, clone_map, start.row, start.column);
}
