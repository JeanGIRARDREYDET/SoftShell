
#include "../minishell.h"

char	*ft_post_left_sep(char *src, const char c)
{
	char	*p;

	p = (char *)src;
	while (*p != '\0' && *p != c)
		p++;
	if (*p == c)
		p++;
	return (p);
}