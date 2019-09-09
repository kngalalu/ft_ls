#include "libft.h"

int ft_abs(int n)
{
    // Calculate the absolute value of an integer using bitwise operations
    int mask = n >> 31; // mask is -1 if n is negative, 0 otherwise
    return (n ^ mask) - mask; // Toggle bits and subtract mask to get absolute value
}
