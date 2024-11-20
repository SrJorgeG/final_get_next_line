/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 03:53:57 by jorge             #+#    #+#             */
/*   Updated: 2024/11/20 07:27:15 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;
	
	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;
	size_t	len;

	i = -1;
	len = ft_strlen(s);
	if (!s)
		return (NULL);
	while ((++i) < len)
		if (s[i] == c)
			return (&s[i]);
	return (NULL);
}

void	*ft_memcpy(char *dst, char *src, size_t n)
{
	if (!src)
		return (NULL);
	while (n--)
	{
		*dst = *src;
		dst++;
		src++;
	}
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*sd;

	if (!s1 || !s2)
		return (NULL);
	sd = ft_calloc(sizeof(char), (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!sd)
		return (NULL);
	ft_memcpy(sd, s1, ft_strlen(s1));
	ft_memcpy(sd + ft_strlen(s1), s2, ft_strlen(s2));
	free(s1);
    return (sd);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*z;
	size_t	len;
	size_t	i;
	
	i = 0;
	len = nmemb * size;
	if (nmemb && size > SIZE_MAX / nmemb)
		return (NULL);
	z = malloc(len);
	if (z)
		while (i < len)
			z[i++] = '\0';
	return (z);
}