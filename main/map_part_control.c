/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_part_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icelebi <icelebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:36:05 by icelebi           #+#    #+#             */
/*   Updated: 2023/06/07 18:34:30 by icelebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ber_control(char *map_name)
{
	int	i;
	int	count;

	i = ft_strlen(map_name) - 5;
	count = 0;
	while (map_name[i])
	{
		if (map_name[i] == '.')
			count++;
		else if (map_name[i] == 'b')
			count++;
		else if (map_name[i] == 'e')
			count++;
		else if (map_name[i] == 'r')
			count++;
		i++;
	}
	if (count == 4)
		ft_printf("Map is succesfuly loaded !");
	else
		err_msg("What the f*ck !! Your map is trash. Be sure it is .ber file");
}

void	min_part_control(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->pcheck = 0;
	data->echeck = 0;
	data->ccheck = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
				data->pcheck += 1;
			else if (data->map[i][j] == 'E')
				data->echeck += 1;
			else if (data->map[i][j] == 'C')
				data->ccheck += 1;
			j++;
		}
		i++;
	}
	data->coin_count = data->ccheck;
	if (data->pcheck != 1 || data->echeck != 1 || data->ccheck == 0)
		err_msg("map have not requirement minimum part of 'P','C', 'E'");
}

void	bad_part_control(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] && argv[i][j] != '\n')
		{
			if ((argv[i][j] == 'P' || argv[i][j] == 'E' || argv[i][j] == 'C'
					|| argv[i][j] == '1' || argv[i][j] == '0'))
				j++;
			else
				err_msg("There are i dont want parts at map");
		}
		i++;
	}
	ft_printf("There are correct parts at map -> Only 'P','E', 'C', '1', '0' ");
}

int	control(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n')
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}
