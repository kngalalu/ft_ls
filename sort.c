#include "ft_ls.h"

void  sorting(char **array, struct options *flags)
{
        asci_value(array);

/*        if (flags->n == 1)
        {
                printing_ls(array);
        }*/
        if (flags->t == 1)
        {
                time_sorting(array);
        }
        if (flags->r == 1)
        {
                reverse_arr(array);
        }
//        else
//                printing_ls(array);
}
