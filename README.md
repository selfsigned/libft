# Libft/GNL
My libft and GNL projects as a single lib

# GNL
| NAME          | get\_next\_line - read from a fd line per line                                                                                                                                              |
|---------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| SYNOPSIS      | int get\_next\_line(const int fd, char **line)                                                                                                                                              |
| DESCRIPTION   | the __get\_next\_line()__ function stores the content of a line (array of char ending with a newline or EOF) __without the trailing newline__ read from __fd__ into the address of __line__ |
| RETURN VALUES |  1 if a line has been read, 0 if the reading has been completed, -1 if an error happened                                                                                                    |

# Libft
## Bonus functions

Functions from the __libc__:
- ft_islower
- ft_isupper
- ft_strndup

Homebrewn functions:

| NAME          | ft\_strrlen -- find length until character                                                                                                        |
|---------------|---------------------------------------------------------------------------------------------------------------------------------------------------|
| SYNOPSIS      |  size\_t ft_strrlen(const char **s, char c);                                                                                                       |
| DESCRIPTION   | The __ft_strrlen()__ function computes the offset between the start of the string __s__ and the character __c__.                                  |
| RETURN VALUES | The number of characters that precede the given character, or __ft_strlen()__ if the character isn't found in the string.                         |

| NAME          | ft\_cntword - count the number of words                                                                                                                                                                                                                     |
|---------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| SYNOPSIS      | int ft\_cntword(char const *s, char c);                                                                                                                                                                                                                        |
| DESCRIPTION   | The __ft\_cntword()__ function computes the number of 'words' delimited by the character __c__ in the NULL terminated string __s__. A 'word' is a section of a string delimited by a given character, excluding the first and the last character of the string.|
| RETURN VALUES | The number of words in the string pointed by __s__. Otherwise 0 if __s__ is empty or 1 if c isn't found in __s__ (or is '\0')                                                                                        |

| NAME         | ft\_cntdigit - count the number of digits                                     |
|--------------|-------------------------------------------------------------------------------|
| SYNOPSIS     | int ft\_cntdigit(int n);                                                      |
| DESCRIPTION  | The __ft\_cntdigit()__ function computes the number of digits in the number n.|
| RETURN VALUE | The number of digits starting from 1                                          |

| NAME         | ft\_strlowcase - converts to lowercase                                                           |
|--------------|--------------------------------------------------------------------------------------------------|
| SYNOPSIS     | char ft\_strlowcase(char *s);                                                                    |
| DESCRIPTION  | The __ft\_strlowcase()__ function converts uppercase characters in the string __s__ to lowercase.|
| RETURN VALUE | The string converted to uppercase.                                                               |

| NAME         | ft\_strupcase - converts to uppercase                                                           |
|--------------|-------------------------------------------------------------------------------------------------|
| SYNOPSIS     | char ft\_strupcase(char *s);                                                                    |
| DESCRIPTION  | The __ft\_strupcase()__ function converts lowercase characters in the string __s__ to uppercase.|
| RETURN VALUE | The string converted to uppercase.                                                              |

## Part 1 Functions (libc functions)
- ft_memset
- ft_bzero
- ft_memcpy
- ft_memccpy
- ft_memmove
- ft_memchr
- ft_memcmp
- ft_strlen
- ft_strdup
- ft_strcpy
- ft_strncpy
- ft_strcat
- ft_strncat
- ft_strlcat
- ft_strchr
- ft_strrchr
- ft_strstr
- ft_strnstr
- ft_strcmp
- ft_strncmp
- ft_atoi
- ft_isalpha
- ft_isdigit
- ft_isalnum
- ft_isascii
- ft_isprint
- ft_toupper
- ft_tolower
## Part 2 Functions
- ft_itoa
- ft_memalloc
- ft_memdel
- ft_putchar
- ft_putchar_fd
- ft_putendl
- ft_putendl_fd
- ft_putnbr
- ft_putnbr_fd
- ft_putstr
- ft_putstr_fd
- ft_strclr
- ft_strdel
- ft_strequ
- ft_striter
- ft_striteri
- ft_strjoin
- ft_strmap
- ft_strmapi
- ft_strnequ
- ft_strnew
- ft_strsplit
- ft_strsub
- ft_strtrim
