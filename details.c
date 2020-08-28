#include "ft_ls.h"


void long_format(char **list)
{
        char *s1;
        char *linkname;
        ssize_t r;
        struct stat sb;
        int x;

        x = 0;
        block_size(list);
        ft_putchar('\n');
      
        int i;

        i = 0;
        while (list[i])
        {
                lstat(list[i], &sb);
                filetype(sb);
                ft_permissions(sb);
                ft_putchar('\t');
                symbolic_link(sb);
                ft_putchar('\t');
                user_id(sb);
                ft_putchar('\t');
                group_id(sb);
                ft_putchar('\t');
                file_size(sb);
                ft_putchar ('\t');
                s1 = ft_strsub(ctime(&sb.st_mtime),4,12);
                ft_putstr(s1);
                ft_putchar('\t');
                (ft_strrchr(list[i], '/')) ? ft_putstr(ft_strrchr(list[i], '/') + 1) : ft_putstr(list[i]);
                linkname = malloc(sb.st_size + 1);
                r = readlink(list[i], linkname, sb.st_size +1);
                linkname[sb.st_size] = '\0';
                x = (sb.st_mode & S_IFLNK);
                if (x > 0 && S_ISLNK(sb.st_mode))
                {
                        ft_putstr(" -> ");
                        ft_putstr(linkname);
                }
                ft_putchar('\n');
                i++;
                free(s1);
                free(linkname);
      }
}

