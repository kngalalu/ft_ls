#include "libft.h"

char	*ft_str2lower(char *s)
{
	unsigned i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
	}
	return (s);
}
