#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned	i;

	i = 0;
	while (*s)
		f(i++, s++);
}
