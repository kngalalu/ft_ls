#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char *s;
	char *d;

	s = (char *)src;
	d = (char *)dest;
	while (n--)
		d[n] = s[n];
	return (dest);
}
