int	ft_isascii(int chr)
{
    if (0 <= chr && chr <= 127)
	return(1);
    return (0);
}
