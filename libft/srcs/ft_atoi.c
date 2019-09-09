#include "libft.h"

int ft_atoi(char *s)
{
    int sign;  // Stores the sign of the number (+1 or -1)
    long result;  // Stores the intermediate result

    result = 0;  // Initialize result to 0

    // Skip leading whitespace characters
    while (*s == 32 || (*s >= 9 && *s <= 13))
        s++;
    // Determine the sign of the number
    sign = (*s == '-') ? -1 : 1;

    // Skip the sign character if present
    if (*s == '-' || *s == '+')
        s++;

    // Convert the string of digits to an integer
    while (*s >= '0' && *s <= '9')
        result = result * 10 + (*s++ - '0');

    // Return the final result with the correct sign
    return (sign * (int)result);
}
