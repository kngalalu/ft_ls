#include "libft.h"

int		ft_isblank(char c)
{
	if (!c)
		return (0);
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\r' || c == '\v' || c == '\f')
		return (1);
	return (0);
}
