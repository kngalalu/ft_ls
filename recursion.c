#include "ft_ls.h"

///recusion part of the code, and with assistance from nmaila///
void  recursion(struct options *flags, char *dir)
{
        char  *list[20000];
        char  *folder[20000];
        char *str1;
        int   i;

 //      list = (char**)malloc(sizeof(char *(12024)));
//        folder = (char**)malloc(sizeof(1024 * 1024));

        action_ls(dir, flags, list,folder); 
        sorting(list, flags);
        sorting(folder, flags);
        print_l(list, flags);
      // runner(flags, folder[i]);
        if (flags->kk == 1)
        {
                while (folder[i])
                {
                        str1 = ft_strrchr(folder[i], '/');
                        if ((ft_strcmp(str1, "/.") != 0) &&  (ft_strcmp(str1, "/..") != 0))
                        {
                                ft_putstr("");
                                ft_putchar('\n');
                                ft_putstr(folder[i]);
                                ft_putstr(":");
                                ft_putchar('\n');
                                recursion(flags, folder[i]);
                                //runner(flags, folder[i]);
                        }
                        i++;
                        //free(str1);
                }
                //free(str1);
        }
       // free(str1);
        free_memory(list);
        free_memory(folder);
}


// void recurse(char *basePath, struct options *flags, int root)
// {
//         int i;
//     char path[20000];
//     struct dirent *dp;
//     DIR *dir = opendir(basePath);
//    if (flags->kk == 1)
//    {
//            //DIR *dir = opendir(basePath);
           
//            if (!dir)
//                 return;

//         while ((dp = readdir(dir)) != NULL)
//         {
//                 if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
//                 {
//                         printf("%c%c%s\n", 195, 196, dp->d_name);
                        
//                         strcpy(path, basePath);
//                         strcat(path, "/");
//                         strcat(path, dp->d_name);
//                         recurse(path, flags, root + 2);
//                 }
//         }
//  //       list[k] = NULL;
//        // basePath = '\0';
//         //free(path);
//         // closedir(dir);
//    }
//    closedir(dir);
//    return ;
    
// }