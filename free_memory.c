#include "ft_ls.h"

void free_memory(char **lists)
{
        int i;

        i = 0;
        while(lists[i])
        {
                free(lists[i]);
                i++;
        }
}
