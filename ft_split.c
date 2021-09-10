#include "pipex.h"

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			count++;
			while (*s != c && *s)
				s++;
		}
	}
	return (count);
}

static int	ft_size_word(char const *s, char c)
{
	int	size;

	size = 0;
	while (*s == c)
		s++;
	while (*s != c && *s)
	{
		size++;
		s++;
	}
	return (size);
}

static void	ft_free(char **arr, const char *s, char c)
{
	int	i;

	i = 0;
	while (i < ft_count_words(s, c))
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static char	**ft_go_word(char const *s, char c, char **arr, int i)
{
	int	j;
	int	count;

	count = ft_count_words(s, c);
	while (i < count)
	{
		j = 0;
		arr[i] = (char *)malloc(sizeof(char) * (ft_size_word(s, c) + 1));
		if (arr[i] == NULL)
		{
			ft_free(arr, s, c);
			return (NULL);
		}	
		while (*s && *s != c)
		{
			arr[i][j] = *s++;
			j++;
		}
		arr[i][j] = '\0';
		while (*s == c)
			s++;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**arr;

	i = 0;
	if (!s)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!arr)
		return (NULL);
	if (*s == 0 && c == 0)
	{
		*arr = NULL;
		return (arr);
	}
	while (*s == c)
		s++;
	arr = ft_go_word(s, c, arr, i);
	return (arr);
}
