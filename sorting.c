#include "ft_ls.h"

void    swap(char **str1, char **str2)
{
        char *temp;

        temp = *str1;
        *str1 = *str2;
        *str2 = temp;
}

void    asci_value(char **arr)
{
        int i;
        int i2;
        int i3;

        i = 0;
        i2 = 0;
        while (arr[i])
                i++;
        while (i2 < i)
        {
                i3 = 0;
                while (i3 + 1 < i)
                {
                        
                        if (ft_strcmp(arr[i3], arr[i3 + 1]) > 0)
                                swap(&arr[i3], &arr[i3 + 1]);
                        i3++;
                }
                i2++;
        }
}

void    reverse_arr(char **arr)
{
        int i = 0;
        int j = 0;
        while (arr[i])
                i++;
        i--;
        while (j < i)
                swap(&arr[i--], &arr[j++]);
}
/*
void    reverse_arr(char **arr)
{
        int i;
        int i2;
        int i3;

        i = 0;
        i2 = 0;
        while(arr[i])
                i++;
        while (i2 < i)
        {
                i3 = 0;
                while (i3 + 1 < i)
                {
                        if (ft_strcmp(arr[i3], arr[i3 + 1]) < 1)
                                swap(&arr[i3], &arr[i3 + 1]);
                        i3++;
                }
                i2++;
        }
}
*/


void time_sorting(char **arr)
{
        struct stat sb1;
        struct stat sb2;
//        struct stat name = malloc(sizeof(struct stat));
        int i;
        int i2;
        int i3;

        i = 0;
        i2 = 0;
        while (arr[i])
        {
                lstat(arr[i], &sb1);
                lstat(arr[i], &sb2);
                i++;
        }
        while (i2 < i)
        {
                i3 = 0;
                while (i3 + 1 < i)
                {
                        lstat(arr[i3], &sb1);
                        lstat(arr[i3 + 1], &sb2);

                        if (sb1.st_mtime < sb2.st_mtime)
                                swap(&arr[i3], &arr[i3 + 1]);
                        else
                        {
                                if (sb1.st_mtime == sb2.st_mtime)
                                {
                                        if (sb1.st_mtim.tv_nsec < sb2.st_mtim.tv_nsec)
                                                swap(&arr[i3], &arr[i3 + 1]);
                                }
                                i3++;
                        }
                        //i3++;
                }
                i2++;
        }
//        i2++;
}