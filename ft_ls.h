#ifndef FT_LS_H
# define FT_LS_H

#include "libft/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <fcntl.h>
#include <grp.h>
#include <time.h>
#include <pwd.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <uuid/uuid.h>
#include <dirent.h>
#include <unistd.h>


typedef struct options
{
        int l;
        int a;
        int r;
        int t;
        int kk;
        int n;
}             t_lists;

//void    test(int argc, char **argv, struct options *flags, char **file, char **direct);
void    flag_check(char **argv, struct options *flags, int k);
void    implement(char **argv, char **folder, char **list);
void    sorting(char **array, struct options *flags);
void    asci_value(char **arr);
void    reverse_arr(char **arr);
void    time_sorting(char **arr);
void    print_l(char **list, struct options *flags);
void    printing_ls(char **list);
void    block_size(char **list);
void    long_format(char **list);
void    user_id(struct stat sb);
void    group_id(struct stat sb);
void    file_size(struct stat sb);
void    ft_permissions(struct stat sb);
void    filetype(struct stat sb);
void    action_ls(char *dir, struct options *flags, char **list, char **folder);
void    argv_count(char **argv);
void    free_memory(char **lists);
void    runner(struct options *flags, char *dir);
//void    recurse(char *basePath, struct options *flags, int root);
void    recursion(struct options *flags, char *dir);
void    symbolic_link(struct stat sb);
int     error101(char *s1);

#endif
