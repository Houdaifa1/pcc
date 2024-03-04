#include "so_long.h"

void    check_elements(info *info)
{
    if (info->p != 1)
    {
        if (info->p < 1)
		    ft_printf("You need to enter the Player : 'P'");            
	    else
		    ft_printf("You should enter just one Player");
	    ft_free_arr(info->map);
	    exit (1);
    }
    if (info->e != 1)
    {
        if (info->e < 1)
            ft_printf("You need to enter the Exit : 'E'");
	    else
            ft_printf("You need to enter just one Exit");
        ft_free_arr(info->map);
	    exit(1);
    }
    if (info->c < 1)
    {
        ft_printf("You need to enter the coins in the map : 'C'");
	    ft_free_arr(info->map);
        exit (1);
    }
}