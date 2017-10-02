int	ft_isalpha(int chr)
{
   if (('a' <= chr && 'z' >= chr) || ('A' <= chr && 'Z' >= chr)) 
       return (1);
   return (0);
}
