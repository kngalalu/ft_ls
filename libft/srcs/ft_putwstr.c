#include "libft.h"

int		ft_putwstr(wchar_t *s)
{
	int		len;

	len = ft_wstrlen((unsigned *)s);
	(!len) ? write(1, "(null)", 6) : write(1, s, len);
	return ((!len) ? 6 : len);
}
