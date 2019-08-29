#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <inttypes.h>
#include "printf.h"
#include "libft.h"

// Choose your type here
# define INT

#ifdef STRING
# define PRINTF_ARG_TYPE char *a, char *b
# define PRINTF_ARG input_fmt, av[2]
#endif

# ifdef LONG
# define PRINTF_ARG_TYPE char *a, ulong b
# define PRINTF_ARG input_fmt, strtoul(av[2], NULL, 10)
# endif

# ifdef INT
# define PRINTF_ARG_TYPE char *a, int long b
# define PRINTF_ARG input_fmt, atoll(av[2])
#endif

#ifdef UNICODE
# include <wchar.h>
# include <locale.h>

# define PRINTF_ARG_TYPE char *a, wchar_t *b
# define PRINTF_ARG input_fmt, L"🤔 Thinking Face 🅱️ B Button (Blood Type) 👍 Thumbs Up 🔥 Fire 🤣 Rolling On The Floor Laughing 🏁 Flags 🙄 Face With Rolling Eyes 👑 Crown 🤤 Drooling Face ♀️ Female Sign 🤷‍♂️ Man Shrugging 🤷‍♀️ Woman Shrugging 🤭 Face With Hand Over Mouth 🤦‍♀️ Woman"
#endif

void	bench_printf(
		int (*print_func)(const char *restrict, ...),
		char *name,
		PRINTF_ARG_TYPE) {
	clock_t start, end;

	start = clock();
	print_func(a, b);
	end = clock();

	printf ("%s - Processor time: %.10f\n",
			name,
			(double)(end - start) / (double)CLOCKS_PER_SEC);
}

int main(int ac, char **av) {
	if (ac != 3)
		return 1;

	char input_fmt[128];
	size_t input_len = strlen(av[1]);

	if (input_len >= 128 - 2)
		return 1;

	strncpy(input_fmt, av[1], 128);
	strncat(input_fmt, "\n", 128 - 1 );

# ifdef UNICODE
	setlocale(LC_ALL, "");
# endif

	ft_putendl("### First pass ###");
	bench_printf(&printf,    "system printf", PRINTF_ARG);
	bench_printf(&ft_printf, "libft  printf", PRINTF_ARG);

	ft_putendl("\n### Second pass ###");
	bench_printf(&printf,    "system printf", PRINTF_ARG);
	bench_printf(&ft_printf, "libft  printf", PRINTF_ARG);
}
