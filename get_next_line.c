/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:54:23 by dicarval          #+#    #+#             */
/*   Updated: 2024/05/07 21:26:31 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	create_line(t_list **lnklist, int fd)
{
	int		i;
	char	*buffer;

	while (end_line(*lnklist) == 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buffer == NULL)
			return ;
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == 0)
			free (buffer);
			return ;
		lnklist[i] = '\0';
		lstadd_back(lnklist, buffer);
	}

}
char	*get_next_line(int fd)
{
	static t_list	*lnklist;
	char			*line;

	lnklist == NULL;
	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, &line, 0) < 0)
		return (NULL);
	create_line(&lnklist, fd)
}
