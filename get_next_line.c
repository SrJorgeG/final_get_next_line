/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 03:54:04 by jorge             #+#    #+#             */
/*   Updated: 2024/11/20 08:11:45 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// ESTA FUNCION DEVUELVE EL RESTO DEL BUFFER LEIDO

char    *seg_rest(char *buff)
{
    char    *rest;
    int     size_rest;
    char    *temp;
    
    temp = ft_strchr(buff, '\n');
    if (!temp)
        return (NULL);
    size_rest = ft_strlen(temp);
    rest = ft_calloc(size_rest, 1); 
    if (!rest)
        return (NULL);
    ft_memcpy(rest, ft_strchr(buff, '\n') + 1, size_rest);
    return (rest);
}

// ESTA FUNCION DEVUELVE LA LINEA QUE QUEREMOS DEVOLVER DEL BUFFER LEIDO 

char    *seg_line(char *buff)
{
    char    *line;
    int     size_line;
    char    *temp;

    temp = ft_strchr(buff, '\n');
    if (!temp)
        return (NULL);
    size_line = ft_strlen(buff) - ft_strlen(temp);
    line = ft_calloc(size_line, 1); 
    if (!size_line)
        return (NULL);
    ft_memcpy(line, buff, size_line);
    return (line);
}

// ESTA FUNCION NOS DEVUELVE UN BUFFER ENTERO LEIDO DE UN FD

char    *read_buff(int fd)
{
    char    *buff;
    int     count;
    char    *aux;

    buff = ft_calloc(BUFFER_SIZE, sizeof(char));
    if (!buff)
        return (NULL);
    aux = malloc(sizeof(char));
    if (!aux)
        return (NULL);
    count = 1;
    while (count > 0 && !ft_strchr(aux, '\n'))
    {
        count = read(fd, buff, BUFFER_SIZE);
        if (count < 0)
            return (NULL);
        aux = ft_strjoin(aux, buff);
    }
    free(buff);
    return (aux);
}

char    *get_next_line(int fd)
{
    static char *rest;
    char        *line;
    char        *buff;
    
    if (fd < 0  || BUFFER_SIZE <= 0)
        return (NULL);
    buff = read_buff(fd);
    line = seg_line(buff);
    if (rest)
        line = ft_strjoin(rest, line);
    rest = seg_rest(buff);
    free(buff);
    return (line);
}