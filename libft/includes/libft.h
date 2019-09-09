#ifndef LIBFT_H
# define LIBFT_H

// Standard libraries
# include <unistd.h>  // POSIX functions (e.g., write)
# include <string.h>  // String manipulation functions
# include <stdlib.h>  // Memory allocation and utilities
# include "ft_printf.h"  // Custom printf implementation

// Boolean type definition
typedef int t_bool;

// Linked list structure
typedef struct s_list {
    void *content;           // Pointer to data
    size_t content_size;     // Size of the data
    struct s_list *next;     // Pointer to the next node
} t_list;

// RGB color structure
typedef struct s_rgb {
    float r;  // Red component
    float g;  // Green component
    float b;  // Blue component
} t_rgb;

// HSB color structure
typedef struct s_hsb {
    float h;  // Hue
    float s;  // Saturation
    float b;  // Brightness
} t_hsb;

// 3D vector structure
typedef struct s_vector {
    float x;  // X coordinate
    float y;  // Y coordinate
    float z;  // Z coordinate
    float w;  // W coordinate (optional)
} t_vector;

// String functions
size_t ft_strlen(const char *str);  // Get string length
int ft_strlencmp(const char *s1, const char *s2);  // Compare string lengths
void ft_putchar(char c);  // Print a character
void ft_putstr(const char *str);  // Print a string
void ft_putstr_free(const char *str);  // Print and free a string
int ft_strcmp(const char *s1, const char *s2);  // Compare two strings
int ft_strncmp(const char *s1, const char *s2, size_t n);  // Compare first n characters
void ft_swap(int *a, int *b);  // Swap two integers
void ft_putnbr(int nb);  // Print an integer
int ft_atoi(char *str);  // Convert string to integer
char *ft_strcat(char *dest, char *src);  // Concatenate strings
char *ft_strncat(char *dst, const char *src, size_t n);  // Concatenate n characters
unsigned int ft_strlcat(char *dest, char *src, unsigned int size);  // Safe string concatenation
char *ft_strcpy(char *dest, char *src);  // Copy string
char *ft_strncpy(char *dest, const char *src, size_t n);  // Copy n characters
char *ft_strdup(const char *s1);  // Duplicate string

// Memory functions
void *ft_memset(void *s, int c, size_t n);  // Fill memory with a byte
void ft_bzero(void *s, size_t n);  // Zero out memory
void *ft_memalloc(size_t size);  // Allocate memory
void ft_memdel(void **ap);  // Free memory
void *ft_memcpy(void *dest, const void *src, size_t n);  // Copy memory
void *ft_memccpy(void *dest, const void *src, int c, size_t n);  // Copy until a byte is found
void *ft_memmove(void *dest, const void *src, size_t n);  // Move memory
void *ft_memchr(const void *s, int c, size_t n);  // Find byte in memory
int ft_memcmp(const void *s1, const void *s2, size_t n);  // Compare memory

// String manipulation
char *ft_strnew(size_t size);  // Create a new string
int *ft_intnew(size_t size);  // Create a new integer array
void ft_strdel(char **as);  // Delete a string
void ft_strclr(char *s);  // Clear a string
char *ft_strnstr(const char *big, const char *little, size_t len);  // Find substring
char *ft_strstr(const char *big, const char *little);  // Find substring
char *ft_strchr(const char *s, int c);  // Find character in string
char *ft_strrchr(const char *s, int c);  // Find last occurrence of character
void ft_striter(char *s, void (*f)(char *));  // Apply function to each character
void ft_striteri(char *s, void (*f)(unsigned int, char *));  // Apply function with index
char *ft_strmap(const char *s, char (*f)(char));  // Map function to string
char *ft_strmapi(const char *s, char (*f)(unsigned int, char));  // Map function with index
int ft_strequ(const char *s1, const char *s2);  // Check string equality
int ft_strnequ(const char *s1, const char *s2, size_t n);  // Check equality of first n characters
char *ft_strsub(const char *s, unsigned int start, size_t len);  // Extract substring
char *ft_strjoin(const char *s1, const char *s2);  // Join two strings
char *ft_strjoinfree(char *s1, char *s2, char control);  // Join and free strings
char *ft_strtrim(const char *s);  // Trim whitespace
char **ft_strsplit(const char *s, char c);  // Split string by delimiter
char *ft_itoa(int n);  // Convert integer to string

