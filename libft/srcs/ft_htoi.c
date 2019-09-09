#include "libft.h"

// Convert a hexadecimal string to an integer
int ft_htoi(char *s)
{
    int n = 0;

    while (*s)
    {
        n *= 16;
        if (*s >= '0' && *s <= '9')
            n += *s - '0';
        else if (*s >= 'A' && *s <= 'F')
            n += *s - 'A' + 10;
        else if (*s >= 'a' && *s <= 'f')
            n += *s - 'a' + 10;
        else
            return -1;  // Error: non-hexadecimal character found
        s++;
    }
    return n;
}
