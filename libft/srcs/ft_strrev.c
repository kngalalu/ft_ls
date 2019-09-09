#include "libft.h"

char	*ft_strrev(char *s)
{
	int		i;
	int		j;
	char	t;

	i = -1;
	j = ft_strlen(s);
	while (++i < --j)
	{
		t = s[i];
		s[i] = s[j];
		s[j] = t;
	}
	return (s);
}
