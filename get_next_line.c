/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:54:23 by dicarval          #+#    #+#             */
/*   Updated: 2024/05/08 15:08:52 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*prep_next_line(t_list **lnklist)
{
	t_list	*last;
	t_list	*char_n_used;
	int		i;

	if (lnklist == NULL)
		return ;
	last = ft_lstlast(lnklist);
	while (last->buf[i] != '\n' || last->buf[i] != '\0')
		i++;
	if (last->buf[i] == '\n')
		i++;
	if (last->buf[i] == '\0')
		return ;
	char_n_used = malloc(sizeof(t_list));
	char_n_used->buf = malloc(sizeof(char) * (BUFFER_SIZE - i) + 1);
	char_n_used->next = NULL;
	if (char_n_used == NULL)
		return ;
	free_content(&lnklist);
	return (char_n_used);
}

char	*cpy_line(t_list *lnklist)
{
	int		i;
	int		j;
	char	*new_line;
	size_t	line_len;

	if (lnklist == NULL)
		return (NULL);
	j = 0;
	line_len = list_len(lnklist);
	new_line = malloc(sizeof(char) * line_len + 1);
	if (new_line || line_len == 0)
		return (NULL);
	while (lnklist->buf)
	{
		i = 0;
		while (lnklist->buf[i] != '\0' || lnklist->buf[i] != '\n')
			new_line[j++] = lnklist->buf[i++];
		if ((lnklist->buf[i] == '\n'))
			new_line[j] = lnklist->buf[i];
		if (lnklist->next)
			lnklist = lnklist->next;
	}
	new_line[++j] = '\0';
	return (new_line);
}

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
	static t_list	*lnklist = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, &line, 0) < 0)
		return (NULL);
	create_line(&lnklist, fd);
	line = cpy_line(lnklist);
	if (line == NULL)
		return (NULL);
	prep_next_line (&lnklist);
	return (line);
}
