#include "libft.h"

char	*ft_strnjoin(const char *s1, const char *s2, size_t len)
{
	char	*s;
	char	*ret;

	s = ft_strnew(ft_strlen(s1) + len + 1);
	ret = s;
	while (*s1)
		*s++ = *s1++;
	while (*s2 && len--)
		*s++ = *s2++;
	return (ret);
}
