#include "libft.h"
#include <string.h>

/*
** Compare up to n characters of two strings
** - s1: First string to compare.
** - s2: Second string to compare.
** - n: Maximum number of characters to compare.
** - Returns:
**   - 0 if the strings are equal for the first n characters.
**   - A positive value if s1 is greater than s2.
**   - A negative value if s1 is less than s2.
*/
int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i = 0;  // Index for iteration

    if (!n)  // If n is 0, return 0 (no comparison needed)
        return 0;

    // Compare characters until a difference is found or n characters are compared
    while (s1[i] == s2[i] && s2[i] && i < n - 1)
        ++i;

    // Return the difference between the differing characters
    return (unsigned char)s1[i] - (unsigned char)s2[i];
}