#include "pipex.h"

char	*ft_strdup(char *src)
{
	char	*str;
	size_t	len;
	char	*p;

	len = ft_strlen(src);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	p = str;
	while (*src)
		*(p++) = *(src++);
	*p = '\0';
	return (str);
}
