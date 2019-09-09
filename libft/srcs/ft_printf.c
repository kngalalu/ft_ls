#include "ft_printf.h"

/*
** Main printf function
** - Iterates through the format string.
** - Handles regular characters and format specifiers (starting with %).
** - Returns the total number of characters printed.
*/
int ft_printf(char *format, ...)
{
    va_list ap;      // Variable argument list
    t_printf p;      // Struct to store printf state (e.g., length, flags)

    va_start(ap, format);  // Initialize va_list
    p.len = 0;             // Initialize printed length to 0

    while (*format)  // Iterate through the format string
    {
        if (*format == '%')  // Handle format specifier
        {
            if (!format[1] || (format[1] == ' ' && (!format[2] || (!format[3] && format[2] == 'h'))))
                break;  // Break if invalid format specifier
            p.printed = 0;  // Reset printed length for this specifier
            format = parse_optionals(++format, ap, &p);  // Parse optional flags
            if (*format == '%')  // Handle %% (escape %)
                p.len += percent_char(&p);
            format = conversion_specifier(format, ap, &p);  // Handle conversion specifier
        }
        else  // Handle regular characters
            pf_putchar(*format, &p);  // Print the character
        ++format;  // Move to the next character
    }

    va_end(ap);  // Clean up va_list
    return p.len;  // Return total printed length
}

/*
** Handle conversion specifiers
** - Determines the type of conversion (e.g., d, s, x) and processes accordingly.
** - Updates the printed length in the printf struct.
*/
char *conversion_specifier(char *format, va_list ap, t_printf *p)
{
    // Set uppercase flag for hex conversions
    p->cs.upcase = (*format == 'X') ? 1 : 0;

    // Handle numeric conversions
    if (*format == 'x' || *format == 'X')
        pf_putnb_base(16, ap, p);  // Hexadecimal
    else if (*format == 'u' || *format == 'U')
        pf_putnb_base(10, ap, p);  // Unsigned decimal
    else if (*format == 'o' || *format == 'O')
        pf_putnb_base(8, ap, p);   // Octal
    else if (*format == 'b' || *format == 'B')
        pf_putnb_base(2, ap, p);   // Binary
    else if (ft_strchr("dDi", *format))
        pf_putnb(ap, p);           // Signed decimal
    else if (*format == 'c' || *format == 'C')
        pf_character(ap, p);       // Character
    else if (*format == 's' && !p->lm.llong)
        p->len += pf_string(ap, p);  // String
    else if (*format == 'S' || (*format == 's' && p->lm.llong))
        p->len += pf_wide_string(ap, p);  // Wide string
    else if (*format == 'p')
        p->len += print_pointer_address(ap, p);  // Pointer address
    else if (*format == 'n')
        *va_arg(ap, int *) = p->len;  // Store printed length
    else if (*format == 'm')
        p->len += ft_printf_putstr(strerror(errno), p);  // Print error message
    else if (*format == 'f' || *format == 'F')
        pf_putdouble(ap, p);  // Floating point
    else if (*format == '{')
        return color(format, p);  // Handle color
    else if (!ft_strchr("sSpdDibBoOuUxXcC%nmfF", *format))
        cs_not_found(format, p);  // Handle invalid specifier

    return format;  // Return updated format pointer
}

/*
** Print padding characters (e.g., spaces or zeros)
** - Used for alignment and formatting.
*/
void ft_putnchar(int len, char c)
{
    char *s;

    /* Allocate len + 1 characters (including the null terminator) */
    s = (char *)malloc(sizeof(char) * (len + 1));
    if (!s)
        return;  // Allocation failed, so exit early

    s[len] = '\0';  // Null-terminate the string

    /* Fill the string with the padding character */
    while (len--)
        s[len] = c;

    /* Print the string and free the allocated memory */
    ft_putstr_free(s);
}


/*
** Print a pointer address
** - Handles formatting (e.g., padding, 0x prefix).
*/
int print_pointer_address(va_list ap, t_printf *p)
{
    int sp_padding;
    char *s;
    void *pointer;

    pointer = va_arg(ap, void *);  // Get the pointer argument
    p->flags.sharp = 0;  // Disable sharp flag
    p->min_length -= (p->flags.zero ? 2 : 0);  // Adjust min length for 0x prefix
    s = itoa_base_printf((uintmax_t)pointer, 16, p);  // Convert pointer to hex string
    sp_padding = (p->printed > p->min_length - 2) ? 0 : p->min_length - 2 - p->printed;

    if (!p->flags.min)  // Add padding before 0x prefix
        ft_putnchar(sp_padding, (p->flags.zero ? '0' : ' '));
    ft_putstr("0x");  // Print 0x prefix
    ft_putstr_free(s);  // Print the hex value
    if (p->flags.min)  // Add padding after 0x prefix
        ft_putnchar(sp_padding, (p->flags.zero ? '0' : ' '));

    return MAX(p->printed + 2, p->min_length);  // Return total printed length
}

/*
** Handle invalid conversion specifiers
** - Prints the invalid specifier and adjusts padding.
*/
void cs_not_found(char *format, t_printf *p)
{
    if (!p->flags.min && p->min_length > 1)  // Add padding before invalid specifier
        ft_putnchar(p->min_length - 1, p->flags.zero ? '0' : ' ');
    p->min_length > 1 ? p->len += p->min_length - 1 : 0;  // Update printed length
    pf_putchar(*format, p);  // Print the invalid specifier
    if (p->flags.min && p->min_length > 1)  // Add padding after invalid specifier
        ft_putnchar(p->min_length - 1, p->flags.zero ? '0' : ' ');
}