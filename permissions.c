#include "ft_ls.h"

void    filetype(struct stat sb)
{
        if (S_ISDIR(sb.st_mode))
                ft_putchar('d');
        if (S_ISREG(sb.st_mode))
                ft_putchar('-');
        if (S_ISCHR(sb.st_mode))
                ft_putchar('c');
        if (S_ISBLK(sb.st_mode))
                ft_putchar('b');
        if (S_ISFIFO(sb.st_mode))
                ft_putchar('f');
        if (S_ISLNK(sb.st_mode))
                ft_putchar('l');
        if (S_ISSOCK(sb.st_mode))
                ft_putchar('s'); 
}

void    ft_permissions(struct stat sb)
{
        ft_putstr((sb.st_mode & S_IRUSR) ? "r" : "-");
        ft_putstr((sb.st_mode & S_IWUSR) ? "w" : "-");
        if (sb.st_mode & S_IXUSR)
        {
                if ((sb.st_mode & S_ISUID) && (sb.st_mode & S_IXUSR))
                {
                        ft_putstr("s");
                }
                else
                        ft_putstr("x");

        }
        else if ((sb.st_mode & S_ISUID) && (!(sb.st_mode & S_IXUSR)))
        {
                ft_putstr("S");
        }
        else 
                ft_putstr("-");
        ft_putstr((sb.st_mode & S_IRGRP) ? "r" : "-");
        ft_putstr((sb.st_mode & S_IWGRP) ? "w" : "-");
        if (sb.st_mode & S_IXGRP)
        {
                if ((sb.st_mode & S_ISGID) && (sb.st_mode & S_IXGRP))
                {
                        ft_putstr("s");
                }
                else
                        ft_putstr("x");
        }
        else if ((sb.st_mode & S_ISGID) && (!(sb.st_mode & S_IXGRP)))
                {
                        ft_putstr("S");
                }
        else
                ft_putstr("-");
        ft_putstr((sb.st_mode & S_IROTH) ? "r" : "-");
        ft_putstr((sb.st_mode & S_IWOTH) ? "w" : "-");
        if (sb.st_mode & S_IXOTH)
        {
                if ((sb.st_mode & S_ISVTX) && (sb.st_mode & S_IXOTH))
                {
                        ft_putstr("t");
                }
                else
                        ft_putstr("x");
        }
        else if ((sb.st_mode & S_ISVTX) && (!(sb.st_mode & S_IXOTH)))
        {
                ft_putstr("T");
        }
        else
                ft_putstr("-");
}