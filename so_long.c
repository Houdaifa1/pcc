# include "so_long.h"

int main(int arc, char **arv)
{
    int i;
    int j;
    char    *name;

    i = 0;
    j = 3;
    name = ".ber";
    if (arc == 2)
    {
        i = ft_strlen(arv[1]) - 1;
        while(j >= 0)
        {
            if (arv[1][i] != name[j])
            {
                ft_printf("The extention of the file contaning the map is wrong");
                exit (1);
            }
            j--;
            i--;
        }
        translate_map(arv[1]);
    }
    else
        ft_printf("Number of arguments not correct");
    return(0);
}
