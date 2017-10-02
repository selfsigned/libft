#include "libft.h"

int	ft_atoi(const char *str)
{
    int		i;
    int 	r;
    char 	s;

    i = 0;
    r = 0;
    while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
	i++;
    if (str[i] == '+' || str[i] == '-')
    {
	s = str[i];
	i++;
    }
    while (ft_isdigit(str[i]))
    {
	r *= 10;
	r += str[i] - 48;
	i++;
    }
    if (s == '-')
	return (r * - 1);
    return (r);
}
