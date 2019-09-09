#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = n;
	while (n--)
		*dest++ = *src ? *src++ : '\0';
	return (dest - i);
}
