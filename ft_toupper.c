int	ft_toupper(int chr)
{
    if (chr >= 'a' && chr <= 'z')
	return (chr - 32);
    return (chr);
}
