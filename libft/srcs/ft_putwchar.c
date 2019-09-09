#include "libft.h"

/*
** Print a wide character (UTF-8 encoding)
** - wc: The wide character to print.
** - wlen: The maximum number of bytes allowed for the output.
** - Returns the number of bytes printed, or 0 if the character cannot fit in wlen.
*/
int ft_putwchar(unsigned wc, int wlen)
{
    int nb_bytes;

    // Determine the number of bytes required for the wide character
    nb_bytes = ft_wcharlen(wc);

    // Check if the character can fit within the allowed byte length
    if (nb_bytes <= wlen)
    {
        if (nb_bytes == 1)  // 1-byte character (ASCII)
            ft_putchar(wc);
        else
        {
            // Multi-byte character (UTF-8)
            if (nb_bytes == 2)  // 2-byte character
                ft_putchar(((wc & (0x1f << 6)) >> 6) + 0xC0);
            else if (nb_bytes == 3)  // 3-byte character
            {
                ft_putchar(((wc & (0xf << 12)) >> 12) + 0xE0);
                ft_putchar(((wc & (0x3f << 6)) >> 6) + 0x80);
            }
            else  // 4-byte character
            {
                ft_putchar(((wc & (0x7 << 18)) >> 18) + 0xF0);
                ft_putchar(((wc & (0x3f << 12)) >> 12) + 0x80);
                ft_putchar(((wc & (0x3f << 6)) >> 6) + 0x80);
            }
            // Print the last byte of the multi-byte character
            ft_putchar((wc & 0x3f) + 0x80);
        }
    }

    // Return the number of bytes printed, or 0 if the character doesn't fit
    return (nb_bytes <= wlen) ? nb_bytes : 0;
}