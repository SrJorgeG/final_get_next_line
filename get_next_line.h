/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-d <jgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 03:54:12 by jorge             #+#    #+#             */
/*   Updated: 2024/12/02 02:20:28 by jgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdint.h>

char		*get_next_line(int fd);
size_t		ft_strlen(char *s);
char		*ft_strchr(char *s, int c);
void		*ft_memcpy(char *dst, char *src, size_t n);
char		*ft_strjoin(char *s1, char *s2);
void		*ft_calloc(size_t nmemb, size_t size);

#endif