/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icelebi <icelebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:28:54 by icelebi           #+#    #+#             */
/*   Updated: 2023/06/07 17:38:04 by icelebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	data_init(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->map_width * PNG_SIZE,
			(data->map_height * PNG_SIZE), "SoLong.h");
	data->coin_collected = 0;
	data->exit_count = 0;
	data->step_count = 0;
	data->wall_count = 0;
	data->player_count = 0;
	data->unwanted_character_count = 0;
}
