#include "libft.h"

char	*ft_lltoa_base(long long n)
{
	char				*s;
	unsigned long long	tmp;
	int					length;

	length = (n < 0) ? 2 : 1;
	tmp = (n < 0) ? -n : n;
	while (tmp /= 10)
		++length;
	if (!(s = (char*)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	s[length] = '\0';
	tmp = (n < 0) ? -n : n;
	while (length--)
	{
		s[length] = tmp % 10 + '0';
		tmp /= 10;
	}
	if (n < 0)
		s[0] = '-';
	return (s);
}
