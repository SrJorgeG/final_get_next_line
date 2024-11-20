/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 03:54:17 by jorge             #+#    #+#             */
/*   Updated: 2024/11/20 08:02:06 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

int main (void)
{
	int fd = open("file.txt", O_RDONLY);
	char	*line;

	line = get_next_line(fd);
	printf("\n%s\n",line);
    line = get_next_line(fd);
	printf("\n%s\n",line);
    line = get_next_line(fd);
	printf("\n%s\n",line);
	free (line);
}
