/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icelebi <icelebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:24:56 by icelebi           #+#    #+#             */
/*   Updated: 2023/05/31 17:00:48 by icelebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# define PNG_SIZE 50
#include "../libs/minilibx/mlx.h"
#include "../libs/libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "solong.h"

char **read_map(char *mapname);
void ber_control(char *argv);
int part_control(char **argv);
int is_different(char **argv);
void is_rectangular(char **argv);
void err_msg(char *s);
int param_count(char **map);
int recursive_c(char **map, int y, int x);
int recursive_e(char **map, int y, int x);
void map_free(char **map);


typedef struct s_image
{
	char	*character;
	char	*wall;
	char	*coin;
	char	*door;
	char	*bg;
	int		img_w;
	int		img_h;
}			t_image;

typedef struct l_int_map
{
	int	read_count;
}			t_int_map;

typedef struct s_data
{
	char		**map;
	char		*mlx;
	char		*win;
	char		*map_tmp;
	int			map_width;
	int			map_height;
	int			player_x;
	int			player_y;
	int			player_count;
	int			exit_count;
	int			exit_x;
	int			exit_y;
	int			wall_count;
	int			coin_count;
	int			unwanted_character_count;
	int			coin_collected;
	int			step_count;
	t_image		img;
	t_int_map	i_map;

}   t_data;
void	hook(t_data *data);
int	mouse_hook(int mousecode, t_data *data);
int	key_hook(int keycode, t_data *data);
void map_control(char **argv, t_data *data);
void mlx_create(t_data *data);
void wall_control(t_data *data);
int	exit_door(t_data *data);
int	press(t_data *data);
void min_part_control(t_data *data);
void exit_location(t_data *data);
#endif 