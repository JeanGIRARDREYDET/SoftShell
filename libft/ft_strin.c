
#include <stddef.h>

int	ft_strin(const char *s, const char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
	}
	if (s[i] == c)
		return (1);
	return (0);
}
