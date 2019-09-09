#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	if (!big[0] && !little[0])
		return ((char *)big);
	return (ft_strnstr(big, little, ft_strlen(big)));
}
