#include "libft.h"

/*
** Extract a substring from a wide-character string
** - s: The source wide-character string.
** - start: The starting index of the substring.
** - len: The maximum length of the substring in bytes.
** - Returns a new wide-character string containing the substring, or NULL if allocation fails.
*/
wchar_t *ft_wstrsub(wchar_t *s, unsigned start, unsigned len)
{
    wchar_t *str;  // Pointer to the substring
    unsigned i = 0;  // Index for iteration

    // Allocate memory for the substring, including space for the null terminator
    if (!(str = (wchar_t *)ft_memalloc(sizeof(wchar_t) * (len + 1))))
        return NULL;  // Return NULL if allocation fails

    // Copy characters from the source string to the substring
    while (ft_wcharlen(s[i + start]) <= len)  // Ensure the character fits within the remaining length
    {
        str[i] = s[i + start];  // Copy the character
        i += ft_wcharlen(str[i]);  // Move the index by the character's byte length
    }

    // Null-terminate the substring
    str[i] = '\0';

    // Return the substring
    return str;
}