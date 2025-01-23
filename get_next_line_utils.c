/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:28:24 by mlamanti          #+#    #+#             */
/*   Updated: 2025/01/13 12:28:26 by mlamanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*out;
	size_t			i;

	out = s;
	i = 0;
	while (i < n)
	{
		out[i] = c;
		i++;
	}
	s = out;
	return (s);
}

char	*resize_out(char *out, int *out_size, int i)
{
	char	*out_n;
	int		x;

	x = 0;
	*out_size *= 2;
	out_n = malloc(sizeof(char) * (*out_size));
	if (!out_n)
	{
		free(out);
		return (NULL);
	}
	while (x < i)
	{
		out_n[x] = out[x];
		x++;
	}
	free(out);
	return (out_n);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	size_all;
	void	*out;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	size_all = nmemb * size;
	out = malloc(size_all);
	if (out == NULL)
		return (NULL);
	ft_memset(out, 0, size_all);
	return (out);
}

char	*return_null(char **out,char **buffer)
{
	if(buffer)
		free(*buffer);
	free(*out);
	return (NULL);
}


