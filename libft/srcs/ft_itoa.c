#include "libft.h"

char	*ft_itoa(int n)
{
	char	*s;
	long	tmp;
	int		length;

	tmp = n;
	length = (n <= 0 ? 2 : 1);
	while (n && ++length)
		n /= 10;
	if (!(s = (char *)malloc(sizeof(char) * length)))
		return (NULL);
	s[--length] = '\0';
	if (tmp <= 0)
		s[0] = (tmp < 0 ? '-' : '0');
	while (tmp)
	{
		s[--length] = (tmp < 0 ? -tmp : tmp) % 10 + '0';
		tmp /= 10;
	}
	return (s);
}
