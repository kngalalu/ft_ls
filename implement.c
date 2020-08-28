#include "ft_ls.h"

void    implement(char **argv, char **folders, char **list)
{
        int i = 1;
        int leng = 1;
        struct stat sb;
        int x;
        int f = 0;
        int lst = 0;
        DIR *dp;
        
        while (argv[i] && argv[i][0] == '-')
        {
                i++;
                leng++;
        }
        
        while (argv[i])
        {
                if (error101(argv[i]) != 0)
                {
                        ft_putstr("ls: cannot open directory '");
			//ft_putstr("'");
			ft_putstr(argv[i]);
			//ft_putstr("'");
			//ft_putchar(' ');
			ft_putstr("' : ");
			ft_putstr(strerror(errno));
			ft_putchar('\n');
                }
                if (lstat(argv[i], &sb)== -1)
                {
                        ft_putstrx3("ft_ls: cannot access '", argv[i], "' : No such files or directory ");
                        ft_putchar('\n');
                }
                // else{
                //         S_ISDIR(sb.st_mode) ? folders[f++] = argv[i] : list[lst++] = argv[i];
                // }
                else if (lstat(argv[i], &sb) != -1)
                {
                        x = S_ISDIR(sb.st_mode) ? 1: 0;
                        if (x == 1)
                        {
                                folders[f] = argv[i];
                                f++;
                        }
                        else if (x == 0)
                        {
                                list[lst] = argv[i];
                                lst++;
                        }
                }
                i++;
        }
        folders[f] = '\0';
        list[lst] = '\0';
}