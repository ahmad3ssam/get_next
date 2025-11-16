
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int		ft_strlen(char *s);
char	*ft_strdup(char *str, int len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_loop(char *str1, char *str2);
int		has_nl(char *p);
char	*get_line(char **temp);
char	*get_next_line(int fd);
char    *free_buf(char **p);

#endif