/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icelebi <icelebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:02:36 by icelebi           #+#    #+#             */
/*   Updated: 2023/05/31 17:05:01 by icelebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <string.h>

void err_msg(char *str)
{
    //free(data);
    ft_printf("%s",str);
    exit(0);
}

void ber_control(char *map_name)
{
    int i = ft_strlen(map_name) - 5;
    int count = 0;
    
    while(map_name[i])
    {
        if(map_name[i] == '.')
            count++;
        else if(map_name[i] == 'b')
            count++;
        else if(map_name[i] == 'e')
            count++;
        else if(map_name[i] == 'r')
            count++;
        i++;
    }
    if(count == 4)
        ft_printf("Map is succesfuly loaded !");
    else 
        err_msg("What the f*ck !! Your map is trash. Be sure it is .ber file");
}

void is_rectangular(char **argv)
{
    int i = 1;
    int j = 0;
    
    while(argv[i])
    {
         while(argv[i][j])
        {
            if(i >= 3 && j >= 5) //DEĞİŞECEK
                ft_printf("the map is rectangular");
            else if (i >= 5 && j >= 3)
                ft_printf("the map is rectangular");
            j++;
        }
        i++;
    }
    err_msg("Error\nthe map is not rectangular !!");
}

void min_part_control(t_data *data)
{
    int i = 0;
    int j;
    
    int pcheck = 0;
    int echeck = 0;
    int ccheck = 0;

    while(data->map[i])
    {
        j = 0;
        while(data->map[i][j])
        {
            if(data->map[i][j] == 'P')
                pcheck += 1;
            else if(data->map[i][j] == 'E')
                echeck += 1;
            else if(data->map[i][j] == 'C')         
                ccheck += 1;
            j++;
        }
        i++;
    }
        data->coin_count = ccheck;
       // printf(" \n\n minpart icinde %d\n\n\n\n",data->coin_count);
    if(pcheck != 1 || echeck != 1 || ccheck == 0)
        err_msg("map have not requirement minimum part of 'P','C', 'E'");
    else
    {
        ft_printf("Map have requirement minimum part of 'P','C', 'E' ");
    }
}

void bad_part_control(char **argv)
{
    int i = 0;
    int j;

    while(argv[i])
    {
        j = 0;
        while(argv[i][j] && argv[i][j] != '\n')
        {
            if((argv[i][j] == 'P' || argv[i][j] == 'E' || 
        argv[i][j] == 'C' || argv[i][j] == '1' || argv[i][j] == '0'))
                j++;
            else
               err_msg("There are i dont want parts at map");
        }
        i++;
    }
   ft_printf("There are correct parts at map -> Only 'P','E', 'C', '1', '0' ");
}

//DÜZENLENECEK

int control(char *line)
{
    int i = 0;
    
    while(line[i] != '\n')
       { 
            if(line[i] != '1')
                return (0);
            i++;
       }
       return (1);
}

//player x ve y konumunu alıyor
void player_location(t_data *data)
{
    int i;
    int j;
    i = 0;
    
    while(data->map[i])
    {
        j = 0;
        while(data->map[i][j])
        {
            if(data->map[i][j] == 'P')
            {
                data->player_x = j;
                data->player_y = i;
            }
            j++;
        }
        i++;
    }
}

void exit_location(t_data *data)
{
    int i;
    int j;
    i = 0;
    
    while(data->map[i])
    {
        j = 0;
        while(data->map[i][j])
        {
            if(data->map[i][j] == 'E')
            {
                data->exit_x = j;
                data->exit_y = i;
            }
            j++;
        }
        i++;
    }
}

// aşağıdaki yer eski wallcontrol sonra bir ara bakılacak
/*
void wall_control(char *map_name)
{
    int i;
    int fd;
    
    i = 0;
    fd = open(map_name, O_RDONLY);
    char *line = get_next_line(fd);
    char *tmp = malloc(ft_strlen(line));
    
        if(!tmp || !line)
           return ;
            
    if(control(line))
        {
            i = ft_strlen(line);
            while(line)
            {
                if(line[i - 1] == '1' && line [0] == '1' && line != NULL)
                    {
                        tmp = line;
                        line = get_next_line(fd);
                    }
            }
        }
    if(control(tmp) != 0)
        ft_printf(" Olleyy !the map surrended by wall ! ");
    else 
        err_msg("the map not have the wall enough");
}
*/
//yenisi

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

char **read_map(char *mapname)
{
    char **map;
    char *str;
    int i = 0;
    
    char file_path[100] = "../map/";  // Dosya yolu için "../map/" başlangıcı ekleyin
    strcat(file_path, mapname);  // Dosya adını ekleyin

    int fd = open(file_path, O_RDONLY);

    map = malloc(1000);
    str = get_next_line(fd);
    if(!str)
        return NULL;
    
    while(str != NULL)
    {
        map[i] = str;
        str = get_next_line(fd);
        i++;
    }
    close(fd);
   // map[i] = '\0';
    return map;
}


void	tmp_control(char *map_name)
{
	int		fd;

	fd = open(ft_strjoin("../map/", map_name), O_RDONLY);
	if (fd == -1)
		err_msg("Error : Map file is not found");
	close(fd);
	if (!map_name)
		free(map_name);
}


void size_control(t_data *data)
{
    char *line;
    int fd;
    int x;
    int y;

    y = 0;
    fd = open(data->map_tmp,O_RDONLY);
    line = get_next_line(fd);
    x = ft_strlen(line);

    while(1)
    {
    
     //   if(line != NULL)
            free(line);
        y++;
       // write(1, "\n", 1);
        line = get_next_line(fd);
       // ft_printf("*********%s", line);
        
        if(line == NULL)
            break ;
        if(x != (int)ft_strlen(line))
            err_msg("Error: Map is not rectangular");
    }
    if(!line)
        free(line);
   // write(1, "cc", 2);
    data->map_width = x -1;
    data->map_height = y;
    close(fd);
}


void map_control(char **argv, t_data *data)
{
    char *map_name;
    char *map_names;
    map_name = argv[1];
    map_names = ft_strjoin("map/",map_name);
    data->map_tmp = map_names;
    free(map_names);
    ber_control(argv[1]);
    tmp_control(argv[1]);
   // is_rectangular(argv[1]);
    min_part_control(data);  //çalışıyor
    bad_part_control(data->map); //çalışıyor
    size_control(data); // çalışıyor
    // buraya playerin konumunu öğrenip player_y player_x e atan fonksyion lazım.
    player_location(data);
    exit_location(data);
    
}
