#include "so_long.h"


int	ft_move_player(int keynum, mlptr *mlptr)
{

		if (keynum == 97 || keynum == 65361)
			ft_change_map_imga(mlptr);
		if (keynum == 115 || keynum == 65364)
				ft_change_map_imgs(mlptr);
		if (keynum == 100 || keynum == 65363)
			ft_change_map_imgd(mlptr);
		if (keynum == 119 || keynum == 65362)
			ft_change_map_imgw(mlptr);
		if (keynum == 65307)
		{	
			ft_free_mlptr(mlptr, 'Y');
			exit(1);
		}
		printf("the player moves   %d\n", mlptr->moves);
	return(0);
}

void ft_put_image_in_win(info *info, mlptr *mlptr, int x, int y)
{
	int a;
	int b; 
	int i;
	int j;

	j = 0;
	b = 0;
	while (j < y)
	{
		i = 0;
		a = 0;
		while (i < x)
		{
			if (info->map[b][a] == '1')
				mlx_put_image_to_window(mlptr->mlx_ptr, mlptr->mlx_wind, mlptr->imgw, i, j);
			if (info->map[b][a] == '0')
				mlx_put_image_to_window(mlptr->mlx_ptr, mlptr->mlx_wind, mlptr->imgs, i, j);
			if (info->map[b][a] == 'P')
				mlx_put_image_to_window(mlptr->mlx_ptr, mlptr->mlx_wind, mlptr->imgpmr, i, j);
			if (info->map[b][a] == 'C')
				mlx_put_image_to_window(mlptr->mlx_ptr, mlptr->mlx_wind, mlptr->imgc, i, j);
			if (info->map[b][a] == 'E')
				mlx_put_image_to_window(mlptr->mlx_ptr, mlptr->mlx_wind, mlptr->imge, i, j);
			i = i + 50;
			a++;
		}
		j = j + 50;
		b++;
	}
}
void ft_put_border_images(mlptr *mlptr,info *info, int x, int y)
{
	int i;
	int j;
	int a;
	int b;

	b = 0;
	j = 0;
	a = 0;
	i = 0;
	printf("this is y%d and x%d", y, x );

	while (i < x)
	{
		info->map[b][a] = 'x';
		info->map[y / 50 - 1][a] = 'x';
		mlx_put_image_to_window(mlptr->mlx_ptr, mlptr->mlx_wind, mlptr->imgw, i, 0);
		mlx_put_image_to_window(mlptr->mlx_ptr, mlptr->mlx_wind, mlptr->imgw, i, y - 50);
		i = i + 50;
		a++;
	}
	a = 0;
	while(j < y)
	{
		info->map[b][a] = 'x';
		info->map[b][x / 50 - 1] = 'x';
		mlx_put_image_to_window(mlptr->mlx_ptr, mlptr->mlx_wind, mlptr->imgw, 0, j);
		mlx_put_image_to_window(mlptr->mlx_ptr, mlptr->mlx_wind, mlptr->imgw, x - 50, j);
		j = j + 50;
		b++;
	}
}

void put_images(info *info)
{
	int		img_width ;
	int		img_height;
	mlptr	mlptr;
	int 	x;
	int 	y;

	x = 50 * info->size;
	y = 50 * info->high;
	mlptr.mlx_ptr = mlx_init();
	mlptr.imgw = mlx_xpm_file_to_image(mlptr.mlx_ptr, "./textures/wall.xpm", &img_width, &img_height);
	mlptr.imgpmu = mlx_xpm_file_to_image(mlptr.mlx_ptr, "./textures/moveup.xpm", &img_width, &img_height);
	mlptr.imgpmd = mlx_xpm_file_to_image(mlptr.mlx_ptr, "./textures/movedown.xpm", &img_width, &img_height);
	mlptr.imgpmr = mlx_xpm_file_to_image(mlptr.mlx_ptr, "./textures/moveright.xpm", &img_width, &img_height);
	mlptr.imgpml = mlx_xpm_file_to_image(mlptr.mlx_ptr, "./textures/moveleft.xpm", &img_width, &img_height);
	mlptr.imgc = mlx_xpm_file_to_image(mlptr.mlx_ptr, "./textures/coins.xpm", &img_width, &img_height);
	mlptr.imgs = mlx_xpm_file_to_image(mlptr.mlx_ptr, "./textures/space.xpm", &img_width, &img_height);
	mlptr.imge = mlx_xpm_file_to_image(mlptr.mlx_ptr, "./textures/door.xpm", &img_width, &img_height);
	mlptr.imger = mlx_xpm_file_to_image(mlptr.mlx_ptr, "./textures/eatright.xpm", &img_width, &img_height);
	mlptr.imgel = mlx_xpm_file_to_image(mlptr.mlx_ptr, "./textures/eatleft.xpm", &img_width, &img_height);
	mlptr.imgeu = mlx_xpm_file_to_image(mlptr.mlx_ptr, "./textures/eatup.xpm", &img_width, &img_height);
	mlptr.imged = mlx_xpm_file_to_image(mlptr.mlx_ptr, "./textures/eatdown.xpm", &img_width, &img_height);
		//mlptr.imgdr = mlx_xpm_file_to_image(mlptr.mlx_ptr, "./textures/middleborder.xpm", &img_width, &img_height);
		// mlptr.imgrc = mlx_xpm_file_to_image(mlptr.mlx_ptr, "./textures/eatdown.xpm", &img_width, &img_height);
		// mlptr.imglc = mlx_xpm_file_to_image(mlptr.mlx_ptr, "./textures/eatdown.xpm", &img_width, &img_height);
		// mlptr.imgdl = mlx_xpm_file_to_image(mlptr.mlx_ptr, "./textures/eatdown.xpm", &img_width, &img_height);
		// mlptr.imgdr = mlx_xpm_file_to_image(mlptr.mlx_ptr, "./textures/eatdown.xpm", &img_width, &img_height);			
	
	if (mlptr.imgw == NULL || mlptr.imgpmu == NULL || mlptr.imgc == NULL || mlptr.imgs == NULL || mlptr.imge == NULL)
	{
		ft_free_mlptr(&mlptr, 'N');
		ft_free_arr(info->map);
		exit(1);
	}
	mlptr.mlx_wind = mlx_new_window(mlptr.mlx_ptr, x , y, "this my wind test");
	ft_put_border_images(&mlptr, info, x, y);
	ft_put_image_in_win(info, &mlptr, x , y);
	ft_get_player_pos(info, &mlptr);
	mlptr.moves = 0;
	mlx_key_hook(mlptr.mlx_wind, &ft_move_player, &mlptr);
    mlx_loop(mlptr.mlx_ptr);
} 
