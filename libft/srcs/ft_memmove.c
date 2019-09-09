#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (src > dst)
		while (len--)
			((char *)dst)[i++] = *((char *)src++);
	else
		while (len--)
			*((char *)dst + len) = *((char *)src + len);
	return (dst);
}
