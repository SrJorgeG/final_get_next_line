/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-d <jgomez-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 03:54:17 by jorge             #+#    #+#             */
/*   Updated: 2024/11/26 01:24:48 by jgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "get_next_line.h"

int main (void)
{
	int fd = open("file.txt", O_RDONLY);
	char	*line;

	//while ((line = get_next_line(fd)) != NULL)
	//{
	//	printf("%s\n", line);
	//	free(line);
	//}		
	//free(line);
	//close(fd);
    line = get_next_line(fd);
	printf("\n%s\n",line);
    line = get_next_line(fd);
	printf("\n%s\n",line);
	line = get_next_line(fd);
	printf("\n%s\n",line);
	line = get_next_line(fd);
	printf("\n%s\n",line);
	line = get_next_line(fd);
	printf("\n%s\n",line);
	line = get_next_line(fd);
	printf("\n%s\n",line);
	line = get_next_line(fd);
	printf("\n%s\n",line);
	line = get_next_line(fd);
	printf("\n%s\n",line);
	line = get_next_line(fd);
	printf("\n%s\n",line);
	
	free (line);
}
