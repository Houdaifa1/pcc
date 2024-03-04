#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "./minilibx-linux/mlx.h"
#include <limits.h>
#include <stdarg.h>

#define widght 500
#define height 500
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 20
#endif

typedef struct mlptr
{
    void *mlx_ptr;
    void *mlx_wind;
    void *imgw;
    void *imgs;
    void *imgpmu;
    void *imgpmd;
    void *imgpmr;
    void *imgpml;
    void *imgeu;
    void *imged;
    void *imgel;
    void *imger;
    void *imgc;
    void *imge;
    int pi;
    int pj;
    int c;
    int moves;
    char **map;
    int high;
    void *imgmb;
    void *imgrc;
    void *imglc;
    void *imgdl;
    void *imgdr;
} mlptr;

typedef struct info
{
    int size;
    int high;
    char **map;
    char *line;
    int p;
    int c;
    int e;
    int fd;

} info;

char *ft_strjoin(char const *s1, char const *s2);

void *ft_calloc(size_t count, size_t size);

void *ft_calloc(size_t count, size_t size);

void ft_bzero(void *s, size_t n);

size_t ft_strlen(const char *s);

int ft_strchr(const char *s, int c);

char *get_next_line(int fd);

void translate_map(char *name);

void ft_free_arr(char **map);

char **ft_split(char const *s, char c);

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);

int ft_putchar(char c);

int ft_putstr(char *str);

int ft_printf(const char *format, ...);

int check_path_to_P(char **map, int j, int i, char x, int r, info *info);

void reset_map(char **map, info *info);

void check_borders(char **map, info *info);

void check_angle(char **map, info *info);

void put_images(info *info);

void check_elements(info *info);

void count_elements(char **map, info *info);

void ft_get_player_pos(info *info, mlptr *mlptr);

void ft_change_map_imga(mlptr *mlptr);

void ft_change_map_imgs(mlptr *mlptr);

void ft_change_map_imgd(mlptr *mlptr);

void ft_change_map_imgw(mlptr *mlptr);

void ft_free_mlptr(mlptr *mlptr, char c);

void ft_get_images(mlptr *mlptr);

char *get_the_map_in_oneline(info *info);

#endif
