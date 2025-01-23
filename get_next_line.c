/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:27:27 by mlamanti          #+#    #+#             */
/*   Updated: 2025/01/23 12:27:28 by mlamanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

// static char	*ft_strchr(const char *s, int c)
// {
// 	if (c == '\0')
// 		return ((char *)s + ft_strlen(s));
// 	while (*s != '\0' && *s != (char)c)
// 		s++;
// 	if (*s == (char)c)
// 		return ((char *)s);
// 	return (0);
// }

char *fill_line(fd)
{
	char		*buffer;
	ssize_t		bytes_read;
	char		*out;
	int			x;
	static char	*rest = NULL;

	x = 0;
	buffer = malloc(BUFFER_SIZE * sizeof(char));
	out =  malloc((BUFFER_SIZE + 1)* sizeof(char));
	if(!buffer || !out)
		return(NULL);
	while (1)	
	{
		if(rest)
		{
			printf("hoalaaaaa");
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(buffer);
			return (NULL);
		}
        // if (i + bytes_read >= out_size)
        // {
        //     buffer = resize_out(out, &out_size, i);
		// 	if (!out)
		// 	{
		// 		free(buffer);
		// 		free(out);
		// 		return (NULL);
		// 	}
        // }
		x = -1;
		while(x++ < bytes_read && buffer[x] != '\n')
			out[x] = buffer[x];
		while(buffer[x])
		
		if (buffer[x] == '\n')
			break ;
	}
	out[x] = '\0';
	return(out);
}
char	*get_next_line(int fd)
{
	char		*out;

	out = fill_line(fd);
	if (!out)
		return (NULL);
	return (out);
}
int main(void)
{
    int fd;
    char *line;

    fd = open("/home/mlamanti/cursus/get_next_line/test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error al abrir el archivo");
        return (1);
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Linea leída: %s", line);
        free(line);
    }

    close(fd);
    return (0);
}
