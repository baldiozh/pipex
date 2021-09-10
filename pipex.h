#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

void	ft_making_child_process(char **argv, char **envp, int *pipefd);
char	*ft_finding_path(char *arguments, char **envp);
int		ft_scroll_envp(char **envp, int i);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(char *src);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);

#endif