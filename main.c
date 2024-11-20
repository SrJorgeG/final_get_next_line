/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 03:54:17 by jorge             #+#    #+#             */
/*   Updated: 2024/11/20 18:42:03 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

int main (void)
{
	int fd = open("file.txt", O_RDONLY);
	char	*line;

	/*while ((line = get_next_line(fd)))
	{
		printf("%s\n", line);
		free(line);
	}*/
	line = malloc(ft_strlen("Salto de linea:(\n") + 1 * sizeof(char));
	ft_memcpy(line, "Salto de linea:(\n", ft_strlen("Salto de linea:(\n") + 1);

	line = read_buff(fd, line);
	printf(line);
	// line = get_next_line(fd);
	// printf("\n%s\n",line);
	// free(line);
	// line = get_next_line(fd);
	// printf("\n%s\n",line);
	// free(line);
    // line = get_next_line(fd);
	// printf("\n%s\n",line);
    // line = get_next_line(fd);
	// printf("\n%s\n",line);
	// line = get_next_line(fd);
	// printf("\n%s\n",line);
	//free (line);
}
