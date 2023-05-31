/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icelebi <icelebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:36:25 by icelebi           #+#    #+#             */
/*   Updated: 2023/05/31 16:39:28 by icelebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int main(int argc, char **argv)
{
    t_data	*data;

    data = malloc(sizeof(t_data));
    data->coin_count = 0;
  
	if (argc != 2)
		err_msg("Error : Argument 2 required");
    data->map = read_map(argv[1]);
    
    map_control(argv, data);
    if (!(recursive_c(data->map, data->player_y, data->player_x)))
        err_msg("Error\nmap is impossible.");
	map_free(data->map);
	data->map = read_map(argv[1]);
	if (!recursive_e(data->map, data->player_y, data->player_x))
	    err_msg("Error\nmap is impossible.");
        
    mlx_create(data);
    
}
