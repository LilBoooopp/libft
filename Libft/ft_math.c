#include "../libft.h"

int	ft_abs(int n)
{
	return (n < 0 ? -n : n);
}

int	ft_max(int a, int b)
{
	return (a > b ? a : b);
}

int	ft_min(int a, int b)
{
	return (a < b ? a : b);
}

int	ft_clamp(int val, int lo, int hi)
{
	return (ft_max(lo, ft_min(val, hi)));
}
