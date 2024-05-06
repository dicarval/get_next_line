/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:54:23 by dicarval          #+#    #+#             */
/*   Updated: 2024/05/06 16:05:41 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*line;
	char			*returnline;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, &returnline, 0) < 0)
		return (NULL);


	if (fd < 0 || bufsize <= 0)
		return (NULL);

	line = (char *)malloc(sizeof(char) * bufsize + 1);
	if (line == NULL)
		return (NULL);

	line[bufsize] = '\0';

	read(fd, line, bufsize);
}
