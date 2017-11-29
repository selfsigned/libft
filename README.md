# My (rad!) Libft
A certain school's version of the libc... done stupidly!*

## Additional functions
*Moar functions, yay!*

Functions from the __libc__:
- ft_islower
- ft_isupper
- ft_strndup

Functions I created:

| NAME          | ft_strrlen -- find length until character                                                                                                         |
|---------------|---------------------------------------------------------------------------------------------------------------------------------------------------|
| SYNOPSIS      |  size_t ft_strrlen(const char **s, char c);                                                                                                       |
| DESCRIPTION   | The __ft_strrlen()__ function computes the offset between the start of the string __s__ and the character __c__.                                  |
| RETURN VALUES | The number of characters that precede the given character, or __ft_strlen()__ if the character isn't found in the string.                         |

| NAME          | ft_cntword - count the number of words                                                                                                                                                                                                                     |
|---------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| SYNOPSIS      | int ft_cntword(char const *s, char c);                                                                                                                                                                                                                        |
| DESCRIPTION   | The __ft_cntword()__ function computes the number of 'words' delimited by the character __c__ in the NULL terminated string __s__. A 'word' is a section of a string delimited by a given character, excluding the first and the last character of the string.|
| RETURN VALUES | The number of words in the string pointed by __s__. Otherwise 0 if __s__ is empty or 1 if c isn't found in __s__ (or is '\0')                                                                                        |

| NAME         | ft_cntdigit - count the number of digits                                      |
|--------------|-------------------------------------------------------------------------------|
| SYNOPSIS     | int ft_cntdigit(int n);                                                       |
| DESCRIPTION  | The __ft_cntdigit()__ function computes the number of digits in the number n. |
| RETURN VALUE | The number of digits starting from 1                                          |

| NAME         | ft_strlowcase - converts to lowercase                                                            |
|--------------|--------------------------------------------------------------------------------------------------|
| SYNOPSIS     | char ft_strlowcase(char *s);                                                                     |
| DESCRIPTION  | The __ft_strlowcase()__ function converts uppercase characters in the string __s__ to lowercase. |
| RETURN VALUE | The string converted to uppercase.                                                               |

| NAME         | ft_strupcase - converts to uppercase                                                            |
|--------------|-------------------------------------------------------------------------------------------------|
| SYNOPSIS     | char ft_strupcase(char *s);                                                                     |
| DESCRIPTION  | The __ft_strupcase()__ function converts lowercase characters in the string __s__ to uppercase. |
| RETURN VALUE | The string converted to uppercase.                                                              |

## Part 1 Functions
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
