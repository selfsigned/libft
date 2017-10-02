int	ft_isprint(int chr)
{
    if (32 <= chr && chr < 127)
	return (1);
    return (0);
}
