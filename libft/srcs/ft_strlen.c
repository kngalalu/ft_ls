#include "libft.h"

size_t	ft_strlen(char const *str)
{
	char	*s;

	s = (char *)str;
	while (*s)
		++s;
	return (s - str);
}
