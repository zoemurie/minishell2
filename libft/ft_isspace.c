#include "libft.h"

int	ft_isspace(int c)
{
	c = (unsigned char)c;
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}
