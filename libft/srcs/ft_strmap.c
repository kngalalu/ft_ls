#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*mem;
	int		i;

	if (!(mem = ft_strnew(ft_strlen(s))))
		return (NULL);
	i = -1;
	while (s[++i])
		mem[i] = f(s[i]);
	mem[i] = '\0';
	return (mem);
}
