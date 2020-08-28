#include "ft_ls.h"

void    print_l(char **list, struct options *flags)
{
        if (flags->l == 1)
                long_format(list);
        else
                printing_ls(list);
}
