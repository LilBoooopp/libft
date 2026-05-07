#include "../libft.h"

/**
 * @brief Returns the absolute value of n.
 * @param n Integer input.
 * @return Absolute value of n. Behaviour is undefined for INT_MIN.
 */
int	ft_abs(int n)
{
	return (n < 0 ? -n : n);
}

/**
 * @brief Returns the greater of two integers.
 * @param a First integer.
 * @param b Second integer.
 * @return a if a > b, otherwise b.
 */
int	ft_max(int a, int b)
{
	return (a > b ? a : b);
}

/**
 * @brief Returns the lesser of two integers.
 * @param a First integer.
 * @param b Second integer.
 * @return a if a < b, otherwise b.
 */
int	ft_min(int a, int b)
{
	return (a < b ? a : b);
}

/**
 * @brief Clamps val to the closed interval [lo, hi].
 * @param val Value to clamp.
 * @param lo  Lower bound.
 * @param hi  Upper bound.
 * @return lo if val < lo, hi if val > hi, otherwise val.
 * @note Behaviour is undefined if lo > hi.
 */
int	ft_clamp(int val, int lo, int hi)
{
	return (ft_max(lo, ft_min(val, hi)));
}
