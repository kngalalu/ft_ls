#include "libft.h"

void ft_bzero(void *s, size_t n)
{
    // Set 'n' bytes of memory starting at 's' to zero
    if (n)  // Check if 'n' is not zero
        ft_memset(s, 0, n);  // Use ft_memset to fill memory with zeros
}