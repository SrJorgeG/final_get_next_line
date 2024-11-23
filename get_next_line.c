/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 03:54:04 by jorge             #+#    #+#             */
/*   Updated: 2024/11/20 18:37:42 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// ESTA FUNCION DEVUELVE EL RESTO DEL BUFFER LEIDO

char    *seg_rest(char *buff)
{
    char    *rst;
    int     size_rest;
    char    *temp;
    
    temp = ft_strchr(buff, '\n');
    if (!temp)
        return (NULL);
    size_rest = ft_strlen(++temp);   
    rst = ft_calloc(size_rest + 1, sizeof(char)); 
    if (!rst)
        return (NULL);
    ft_memcpy(rst, temp, size_rest);
    return (rst);
}

// ESTA FUNCION DEVUELVE LA LINEA QUE QUEREMOS DEVOLVER DEL BUFFER LEIDO 

char    *seg_line(char *buff)
{
    char    *line;
    int     size_line;
    char    *temp;

    temp = ft_strchr(buff, '\n');
    if (!temp)
        return (buff);
    size_line = ft_strlen(buff) - ft_strlen(temp);
    line = ft_calloc(size_line + 1, sizeof(char)); 
    if (!line)
        return (NULL);
    ft_memcpy(line, buff, size_line);
    return (line);
}

// ESTA FUNCION NOS DEVUELVE UN BUFFER ENTERO LEIDO DE UN FD

int    read_buff(int fd, char **stat)
{
    char    buff[BUFFER_SIZE + 1];
    int     count;

    count = 1;
    while (count > 0 && !ft_strchr(*stat, '\n'))
    {
        count = read(fd, buff, BUFFER_SIZE);
        if (count <= 0 )
            return (-1);
        if (count == 0)
            return (-1);
        buff[count] = '\0';
        *stat = ft_strjoin(*stat, buff);
    }
    return (count);
}

char    *get_next_line(int fd)
{
    static char *rest;
    char        *line;
    char        *remaining;
    int         count;
    
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    count = read_buff(fd, &rest);
    if (count == -1)
        return (free(rest), NULL);
    line = seg_line(rest);
    if (!line)
        return (free(rest), NULL);
    remaining = seg_rest(rest);
    free(rest);
    rest = remaining;
    return (line);
}