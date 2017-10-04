#include "libft.h"
#include <stdio.h>

int	main()
{
    char *hello = "hello";

    printf("length of \"%s\": %zu\n", hello, ft_strlen(hello));
    printf("%d\n", (ft_atoi(" \n 		-42")));
	ft_putnbr(-42);
}
