#include "so_long.h"


void    check_coins(char **map, info *info)
{
    int j;
    int i;

    j = 0;
    while (j < info->high)
    {
        i = 0;
        while (i < info->size)
        {
            if (map[j][i] == 'C')
            {
                if (check_path_to_P(map, j, i, 'C', 1, info) != 1)
                {
                    ft_printf("there is no Valid path from the player to the coins");
                    ft_free_arr(map);
		            exit(1);
                }
                reset_map(map, info);
            }
            i++;
        }
        j++;
    }
    put_images(info);
}

void    check_exit(char **map, info *info)
{
    int i;
    int j;

    j = 0;
    while (j < info->high)
    {
        i = 0;
        while (i < info->size)
        {
            if (map[j][i] == 'E')
            {
                if (check_path_to_P(map, j, i, 'P', 1, info) != 1)
                {
                    ft_printf("there is no valid path from the player to the exit ");
		            ft_free_arr(info->map);
                    exit (1);
                }
            }
            i++;
        }
        j++;
    }
    reset_map(map, info);
    check_coins(map, info);
}

void    count_elements(char **map,  info *info)
{
    int i;
    int j;

    j = 0;
    info->c = 0;
    info->e = 0;
    info->p = 0;
    while (j < info->high)
    {
        i = 0;
        while (i < info->size)
        {
            if (map[j][i] == 'P')
                info->p++;
            if (map[j][i] == 'C')
                info->c++;
            if (map[j][i] == 'E')
                info->e++;
            i++;
        }
        j++;
    }
    check_elements(info);
    check_exit(map, info);
}

void    verify_elements(char **map,  info *info)
{
    int i;
    int j;

    j = 0;
    while (j < info->high)
    {
        i = 0;
        while(map[j][i])
        {
            if (map[j][i] != 'P' && map[j][i] != 'C' && map[j][i] != '0' && map[j][i] != '1' && map[j][i] != 'E')
            {
                ft_printf("the map contain an element other than ('0', '1', 'P', 'C', 'E')");
	    	    ft_free_arr(info->map);
                exit (1);
            }
            i++;
        }
        j++;
    }
    check_angle(map, info);
    check_borders(map, info);
    count_elements(map, info);  
}

void translate_map(char *name)
{
    char *temp;
    info info;
    int i;

    info.fd = open(name, O_RDONLY);
    info.high = 0;
    temp = get_the_map_in_oneline(&info);
    i = ft_strlen(temp);
    if (temp[i - 1] == '\n')
    {
        ft_printf("There is an empty line in the end of the file ");
        free(temp);
        exit (1);
    }
    if (temp == NULL)
    {
        ft_printf("The file containing the map is wrong");
        exit(1);
    }
    printf("this is th einfo high   %d", info.high);
    info.map = ft_split(temp, '\n');
    free(temp);
    verify_elements(info.map, &info);
    ft_free_arr(info.map);
}
