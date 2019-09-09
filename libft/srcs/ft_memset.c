#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char *mem;

	mem = (char *)b;
	while (len)
		mem[--len] = c;
	return (b);
}
