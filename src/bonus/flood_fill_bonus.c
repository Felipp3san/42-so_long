/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:29:16 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/26 12:29:21 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	dfs(t_map *map, char **clone_map, int row, int column)
{
	if (row < 0 || column < 0 || column == map->columns - 1
		|| row == map->rows - 1 || clone_map[row][column] == '1')
		return ;
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
