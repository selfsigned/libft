#include "libft.h"

int	ft_isalnum(int chr)
{
    return (ft_isalpha(chr) || ft_isdigit(chr));
}
