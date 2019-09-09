#include "ft_printf.h"

/*
** Handle the * wildcard for length or precision
** - ap: Variable argument list.
** - p: Pointer to the printf struct.
*/
void wildcard_length_modifier(va_list ap, t_printf *p)
{
    int tmp;

    tmp = (int)va_arg(ap, int);  // Get the value from va_list
    p->flags.min = (tmp < 0) ? 1 : 0;  // Set the minus flag if tmp is negative
    tmp = ABS(tmp);  // Use absolute value of tmp

    // Apply tmp to min_length or precision based on context
    if (!p->apply_precision)
        p->min_length = tmp;  // Set min_length if precision is not applied
    else
    {
        p->precision = (!p->flags.min) ? tmp : 0;  // Set precision if no minus flag
        p->apply_precision = (!tmp) ? 1 : 0;  // Disable precision if tmp is 0
    }
}

/*
** Handle color codes in the format string
** - format: Pointer to the format string.
** - p: Pointer to the printf struct.
** - Returns the updated format pointer.
*/
char *color(char *format, t_printf *p)
{
    p->printed = 5;  // Default printed length for color codes

    // Check for color codes and apply the corresponding ANSI color
    if (!ft_strncmp(format, "{red}", ft_strlen("{red}")))
        COLOR(PF_RED, 5);
    else if (!ft_strncmp(format, "{green}", ft_strlen("{green}")))
        COLOR(PF_GREEN, 7);
    else if (!ft_strncmp(format, "{yellow}", ft_strlen("{yellow}")))
        COLOR(PF_YELLOW, 8);
    else if (!ft_strncmp(format, "{blue}", ft_strlen("{blue}")))
        COLOR(PF_BLUE, 6);
    else if (!ft_strncmp(format, "{purple}", ft_strlen("{purple}")))
        COLOR(PF_PURPLE, 8);
    else if (!ft_strncmp(format, "{cyan}", ft_strlen("{cyan}")))
        COLOR(PF_CYAN, 6);
    else if (!ft_strncmp(format, "{eoc}", ft_strlen("{eoc}")))
        COLOR(PF_EOC, 5);
    else
        p->printed = 0;  // No color code matched

    p->len += p->printed;  // Update the total printed length
    return format - 1;  // Return the updated format pointer
}

/*
** Handle floating-point numbers (double)
** - ap: Variable argument list.
** - p: Pointer to the printf struct.
*/
void pf_putdouble(va_list ap, t_printf *p)
{
    char *s;
    double n;

    n = (double)va_arg(ap, double);  // Get the double value from va_list
    if (p->flags.zero)  // If zero flag is set, use min_length as precision
        p->precision = p->min_length;

    s = pf_ldtoa(n, p);  // Convert double to string
    ft_putstr_free(s);  // Print the string and free memory
    p->len += MAX(p->printed, p->min_length);  // Update the total printed length
}

/*
** Convert a double to a string with specified precision
** - n: The double value to convert.
** - p: Pointer to the printf struct.
** - Returns the converted string.
*/
char *pf_ldtoa(double n, t_printf *p)
{
    long tmp;
    char *s;
    int len;

    // Handle zero precision
    if (p->apply_precision && !p->precision)
        return itoa_printf((intmax_t)n, p);  // Return integer part if precision is 0
    else if (!p->apply_precision)
        p->precision = 6;  // Default precision is 6

    // Calculate the length of the integer part
    len = (p->precision > 0) ? 1 : 0;  // Account for the decimal point
    tmp = (long)(ABS(n));
    while (tmp)
    {
        tmp /= 10;
        ++len;
    }

    // Adjust precision if zero flag is set
    if (p->flags.zero)
        p->precision = p->min_length;

    // Calculate the total printed length
    p->printed = p->precision + len + ((n < 0) ? 1 : 0);  // Include space for sign

    // Allocate memory for the string
    if (!(s = (char *)malloc(sizeof(char) * (p->printed + 1))))
        return NULL;

    // Fill the string with the double value
    ldtoa_fill(n, s, p);

    // Handle flags (space, minus, plus)
    if (p->flags.sp)
        s[0] = ' ';  // Add space for space flag
    if (n < 0)
        s[0] = '-';  // Add minus sign for negative numbers
    if (p->flags.plus && n >= 0)
        s[0] = '+';  // Add plus sign for positive numbers

    return s;
}

/*
** Fill the string with the double value
** - n: The double value.
** - s: The string to fill.
** - p: Pointer to the printf struct.
*/
void ldtoa_fill(double n, char *s, t_printf *p)
{
    int len;
    int accuracy;
    double decimal;
    long value;

    // Calculate the decimal part with rounding
    decimal = ABS(n);
    decimal = (decimal - (long)(ABS(n))) * ft_pow(10, p->precision + 1);
    decimal = ((long)decimal % 10 > 4) ? (decimal) / 10 + 1 : decimal / 10;

    // Determine the lengths for integer and decimal parts
    len = p->printed - 1 - p->precision;
    accuracy = p->printed - 1 - len;

    // Null-terminate the string
    s[p->printed] = '\0';

    // Fill the decimal part
    value = (int)decimal;
    while (accuracy--)
    {
        s[len + accuracy + 1] = value % 10 + '0';
        value /= 10;
    }

    // Add the decimal point
    if (p->precision > 0)
        s[len] = '.';

    // Fill the integer part
    value = (long)(ABS(n));
    while (len--)
    {
        s[len] = value % 10 + '0';
        value /= 10;
    }

    // Handle zero flag with precision
    if (p->apply_precision && p->flags.zero)
        s[0] = ' ';
}