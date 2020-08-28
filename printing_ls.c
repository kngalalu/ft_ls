#include "ft_ls.h"

void  printing_ls(char **list)
{
        //struct stat b;
        int i; 

        i = 0;
       // stat(*list, &b);
        // if (argv_count(NULL) > 1 && S_ISDIR(b.st_mode))
        // {
        //         //printf("%",list);
        //         ft_putstr("\n");
	// 	ft_putstr(*list);
	// 	ft_putstr(": \n");
        // }
        while (list[i])
        {
                if (ft_strrchr(list[i], '/'))
                {       
                        ft_putstr(ft_strrchr(list[i], '/')+ 1);
                        ft_putchar('\n');
                }
                else
                {
                        ft_putstr(list[i]);
                        ft_putchar('\n');
                }
                i++;
        }
        //stat(*list, &b);
        // if ((argv_count(NULL) > 1) && (S_ISDIR(b.st_mode)))
        // {
        //         //printf("%",list);
        //         ft_putstr("\n");
	// 	ft_putstr(ft_strchr(*list, '/'));
	// 	ft_putstr(": \n");
        // }
        ft_putchar('\n');
}

