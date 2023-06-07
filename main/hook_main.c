/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icelebi <icelebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 09:04:59 by icelebi           #+#    #+#             */
/*   Updated: 2023/06/07 18:24:15 by icelebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	press(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img.bg, data->player_x
		* PNG_SIZE, data->player_y * PNG_SIZE);
	mlx_put_image_to_window(data->mlx, data->win, data->img.character,
		data->player_x * PNG_SIZE, data->player_y * PNG_SIZE);
	if (data->map[data->exit_y][data->exit_x])
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img.door,
			data->exit_x * PNG_SIZE, data->exit_y * PNG_SIZE);
		mlx_put_image_to_window(data->mlx, data->win, data->img.character,
			data->player_x * PNG_SIZE, data->player_y * PNG_SIZE);
	}
	return (0);
}

int	exit_door(t_data *data)
{
	if (data->coin_collected == data->coin_count)
	{
		ft_printf("\n>>>>Toplam Hareket: %d\n", data->step_count);
		err_msg("FINISH");
	}
	else if (data->coin_collected != data->coin_count)
		return (1);
	return (0);
}
