int	ft_isspace(int c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

int	ft_isblank(int c)
{
	return (c == ' ' || c == '\t');
}
