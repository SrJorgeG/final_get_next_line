/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 03:54:04 by jorge             #+#    #+#             */
/*   Updated: 2024/12/01 19:58:21 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// ESTA FUNCION DEVUELVE EL RESTO DEL BUFFER LEIDO

static int	seg_rest(char **buff)
{
	char    *rst;
	int     size_rest;
	char    *temp;

	temp = ft_strchr(*buff, '\n');
	if (!temp)
		return (free(*buff), *buff = NULL, 0);
	size_rest = ft_strlen(++temp);
	rst = ft_calloc(size_rest + 1, sizeof(char));
	if (!rst)
		return (free(*buff), *buff = NULL, 1);
	ft_memcpy(rst, temp, size_rest);
	free(*buff);
	*buff = rst;
	return (0);
}

// ESTA FUNCION DEVUELVE LA LINEA QUE QUEREMOS DEVOLVER DEL BUFFER LEIDO 

static char    *seg_line(char *buff)
{
	char    *line;
	int     size_line;
	char    *temp;

	temp = ft_strchr(buff, '\n');
	if (!temp)
		return (ft_strjoin(NULL, buff));
	size_line = ft_strlen(buff) - ft_strlen(++temp);
	line = ft_calloc(size_line + 1, sizeof(char)); 
	if (!line)
		return (NULL);
	ft_memcpy(line, buff, size_line);
	return (line);
}

// ESTA FUNCION NOS DEVUELVE UN BUFFER ENTERO LEIDO DE UN FD

static ssize_t	read_buff(int fd, char **stat)
{
	char		*buff;
	ssize_t		count;

	count = 1;
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return (-1);
	while (count > 0 && !ft_strchr(*stat, '\n'))
	{
		count = read(fd, buff, BUFFER_SIZE);
		if (count < 0)
			return (free(buff), -1);
		buff[count] = '\0';
		*stat = ft_strjoin(*stat, buff);
		if (!*stat)
			return (free(buff), -1);
	}
	return (free(buff), count);
}

char    *get_next_line(int fd)
{
	static char	*rest = NULL;
	char		*line;
	int			count;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(rest), rest = NULL, NULL);
	count = read_buff(fd, &rest);
	if (count == -1 || !rest[0])
		return (free(rest), rest = NULL, NULL);
	line = seg_line(rest);
	if (!line)
		return (free(rest), rest = NULL, NULL);
	if (seg_rest(&rest) == 1)
		return (free(line), NULL);
	return (line);
}
