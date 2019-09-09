#include "libft.h"

long	ft_round(double n, int precision)
{
	long long	tmp;

	tmp = n * ft_pow(10, precision + 1);
	if (tmp % 10 >= 5)
		tmp = tmp / 10 + 1;
	else if (tmp % 10 <= -5)
		tmp = tmp / 10 - 1;
	else
		tmp /= 10;
	return (tmp);
}
