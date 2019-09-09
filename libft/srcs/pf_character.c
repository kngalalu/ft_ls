#include "ft_printf.h"

/*
** Handle the %% format specifier (prints a single '%')
** - p: Pointer to the printf struct.
** - Returns the number of characters printed.
*/
int percent_char(t_printf *p)
{
    int pad;

    // Calculate the padding width (should not be negative)
    pad = (p->min_length > 1) ? (p->min_length - 1) : 0;
    
    // Add padding before the '%' if no left alignment flag is set
    if (!p->flags.min)
        ft_putnchar(pad, (p->flags.zero) ? '0' : ' ');

    // Print the '%' character
    ft_putwchar('%', 4);

    // Add padding after the '%' if left alignment is set
    if (p->flags.min)
        ft_putnchar(pad, ' ');

    // Return the total printed length (at least 1)
    return MAX(p->min_length, 1);
}

/*
** Handle the %c format specifier (prints a single character)
** - ap: Variable argument list.
** - p: Pointer to the printf struct.
*/
void pf_character(va_list ap, t_printf *p)
{
    unsigned c;  // Character to print
    int len;     // Printed length for the character

    // Retrieve the character from the argument list
    c = va_arg(ap, unsigned);

    // Decide if we are printing a wide character or a regular char.
    // Here, p->lm.llong acts as a flag for wide characters.
    len = (p->lm.llong) ? ft_wcharlen(c) : 1;

    // Calculate left padding, ensuring it is not negative.
    int pad = (p->min_length > len) ? (p->min_length - len) : 0;

    // Add padding before the character if left alignment is not set
    if (!p->flags.min)
        ft_putnchar(pad, (p->flags.zero) ? '0' : ' ');

    // Print the character: wide or regular.
    if (p->lm.llong)
        ft_putwchar(c, 4);
    else
        ft_putchar(c);

    // Add padding after the character if left alignment is set
    if (p->flags.min)
        ft_putnchar(pad, ' ');

    // Update the printed length with the maximum of min_length and len
    p->len += MAX(p->min_length, len);
}

/*
** Write a single regular character and update the printed length.
** - c: The character to print.
** - p: Pointer to the printf struct.
*/
void pf_putchar(char c, t_printf *p)
{
    write(1, &c, 1);
    ++p->len;
}

