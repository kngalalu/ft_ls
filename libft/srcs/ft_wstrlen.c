#include "ft_printf.h"

/*
** returns the len of a string containing widechars
*/

size_t		ft_wstrlen(unsigned *s)
{
	size_t	len;

	len = 0;
	while (*s != L'\0')
	{
		len += ft_wcharlen(*s);
		++s;
	}
	return (len);
}
