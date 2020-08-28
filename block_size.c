#include "ft_ls.h"

void    block_size(char **list)
{
        struct stat sb;
        int         total;
        int i;
        int len;

        i = 0;
        total = 0;
        len = 0;
        while (list[len])
                len++;
        while (i < len)
        {
                lstat(list[i], &sb);
                total = total + sb.st_blocks;
                i++;
        }
        ft_putstr("total ");
        ft_putnbr(total / 2);
}
