#include "libft.h"

/*
** Duplicate a wide-character string
** - s1: The wide-character string to duplicate.
** - Returns a pointer to the duplicated string, or NULL if allocation fails.
*/
wchar_t *ft_wstrdup(wchar_t const *s1)
{
    wchar_t *s2;  // Pointer to the duplicated string
    size_t len;   // Length of the input string in bytes

    // Calculate the length of the input string in bytes
    len = ft_wstrlen((unsigned *)s1) * sizeof(wchar_t);

    // Check if the input string is NULL or if memory allocation fails
    if (!s1 || !(s2 = (wchar_t *)ft_memalloc(sizeof(wchar_t) + len)))
        return NULL;  // Return NULL if allocation fails

    // Copy the input string to the new memory location
    ft_memcpy(s2, s1, len);

    // Return the duplicated string
    return s2;
}