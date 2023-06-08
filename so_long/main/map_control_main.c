/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icelebi <icelebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:39:14 by icelebi           #+#    #+#             */
/*   Updated: 2023/06/07 17:39:25 by icelebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	map_control(char **argv, t_data *data)
{
	char	*map_name;
	char	*map_names;

	map_name = argv[1];
	map_names = ft_strjoin("map/", map_name);
	data->map_tmp = map_names;
	free(map_names);
	ber_control(argv[1]);
	tmp_control(argv[1]);
	min_part_control(data);
	bad_part_control(data->map);
	size_control(data);
	player_location(data);
	exit_location(data);
}
