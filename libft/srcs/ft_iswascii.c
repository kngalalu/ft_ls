#include "libft.h"

int		ft_iswascii(int wc)
{
	return (!(wc & ~0x7F));
}
