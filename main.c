#include "ft_ls.h"

//void recurse(char *basePath);

int   main(int argc, char **argv)
{
        int i;
        int len;
       // int current;
        char *list[20000];
        char *folder[20000];
        struct options *dang;
        int x;
        //int arv;

        dang = (struct options *)malloc(sizeof(struct options));
        dang->r = 0;
        dang->l = 0;
        dang->t = 0;
        dang->a = 0;
        dang->kk = 0;
        dang->n = 0;


        x = 0;
        i = 1;
       // len = argv_count(argv);
        len = 1;

        while (argv[i] && argv[i][0] == '-')
        {
                i++;
                len++;
        }

        flag_check(argv, dang, len);
        implement(argv, folder, list);
        if (argv[1] == NULL || argv[i] == NULL)
        {
                folder[0] = ".";
                folder[1] = '\0';
        }
        sorting(list, dang);
        if (*list != NULL)
                print_l(list, dang);
        
        // while (folder[x])
        // {
        //         runner(dang, folder[x]);
        //         x++;
        // }

        int z = 0;
        
        // {
        //         while (folder[z])
        //         {
        //                 recursion(dang, folder[z]);
        //                 z++;
        //         }

        // }
        while (folder[z])
        {
                recursion(dang, folder[z]);
                z++;
        }


        free(dang);
        return (0);
}