#include "libft.h"

char	*ft_strcpy(char *dst, char *src)
{
	return (ft_memcpy(dst, src, ft_strlen(src) + 1));
}
