#include "ft_ls.h"

void    flag_check(char **argv, struct options *flags, int k)
{
        int i;
        int i2;
        
        i = 1;
        while (i < k)
        {
                i2 = 1;
                while (argv[i][i2])
                {
                        if (argv[i][i2] == 'a')
                                flags->a = 1;
                        else if (argv[i][i2] == 'l')
                                flags->l = 1;
                        else if (argv[i][i2] == 'r')
                                flags->r = 1;
                        else if (argv[i][i2] == 't')
                                flags->t = 1;
                        else if (argv[i][i2] == 'R')
                                flags->kk = 1;
                        else if (argv[i][i2] == '1')
                                flags->n = 1;
                        else
                        {
                                if (argv[i][i2] != 'a' && argv[i][i2] != 'l' && argv[i][i2] != 't' 
                                                && argv[i][i2] != 'r' && argv[i][i2] != 'R' && argv[i][i2] != '1')
                                {
                                        ft_putstrx3("ft_ls : illegal option '", argv[i], "' usage : ft_ls [-altr1] [file...]");
                                        ft_putchar('\n');
                                        exit(1);
                                }
                        }
                        i2++;
                }
                i++;
        }
}