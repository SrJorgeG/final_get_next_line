/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 03:53:57 by jorge             #+#    #+#             */
/*   Updated: 2024/11/27 13:26:32 by jorge            ###   ########.fr       */
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
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return (s);
		s++;
	}	
	return (NULL);
}

void	*ft_memcpy(char *dst, char *src, size_t n)
{
	if (!src)
		return (dst);
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
	
	if (!s2)
		return (free(s1), NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	sd = ft_calloc((s1_len + s2_len + 1), sizeof(char));
	if (!sd)
		return (free(s1), NULL);
	ft_memcpy(sd, s1, s1_len);
	ft_memcpy(sd + s1_len, s2, s2_len);
	return (free(s1), sd);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*z;
	size_t			len;
	size_t			i;
	
	i = 0;
	if (nmemb && size > SIZE_MAX / nmemb)
		return (NULL);
	len = nmemb * size;
	z = malloc(len);
	if (z)
		while (i < len)
			z[i++] = '\0';
	return (z);
}