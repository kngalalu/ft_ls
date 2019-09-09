#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	n;

	n = ft_strlen(little);
	while (*big && (len-- >= n))
		if (ft_strncmp(big++, little, n) == 0)
			return ((char *)big++ - 1);
	return (NULL);
}
