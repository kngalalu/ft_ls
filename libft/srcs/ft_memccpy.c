#include <string.h>

// Copy bytes from src to dest until character c is found or n bytes are copied
void *ft_memccpy(void *dest, const void *src, int c, size_t n)
{
    char *s = (char *)src;  // Cast src to char pointer
    char *d = (char *)dest; // Cast dest to char pointer
    unsigned int i = 0;     // Index for iteration

    while (n--)  // Iterate through n bytes
    {
        d[i] = s[i];  // Copy byte from src to dest
        if (s[i++] == (char)c)  // Check if current byte matches c
            return (char *)dest + i;  // Return pointer to the next byte in dest
    }
    return NULL;  // Return NULL if c is not found within n bytes
}