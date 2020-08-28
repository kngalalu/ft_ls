#include "ft_ls.h"

void  action_ls(char *dir, struct options *flags, char **list, char **folder)
{
        DIR           *dirp;
        struct dirent *entry;
        char temp[20000];
        int   k;
        int   m;

//        temp = (char*)malloc(sizeof());
        k = 0;
        m = 0;
        dirp = opendir(dir);
        if (dirp == NULL)
                exit(1);
        while ((entry = readdir(dirp)) != NULL)
        {
                if (entry->d_name[0] != '.' || flags->a == 1)
                {
//                        temp = (char*)malloc(sizeof(20000) + 1);
                        ft_strcpy(temp, dir);
                        ft_strcat(temp, "/");
                        ft_strcat(temp, entry->d_name);
//                        if ((entry->d_type) == DT_REG)
                        list[k++] = ft_strdup(temp);
                        if ((entry->d_type) == DT_DIR)
                                folder[m++] = ft_strdup(temp);

   //                     free(temp);
//                        k++;
//                        m++;
                }
//                k++;
//                m++;
//                free(temp);
        }
        list[k] = NULL;
        folder[m] = NULL;
        closedir(dirp);
}

// void  runner(struct options *flags, char *dir)
// {
//         char  *list[20000];
//         char  *folder[20000];




//         action_ls(dir, flags, list,folder); 
//         sorting(list, flags);
//         sorting(folder, flags);
//         print_l(list, flags);
// }