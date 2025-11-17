#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char    *free_buf(char **p)
{
    free(*p);
    *p = NULL;
    return(NULL);
}

char	*get_next_line(int fd)
{
	static char		*re_data;
	char			*buffer;
	char            *temp;
	int				read_f;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free_buf(&re_data));
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	read_f = 1;
	while (read_f > 0 && !has_nl(re_data))
	{
		read_f = read(fd, buffer, BUFFER_SIZE);
		buffer[read_f] = 0;
		re_data = ft_strjoin(re_data, buffer);
		if(!re_data)
			break;
	}
	if (buffer)
		free_buf(&buffer);
	temp = get_line(&re_data);
	if(!temp)
	    free_buf(&re_data);
	return (temp);
}

