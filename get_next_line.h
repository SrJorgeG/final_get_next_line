/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 03:54:12 by jorge             #+#    #+#             */
/*   Updated: 2024/11/20 07:58:38 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10 
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdint.h>

char	*get_next_line(int fd);
//char    *read_buff(int fd);
int     read_buff(int fd, char **stat);
char	*seg_line(char *buff);
char	*seg_rest(char *buff);
size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
void	*ft_memcpy(char *dst,char *src, size_t n);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_calloc(size_t nmemb, size_t size);

#endif