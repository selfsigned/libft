#include "libft.h"

void	ft_putnbr(int n)
{
    if (n < 0)
    {
	ft_putchar('-');
	if (n == -2147483648)
	{
	    ft_putchar('2');
	    n = -147483648;
	}
	n *= -1;
    }
    if (n > 9)
    {
	ft_putnbr(n / 10);
	ft_putnbr(n % 10);
    }
    else
	ft_putchar(n + '0');
}
