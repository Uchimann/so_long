/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icelebi <icelebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:44:43 by icelebi           #+#    #+#             */
/*   Updated: 2023/06/07 18:24:05 by icelebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	step_count(t_data *data)
{
	data->step_count++;
	ft_printf("Step: %d\r", data->step_count);
}

static int	real_walking(int y, int x, t_data *data)
{
	if (data->map[data->player_y + y][data->player_x + x] == '1')
		return (0);
	else if (data->map[data->player_y + y][data->player_x + x] == 'C')
	{
		data->map[data->player_y + y][data->player_x + x] = '0';
		data->coin_collected++;
	}
	else if (data->map[data->player_y + y][data->player_x + x] == 'E')
	{
		if (data->coin_collected == data->coin_count)
		{
			exit_door(data);
			return (0);
		}
	}
	return (1);
}

static int	walking(int keycode, t_data *data, int x)
{
	if (keycode == 0 || keycode == 2)
	{
		if (real_walking(0, x, data) == 0)
			return (0);
		mlx_put_image_to_window(data->mlx, data->win, data->img.bg,
			data->player_x * PNG_SIZE, data->player_y * PNG_SIZE);
		data->player_x += x;
	}
	if (keycode == 13 || keycode == 1)
	{
		if (real_walking(-x, 0, data) == 0)
			return (0);
		mlx_put_image_to_window(data->mlx, data->win, data->img.bg,
			data->player_x * PNG_SIZE, data->player_y * PNG_SIZE);
		data->player_y -= x;
	}
	step_count(data);
	press(data);
	return (0);
}

int	mouse_hook(int mousecode, t_data *data)
{
	(void)mousecode;
	(void)data;
	err_msg("Exit Success");
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
		err_msg("Exit Success");
	else if (keycode == 2 || keycode == 13)
		walking(keycode, data, 1);
	else if (keycode == 0 || keycode == 1)
		walking(keycode, data, -1);
	return (0);
}
