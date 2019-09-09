#include "libft.h"

// Check if a character is alphanumeric (a letter or a digit)
int ft_isalnum(int c)
{
    // Return 1 if the character is a letter (A-Z, a-z) or a digit (0-9), else 0
    if ((c >= '0' && c <= '9') ||
        (c >= 'A' && c <= 'Z') ||
        (c >= 'a' && c <= 'z'))
        return (1);
    return (0);
}