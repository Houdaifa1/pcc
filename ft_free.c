# include "so_long.h"


void ft_free_arr(char **map)
{
	int i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i++]);
	}
	free(map);
}

void ft_free_mlptr(mlptr *mlptr, char c)
{	
			if (mlptr->imgw)
				mlx_destroy_image(mlptr->mlx_ptr, mlptr->imgw);
			if (mlptr->imgpmr)
				mlx_destroy_image(mlptr->mlx_ptr, mlptr->imgpmr);
			if (mlptr->imgc)
			 	mlx_destroy_image(mlptr->mlx_ptr, mlptr->imgc);
			if (mlptr->imgs)
				mlx_destroy_image(mlptr->mlx_ptr, mlptr->imgs);
			if (mlptr->imge)
				mlx_destroy_image(mlptr->mlx_ptr, mlptr->imge);
			if (c == 'Y')
			{
				mlx_destroy_window(mlptr->mlx_ptr, mlptr->mlx_wind);
				ft_free_arr(mlptr->map);
			}			
			mlx_destroy_display(mlptr->mlx_ptr);
			free(mlptr->mlx_ptr);
}

