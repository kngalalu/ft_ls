#include "libft.h"

char	*ft_strnjoinfree(const char *s1, const char *s2, size_t len, char c)
{
	char	*s;

	s = ft_strnjoin(s1, s2, len);
	if (c == 'L' || c == 'B')
		free((char *)s1);
	if (c == 'R' || c == 'B')
		free((char *)s2);
	return (s);
}
