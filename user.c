#include "ft_ls.h"

void    user_id(struct stat sb)
{
        struct passwd   *b1;

        b1 = getpwuid(sb.st_uid);
        ft_putstr(b1->pw_name);
}

void    group_id(struct stat sb)
{
        struct group  *b2;

        b2 = getgrgid(sb.st_gid);
        ft_putstr(b2->gr_name);
}

void    file_size(struct stat sb)
{
        ft_putnbr(sb.st_size);
}
