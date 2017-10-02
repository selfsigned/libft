#include "libft.h"

size_t	ft_strlen(const char *s)
{
    int i;
    
    i =  -1;
    while (s[++i] != '\0');
    return (i);
}
