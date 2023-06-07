/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icelebi <icelebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:46:51 by icelebi           #+#    #+#             */
/*   Updated: 2023/06/07 17:27:01 by icelebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	recursive_c(char **map, int y, int x)
{
	map[y][x] = '1';
	if (map[y - 1][x] == '0' || map[y - 1][x] == 'C')
		recursive_c(map, y - 1, x);
	if (map[y][x + 1] == '0' || map[y][x + 1] == 'C')
		recursive_c(map, y, x + 1);
	if (map[y + 1][x] == '0' || map[y + 1][x] == 'C')
		recursive_c(map, y + 1, x);
	if (map[y][x - 1] == '0' || map[y][x - 1] == 'C')
		recursive_c(map, y, x - 1);
	if (param_count(map) == 0)
		return (1);
	else
		return (0);
}

int	param_count(char **map)
{
	int	counter;
	int	i;
	int	j;

	i = 0;
	counter = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				counter++;
			j++;
		}
		i++;
	}
	return (counter);
}

int	recursive_e(char **map, int y, int x)
{
	map[y][x] = '1';
	if (map[y - 1][x] == '0' || map[y - 1][x] == 'C' || map[y - 1][x] == 'E')
		recursive_e(map, y - 1, x);
	if (map[y][x + 1] == '0' || map[y][x + 1] == 'C' || map[y][x + 1] == 'E')
		recursive_e(map, y, x + 1);
	if (map[y + 1][x] == '0' || map[y + 1][x] == 'C' || map[y + 1][x] == 'E')
		recursive_e(map, y + 1, x);
	if (map[y][x - 1] == '0' || map[y][x - 1] == 'C' || map[y][x - 1] == 'E')
		recursive_e(map, y, x - 1);
	if (param_count(map) == 0)
		return (1);
	else
		return (0);
}

int	exit_count(char **map)
{
	int	counter;
	int	i;
	int	j;

	i = 0;
	counter = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				counter++;
			j++;
		}
		i++;
	}
	return (counter);
}

void	map_free(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
