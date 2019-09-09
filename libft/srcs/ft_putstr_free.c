#include "libft.h"

void	ft_putstr_free(char const *s)
{
	write(1, s, ft_strlen(s));
	free((void *)s);
}
