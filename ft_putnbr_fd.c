#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
    if (n < 0)
    {
	ft_putchar_fd('-',  fd);
	if (n == -2147483648)
	{
	    ft_putchar_fd('2', fd);
	    n = -147483648;
	}
	n *= -1;
    }
    if (n > 9)
    {
	ft_putnbr_fd(n / 10, fd);
	ft_putnbr_fd(n % 10, fd);
    }
    else
	ft_putchar_fd(n + '0', fd);
}
