#include "ft_ls.h"

void    symbolic_link(struct stat sb)
{
        ft_putnbr(sb.st_nlink);
}
