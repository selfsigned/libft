#include "libft.h"
#include <stdio.h>
#include <string.h>

int	main()
{
    char *hello = "hello world!\n";
	/* char src[10] = "hi"; */
	char dst[5];

    printf("%d\n", (ft_atoi(" \n 		-42")));
	char	*c1 = ft_memccpy(dst, hello, 'o', 5);
	char	*c2 = memccpy(dst, hello, 'o', 5);
	printf("ft_memccpy\nmine: %s original: %s\n", --c1, --c2);
	char	*m1 = ft_memmove(dst, hello, 2);
	char	*m2 = memmove(dst, hello, 2);
	printf("ft_memmove\nmine: %s original: %s\n", m1, m2);
	int		cmp1 = ft_memcmp("hello", "helln", 5);
	int		cmp2 = memcmp("hello", "helln", 5);
	printf("ft_memcmp\nmine: %d original: %d\n", cmp1, cmp2);
}
