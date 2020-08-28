#include "ft_ls.h"

void argv_count(char **argv)
{
    static int i;
    int i2;

    i2 = 1;
    if (argv != NULL)
    {
        while (argv[i2] && *argv[i2] != '\0')
        {
            if (argv[i2][0] != '-')
            {
                i++;
                i2++;
            }
        }
    }
    //return (i);
}