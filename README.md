# My (rad!) Libft
42's version of the libc... done stupidly!

## Bonus
*Moar functions, yay!*

Functions from the __libc__:
- ft_islower()
- ft_isupper()
- ft_strndup()

Functions I created:

| NAME          | ft_strrlen -- find length until character                                                                                                    |
|---------------|---------------------------------------------------------------------------------------------------------------------------------------------------|
| SYNOPSIS      |  size_t ft_strrlen(const char **s, char c);                                                                                                        |
| DESCRIPTION   | The ft_strrlen() function computes the offset between the start of the string __s__ and the character __c__.                                    |
| RETURN VALUES | The ft_strrlen() function returns the number of characters that precede the given character, or __ft_strlen()__ if the character isn't found in the string. |

| NAME          | ft_cntword - count the number of words                                                                                                                                                                                                                     |
|---------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| SYNOPSIS      | int ft_cntword(char const *s, char c);                                                                                                                                                                                                                         |
| DESCRIPTION   | The __ft_cntword()__ function computes the number of 'words' delimited by the character __c__ in the NULL terminated string __s__. A 'word' is a section of a string delimited by a given character, excluding the first and the last character of the string. |
| RETURN VALUES | The __ft_cntword()__ function returns the number of words in the string pointed by __s__. Otherwise 0 if __s__ is empty or 1 if c isn't found in __s__ (or is '\0')                                                                                            |
