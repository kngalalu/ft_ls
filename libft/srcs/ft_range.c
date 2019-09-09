#include "libft.h"
#include <stdlib.h>  // Replace libft.h with stdlib.h for malloc

/*
** Create an array of integers from min to max (exclusive)
** - min: The starting value.
** - max: The ending value (exclusive).
** - Returns a pointer to the allocated array, or NULL if allocation fails.
*/
int *ft_range(int min, int max)
{
    int n;  // Number of elements in the range
    int *s; // Pointer to the allocated array

    // Calculate the number of elements
    n = (max >= min) ? (max - min) : (min - max);

    // Allocate memory for the array
    if (!(s = (int *)malloc(sizeof(int) * n)))  // Replace ft_intnew with malloc
        return NULL;  // Return NULL if allocation fails

    // Fill the array with values from min to max (exclusive)
    int *start = s;  // Save the starting address of the array
    while (max != min)
        *s++ = (max > min) ? min++ : min--;
    *s = min;  // Assign the last value

    return start;  // Return the starting address of the array
}