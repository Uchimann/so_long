/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icelebi <icelebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:02:36 by icelebi           #+#    #+#             */
/*   Updated: 2023/06/07 18:39:28 by icelebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	err_msg(char *str)
{
	ft_printf("%s", str);
	exit(0);
}
// player x ve y konumunu alıyor

void	wall_control(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < data->map_width)
		if (data->map[0][x++] != '1')
			err_msg("Error : The map has to be surrounded by walls");
	while (y < data->map_height)
	{
		if (data->map[y][0] != '1' || data->map[y][data->map_width - 1] != '1')
			err_msg("Error : The map has to be surrounded by walls");
		y++;
	}
	x = 0;
	while (x < data->map_width)
		if (data->map[data->map_height - 1][x++] != '1')
			err_msg("Error : The map has to be surrounded by walls");
}

char	**read_map(char *mapname)
{
	char	**map;
	char	*str;
	char	file_path[100] = "../map/";
	int		i;
	int		fd;

	i = 0;
	ft_strcat(file_path, mapname);
	fd = open(file_path, O_RDONLY);
	map = malloc(1000);
	str = get_next_line(fd);
	if (!str)
		return (NULL);
	while (str != NULL)
	{
		map[i] = str;
		str = get_next_line(fd);
		i++;
	}
	close(fd);
	return (map);
}

void	tmp_control(char *map_name)
{
	int	fd;

	fd = open(ft_strjoin("../map/", map_name), O_RDONLY);
	if (fd == -1)
		err_msg("Error : Map file is not found");
	close(fd);
	if (!map_name)
		free(map_name);
}

void	size_control(t_data *data)
{
	char	*line;
	int		fd;
	int		x;
	int		y;

	y = 0;
	fd = open(data->map_tmp, O_RDONLY);
	line = get_next_line(fd);
	x = ft_strlen(line);
	while (1)
	{
		free(line);
		y++;
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (x != (int)ft_strlen(line))
			err_msg("Error: Map is not rectangular");
	}
	if (!line)
		free(line);
	data->map_width = x - 1;
	data->map_height = y;
	close(fd);
}
