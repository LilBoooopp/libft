/**
 * @brief Tests whether c is a whitespace character.
 * @param c Character to test (as unsigned char or EOF).
 * @return Non-zero if c is one of: ' ', '\\t', '\\n', '\\v', '\\f', '\\r'.
 *         Zero otherwise.
 */
int	ft_isspace(int c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

/**
 * @brief Tests whether c is a blank character (space or horizontal tab only).
 * @param c Character to test.
 * @return Non-zero if c is ' ' or '\\t', zero otherwise.
 */
int	ft_isblank(int c)
{
	return (c == ' ' || c == '\t');
}
