#include "pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*str;

	i = 0;
	if (s == NULL)
		return (0);
	slen = ft_strlen(s);
	if (len > slen)
		len = slen;
	if (start >= (unsigned int)slen)
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len && s[i])
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
