/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:28:16 by mlamanti          #+#    #+#             */
/*   Updated: 2025/01/13 12:28:17 by mlamanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>

void	*ft_calloc(size_t nmemb, size_t size);
char	*resize_out(char *out, int *out_size, int current_size);
char	*get_next_line(int fd);
char	*return_null(char **out, char **buffer);

#endif
