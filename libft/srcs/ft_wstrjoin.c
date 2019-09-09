#include "libft.h"

/*
** Concatenate two wide-character strings
** - s1: The first wide-character string.
** - s2: The second wide-character string.
** - Returns a new wide-character string containing s1 followed by s2, or NULL if allocation fails.
*/
wchar_t *ft_wstrjoin(wchar_t *s1, wchar_t *s2)
{
    wchar_t *s;  // Pointer to the concatenated string
    int i = 0;   // Index for iteration

    // Allocate memory for the new string
    if (!(s = (wchar_t *)malloc(sizeof(wchar_t) *
              (1 + ft_wstrlen((unsigned *)s1) + ft_wstrlen((unsigned *)s2)))))
        return NULL;  // Return NULL if allocation fails

    // Copy s1 into the new string
    while (*s1)
        s[i++] = *s1++;

    // Copy s2 into the new string
    while (*s2)
        s[i++] = *s2++;

    // Null-terminate the concatenated string
    s[i] = '\0';

    // Return the concatenated string
    return s;
}