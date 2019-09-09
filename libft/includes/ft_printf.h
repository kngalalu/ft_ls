#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// Include necessary headers
# include <stdint.h>  // Fixed-width integers
# include <stdarg.h>  // Variable arguments
# include "libft.h"   // Custom utility library
# include <errno.h>   // Error handling

// Utility macros
# define MAX(a, b)    ((a) > (b) ? (a) : (b))  // Maximum of two values
# define MIN(a, b)    ((a) < (b) ? (a) : (b))  // Minimum of two values
# define ABS(a)       ((a) < 0 ? -(a) : (a))   // Absolute value
# define COLOR(s, n)  ft_putstr(s), (format += (n))  // Print color and advance format

// ANSI color codes
# define PF_RED       "\033[31m"              // Red text
# define PF_GREEN     "\033[32m\033[1m"      // Bold green text
# define PF_YELLOW    "\033[33m\033[1m"      // Bold yellow text
# define PF_BLUE      "\033[34m\033[1m"      // Bold blue text
# define PF_PURPLE    "\033[35m\033[1m"      // Bold purple text
# define PF_CYAN      "\033[36m\033[1m"      // Bold cyan text
# define PF_EOC       "\033[37m\033[0m"      // Reset to default color

// Struct for formatting flags
typedef struct s_flags {
    int sharp;  // # flag (alternate form)
    int zero;   // 0 flag (zero-padding)
    int min;    // - flag (left-justify)
    int plus;   // + flag (show sign)
    int sp;     // Space flag (prefix with space)
} t_flags;

// Struct for length modifiers
typedef struct s_length_modifier {
    int sshort;  // h (short)
    int llong;   // l (long)
    int intmax;  // j (intmax_t)
    int sizet;   // z (size_t)
} t_length_modifier;

// Struct for conversion specifiers
typedef struct s_conversion_specifier {
    int upcase;  // Uppercase flag for hex
} t_conversion_specifier;

// Main printf struct
typedef struct s_printf {
    int len;                  // Total output length
    t_flags flags;            // Formatting flags
    int min_length;           // Minimum field width
    int precision;            // Precision for numbers/strings
    int apply_precision;      // Whether precision is applied
    t_length_modifier lm;     // Length modifiers
    t_conversion_specifier cs; // Conversion specifiers
    int printed;              // Number of characters printed
} t_printf;

// Main printf function
int ft_printf(char *format, ...);

// Character and string output
int ft_printf_putchar(char c);
int ft_printf_putstr(char *s, t_printf *p);
int ft_printf_putwstr(wchar_t *s);

// Parsing functions
char *parse_optionals(char *format, va_list ap, t_printf *p);
char *parse_flags(char *format, t_flags *flags);
char *field_width(char *format, t_printf *p);
char *precision(char *format, t_printf *p);
char *length_modifier(char *format, t_length_modifier *lm);

// Conversion specifiers
int percent_char(t_printf *p);
char *conversion_specifier(char *format, va_list ap, t_printf *p);
void cs_not_found(char *format, t_printf *p);

// Number-related functions
void pf_putnb(va_list ap, t_printf *p);
void pf_putnb_base(int base, va_list ap, t_printf *p);
char *itoa_printf(intmax_t d, t_printf *p);
char *itoa_base_printf(uintmax_t d, int b, t_printf *p);
void itoa_base_fill(uintmax_t tmp, int base, char *str, t_printf *p);

// String and character functions
int pf_string(va_list ap, t_printf *p);
int pf_wide_string(va_list ap, t_printf *p);
void pf_character(va_list ap, t_printf *p);
void pf_putchar(char c, t_printf *p);

// Bonus functions
int print_pointer_address(va_list ap, t_printf *p);
void wildcard_length_modifier(va_list ap, t_printf *p);
char *color(char *format, t_printf *p);
void pf_putdouble(va_list ap, t_printf *p);
char *pf_ldtoa(double n, t_printf *p);
void ldtoa_fill(double n, char *s, t_printf *p);

void ft_putnchar(int n, char c);

#endif