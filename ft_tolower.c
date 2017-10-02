int	ft_tolower(int chr)
{
    if (chr >= 'A' && chr <= 'Z')
	return (chr + 32);
    return (chr);
}
