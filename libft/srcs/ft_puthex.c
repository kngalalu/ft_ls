#include "libft.h"

void	ft_puthex(int n)
{
	if (n >= 16)
		ft_puthex(n / 16);
	n = n % 16;
	n += n < 10 ? '0' : 'a' - 10;
	write(1, &n, 1);
}