// Output functions
void ft_putendl(const char *s);  // Print string with newline
void ft_putchar_fd(char c, int fd);  // Print character to file descriptor
void ft_putstr_fd(const char *s, int fd);  // Print string to file descriptor
void ft_putendl_fd(const char *s, int fd);  // Print string with newline to file descriptor
void ft_putnbr_fd(int n, int fd);  // Print integer to file descriptor

// Linked list functions
t_list *ft_lstnew(void const *content, size_t content_size);  // Create new list node
void ft_lstdelone(t_list **alst, void (*del)(void *, size_t));  // Delete a list node
void ft_lstdel(t_list **alst, void (*del)(void *, size_t));  // Delete entire list
void ft_lstadd(t_list **alst, t_list *new);  // Add node to list
void ft_lstiter(t_list *lst, void (*f)(t_list *elem));  // Apply function to each node
t_list *ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));  // Map function to list

// Utility functions
int ft_isspace(char c);  // Check if character is whitespace
char *ft_strctrim(char const *s, char c);  // Trim specific character
char *ft_strrev(char *s);  // Reverse string
void ft_bubblesort_array(char **tab, size_t n);  // Bubble sort for string array
int ft_clamp(int n, int min, int max);  // Clamp value between min and max
void ft_memswap(void *a, void *b);  // Swap memory
char *ft_strndup(const char *s, size_t n);  // Duplicate first n characters
char *ft_strdupfree(const char *s1);  // Duplicate and free original string
char *ft_strnjoinfree(const char *s1, const char *s2, size_t len, char c);  // Join and free strings
char *ft_strnjoin(const char *s1, const char *s2, size_t len);  // Join first n characters
void ft_putnbr_base(int n, int b);  // Print integer in specified base
int ft_error(char *s);  // Print error message
int ft_is_power_of_x(unsigned n, unsigned x);  // Check if number is a power of x
int ft_htoi(char *s);  // Convert hexadecimal string to integer
int ft_rand(int min, int max);  // Generate random number
t_rgb ft_hex2rgb(int hex);  // Convert hex color to RGB
int ft_rgb2hex(t_rgb rgb);  // Convert RGB to hex color
t_rgb ft_hsb2rgb(t_hsb hsb);  // Convert HSB to RGB
int ft_hsb2hex(t_hsb hsb);  // Convert HSB to hex color
int ft_shade_color(int c, double n);  // Shade color by factor
int ft_abs(int n);  // Absolute value
float ft_fclamp(float n, float min, float max);  // Clamp float value
char *ft_str2lower(char *s);  // Convert string to lowercase
char *ft_itoa_base(int n, int b);  // Convert integer to string in specified base
double ft_pow(double n, int pow);  // Power function
t_list *ft_lstswap(t_list *lst1, t_list *lst2);  // Swap two list nodes

// Wide character functions (for printf)
int ft_putwchar(unsigned wchar, int wstrlen);  // Print wide character
size_t ft_wstrlen(unsigned *s);  // Get wide string length
size_t ft_wcharlen(unsigned c);  // Get wide character length
int ft_putwstr(wchar_t *s);  // Print wide string
wchar_t *ft_wstrjoin(wchar_t *s1, wchar_t *s2);  // Join wide strings
wchar_t *ft_wstrdup(wchar_t const *s1);  // Duplicate wide string
wchar_t *ft_wstrsub(wchar_t *s, unsigned start, unsigned len);  // Extract wide substring
char *ft_lltoa_base(long long n);  // Convert long long to string in base
char *ft_ulltoa_base(unsigned long long n, int b, int lowup);  // Convert unsigned long long to string in base
long ft_round(double n, int precision);  // Round double to specified precision
char *ft_ldtoa(double n, int precision);  // Convert double to string with precision


typedef struct s_file t_file;
// size_t lst_maxlen(t_file *lst);
size_t lst_maxlen(t_file *lst);

#endif