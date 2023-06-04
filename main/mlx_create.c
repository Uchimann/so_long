#include "solong.h"

void data_init(t_data *data)
{
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, data->map_width * PNG_SIZE, (data->map_height * PNG_SIZE), "SoLong.h");
    data->coin_collected = 0;
    data->exit_count = 0;
    data->step_count = 0;
    data->wall_count = 0;
    data->player_count = 0;
    data->unwanted_character_count = 0;
	
}

void	image_create(t_data *data)
{
	data->img.bg = mlx_xpm_file_to_image(data->mlx, "../img/background.xpm",
			&data->img.img_w, &data->img.img_h);
	data->img.coin = mlx_xpm_file_to_image(data->mlx, "../img/coin.xpm",
			&data->img.img_w, &data->img.img_h);
	data->img.wall = mlx_xpm_file_to_image(data->mlx, "../img/wall.xpm",
			&data->img.img_w, &data->img.img_h);
	data->img.door = mlx_xpm_file_to_image(data->mlx, "../img/door.xpm",
			&data->img.img_w, &data->img.img_h);
	data->img.character = mlx_xpm_file_to_image(data->mlx, "../img/character.xpm",
			&data->img.img_w, &data->img.img_h);
}

void	map_read_to_data(t_data *data)
{
	int		fd;
	int		i;
	int		j;
	char	*area;

	i = 0;
	j = 0;
	fd = open(data->map_tmp, O_RDONLY);
	map_free(data->map);
	data->map = (char **)malloc(sizeof(char *) * data->map_height);
	while (i < data->map_height)
	{
		j = 0;
		area = get_next_line(fd);
		data->map[i] = (char *)malloc(sizeof(char) * data->map_width);
		if (area == NULL)
			break ;
		while (j < data->map_width)
		{
			data->map[i][j] = area[j];
			j++;
		}
		data->map[i][j] = '\0';
		i++;
		free(area);
	}
}

void	map_background_put(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			mlx_put_image_to_window(data->mlx, data->win, data->img.bg,
				j * PNG_SIZE, i * PNG_SIZE);
			j++;
		}
		i++;
	}
}

void	map_obj_put(t_data *data, int i, int j)
{
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->img.wall,
					j * PNG_SIZE, i * PNG_SIZE);
			else if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, data->img.coin,
					j * PNG_SIZE, i * PNG_SIZE);
			else if (data->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->img.door,
					j * PNG_SIZE, i * PNG_SIZE);
			else if (data->map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx, data->win, data->img.character,
					j * PNG_SIZE, i * PNG_SIZE);
			j++;
		}
		i++;
	}
}

void mlx_create(t_data *data)
{
	printf("\n data coin count \n \n %d \n", data->coin_count);
    data_init(data); // çalışıyor
    image_create(data); // çalışıyor
    map_read_to_data(data); // çalışıyor
    map_background_put(data); // çalışıyor
	map_obj_put(data, 0, 0); // çalışıyor
	wall_control(data); // çalışıyor
    
	
	hook(data);

	mlx_loop(data->mlx);
}
