#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*mem;

	if (!(mem = ft_memalloc((ft_strlen(s1) + ft_strlen(s2)))))
		return (NULL);
	mem = ft_strcpy(mem, (char *)s1);
	mem = ft_strcat(mem, (char *)s2);
	return (mem);
}
