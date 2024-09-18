
#include <stddef.h>
#include "../minishell.h"

char	*ft_left_sep(char *src, const char c)
{
	size_t	i;
	char	*p;

	p = ft_strdup(src);
	i = 0;
	while (p[i] != '\0' && p[i] != c)
	{
		i++;
	}
	p[i]='\0';
	return (p);
}