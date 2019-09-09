#include "libft.h"

void ft_bubblesort_array(char **tab, size_t n)
{
    int sorted;  // Flag to check if the array is sorted
    size_t i;    // Loop index
    char *temp;  // Temporary variable for swapping

    sorted = 0;  // Initialize sorted flag to false
    while (!sorted)  // Repeat until the array is sorted
    {
        sorted = 1;  // Assume the array is sorted
        i = 0;
        while (i < n - 1)  // Iterate through the array
        {
            if (ft_strcmp(tab[i], tab[i + 1]) > 0)  // Compare adjacent strings
            {
                // Swap if they are in the wrong order
                temp = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = temp;
                sorted = 0;  // Set sorted flag to false
            }
            i++;
        }
    }
}