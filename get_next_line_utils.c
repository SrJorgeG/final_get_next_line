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

	i = 0;
	len = ft_strlen(s);
	while (s && i < len)
		if (s[i++] == c)
			return (&s[i - 1]);
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
	size_t	s1_len;
	size_t	s2_len;
	
	if (!s1)
	{
//		aqui tienes el segundo leak
		s1 = malloc(sizeof(char) * 42);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2); //Should never be empty unless read() call returned (0)

	sd = ft_calloc(sizeof(char), (s1_len + s2_len + 1));
	if (!sd)
		return (NULL);
	ft_memcpy(sd, s1, s1_len);
	ft_memcpy(sd + s1_len, s2, s2_len);
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